#include <array>
#include <algorithm>

#include <iostream>

int main()
{
    // Fixed size, not resizable
    std::array<int, 3> a = {2, 1, 3};
    std::sort(a.begin(), a.end()); // a == { 1, 2, 3 }

    // Raw-array-compatible iterator
    int raw_array[10] = {1, 3, 5, 2, 4, 6, 8, 9, 10, 7};
    auto iter = std::begin(raw_array);
    for (; iter != std::end(raw_array); iter++)
    {
        std::cerr << *iter << std::endl;
    }

    return 0;
}