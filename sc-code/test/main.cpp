#include <iostream>
#include <vector>
#include <fstream>
#include <cstdint>
#include <sstream>
#include <iomanip>

void initbuffer(std::vector<std::vector<uint8_t>>* &buffers)
{
    buffers = new std::vector<std::vector<uint8_t>>;
    std::ifstream file("data_hex.txt");
    if (!file)
    {
        std::cerr << "Error opening file." << std::endl;
    }
    std::vector<uint8_t> buffer;
    std::string line;
    int lineCount = 0;
    while (std::getline(file, line))
    {
        // Convert hex string to uint8_t
        std::istringstream iss(line);
        uint8_t data = 0;
        iss >> std::hex >> data;

        buffer.push_back(data);
        lineCount++;

        if (lineCount == 10)
        {
            buffers->push_back(buffer);
            buffer.clear();
            lineCount = 0;
        }
    }

    // If the last buffer is not complete (less than 10 lines), add it to buffers.
    if (!buffer.empty())
    {
        buffers->push_back(buffer);
    }
    // Close the file after reading
    file.close();
}

int main()
{
    std::vector<std::vector<uint8_t>> *buffers;
    initbuffer(buffers);

    // Print the contents of each buffer as an example
    for (const auto &buf : *buffers)
    {
        for (const auto &data : buf)
        {
            // Print as hex
            std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(data) << " ";
        }
        std::cout << std::endl;
    }

    // Don't forget to delete the dynamically allocated memory
    delete buffers;

    return 0;
}
