#include "init_extmem.hpp"

// // 定义缓冲区数量和基地址数组
// const int num_buffer = 5;
// int buffer_base[num_buffer] = {0, 8, 16, 24, 32};

// // 定义缓冲区大小数组
// int buffer_size[num_buffer] = {8, 8, 8, 8, 8};

// // 定义存储缓冲区数据的向量
// std::vector<std::vector<uint8_t>> buffer_data(num_buffer);

// 读取外部文本文件并将数据存入缓冲区
void BASE::readTextFile(const std::string &filename, std::vector<std::vector<uint8_t>> &buffers, uint64_t *buffer_size)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    std::string line;
    int bufferIndex = 0;
    std::vector<uint8_t> buffer;
    while (std::getline(file, line))
    {
        for (int i = line.length(); i > 0; i -= 2)
        {
            std::string hexChars = line.substr(i - 2, 2);
            uint8_t byte = std::stoi(hexChars, nullptr, 16);
            buffer.push_back(byte);
        }

        if (buffer.size() == buffer_size[bufferIndex])
        {
            // cout << "SM" << sm_id << " INIT_EXTMEM: prepared buffer[" << bufferIndex << "] of size " << buffer.size() << "\n";
            buffers[bufferIndex] = buffer;
            // cout << "SM" << sm_id << " INIT_EXTMEM: buffers[" << bufferIndex << "] of size " << buffers[bufferIndex].size() << " is in buffers\n";
            buffer.clear();
            bufferIndex++;
        }
    }

    file.close();
}

// 通过虚拟地址获取对应缓冲区的数据并转换为整数
uint32_t BASE::getBufferData(const std::vector<std::vector<uint8_t>> &buffers, unsigned int virtualAddress, int num_buffer, uint64_t *buffer_base, uint64_t *buffer_size, bool &addrOutofRangeException, I_TYPE ins)
{
    addrOutofRangeException = 0;
    int bufferIndex = -1;
    for (int i = 0; i < num_buffer; i++)
    {
        // cout << std::hex << "getBufferData: ranging from " << buffer_base[i] << " to " << (buffer_base[i] + buffer_size[i]) << std::dec << "\n";
        if (virtualAddress >= buffer_base[i] && virtualAddress < (buffer_base[i] + buffer_size[i]))
        {
            bufferIndex = i;
            break;
        }
    }

    if (bufferIndex == -1)
    {
        std::cerr << "getBufferData Error: No buffer found for the given virtual address 0x" << std::hex << virtualAddress << " for ins" << ins << " at " << sc_time_stamp() << "," << sc_delta_count_at_current_time() << "\n";
        addrOutofRangeException = 1;
        return 0;
    }

    int offset = virtualAddress - buffer_base[bufferIndex];
    // cout << "getBufferData: offset=" << std::hex << offset << "\n";
    int startIndex = offset;

    uint32_t data = 0;
    for (int i = 0; i < 4; i++)
    {
        // cout << "getBufferData: fetching buffers[" << bufferIndex << "][" << (startIndex + i) << "], buffer size=" << buffers[bufferIndex].size() << "\n";
        uint8_t byte = buffers[bufferIndex][startIndex + i];
        data |= static_cast<uint32_t>(byte) << (i * 8);
    }

    return data;
}

uint32_t BASE::readInsBuffer(unsigned int virtualAddr, bool &addrOutofRangeException)
{
    addrOutofRangeException = 0;
    int startIndex = virtualAddr - mtd.startaddr;
    if (startIndex < 0 || startIndex > mtd.buffer_size[mtd.insBufferIndex])
    {
        cout << "readInsBuffer Error: virtualAddr(pc)=0x" << std::hex << virtualAddr << std::dec << " at " << sc_time_stamp() << "," << sc_delta_count_at_current_time() << "\n";
        addrOutofRangeException = 1;
        return 0;
    }
    uint32_t data = 0;
    for (int i = 0; i < 4; i++)
    {
        uint8_t byte = (*buffer_data)[mtd.insBufferIndex][startIndex + i];
        data |= static_cast<uint32_t>(byte) << (i * 8);
    }
    return data;
}

void BASE::writeBufferData(int writevalue, std::vector<std::vector<uint8_t>> &buffers, unsigned int virtualAddress, int num_buffer, uint64_t *buffer_base, uint64_t *buffer_size, I_TYPE ins)
{
    int bufferIndex = -1;
    for (int i = 0; i < num_buffer; i++)
    {
        if (virtualAddress >= buffer_base[i] && virtualAddress < (buffer_base[i] + buffer_size[i]))
        {
            bufferIndex = i;
            break;
        }
    }

    if (bufferIndex == -1)
    {
        std::cerr << "writeBufferData Error: No buffer found for the given virtual address 0x" << std::hex << virtualAddress << " for ins" << ins << " at " << sc_time_stamp() << "," << sc_delta_count_at_current_time() << "\n";
        return;
    }

    int offset = virtualAddress - buffer_base[bufferIndex];
    int startIndex = offset;

    for (int i = 0; i < 4; i++)
    {
        uint8_t byte = static_cast<uint8_t>(writevalue >> (i * 8));
        buffers[bufferIndex][startIndex + i] = byte;
    }

    std::cout << "SM" << sm_id << std::hex << " write extmem[" << virtualAddress << "]=" << writevalue << std::dec << ",ins=" << ins << " at " << sc_time_stamp() << "," << sc_delta_count_at_current_time() << "\n";
}

void init_local_and_private_mem(std::vector<std::vector<uint8_t>> &buffers, meta_data mtd)
{
    uint64_t ldsSize = mtd.ldsSize;
    uint64_t pdsSize = mtd.pdsSize;
    buffers[mtd.num_buffer - 2].resize(ldsSize);
    buffers[mtd.num_buffer - 1].resize(pdsSize);
}

void BASE::INIT_EXTMEM()
{
    int num_buffer = mtd.num_buffer;
    uint64_t *buffer_size = mtd.buffer_size;
    buffer_data = new std::vector<std::vector<uint8_t>>(num_buffer); // 此时num_buffer已经是.meta文件里的num_buffer+2，包含了local和private这两个buffer
    readTextFile(datafile, *buffer_data, buffer_size);
    init_local_and_private_mem(*buffer_data, mtd);
}
