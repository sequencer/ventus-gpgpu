#include <iostream>
#include <array>
#include <sstream>

template <typename T, std::size_t N, std::size_t... Is>
void printArrayHelper(std::ostringstream& oss, const std::array<T, N>& arr, std::index_sequence<Is...>)
{
    ((oss << (Is != 0 ? ", " : "") << arr[Is]), ...);
}

template <typename T, std::size_t N>
std::string printArray(const std::array<T, N>& arr)
{
    std::ostringstream oss;
    oss << '(';
    printArrayHelper(oss, arr, std::make_index_sequence<N>{});
    oss << ')';
    return oss.str();
}

int main()
{
    std::array<int, 5> myArray = {1, 2, 3, 4, 5};
    std::cout << printArray(myArray);  // 输出：(1, 2, 3, 4, 5)

    return 0;
}
