#include <span>
#include <vector>
#include <iostream>

#include <numbers>
#include <numeric>

#include <set>
#include <map>

#include <bit>

int main()
{
    // A span is a view (i.e. non-owning) of a container providing bounds-checked access to a contiguous group of elements.
    std::vector<int> v = {1, 2, 3};
    std::span<int> sv = v;
    std::array<int, 3> a = {1, 2, 3};
    std::span<int> sa = a;

    std::for_each(sv.begin(), sv.end(), [](auto i) {
        std::cerr << i << " ";
    });
    std::cerr << std::endl;
    std::for_each(sa.begin(), sa.end(), [](auto &i) {
        std::cerr << i << " ";
        i = i * 2;
    });
    std::cerr << std::endl;
    std::for_each(sa.begin(), sa.end(), [](auto &i) {
        std::cerr << i << " ";
    });
    std::cerr << std::endl;

    std::cerr << std::numbers::pi << " " << std::numbers::e << std::endl;

    // Converts the given array/"array-like" object to a std::array.
    std::to_array("foo"); // returns `std::array<char, 4>`
    std::to_array<int>({1, 2, 3}); // returns `std::array<int, 3>`
    int aa[] = {1, 2, 3};
    std::to_array(aa); // returns `std::array<int, 3>`

    // Calculate the midpoint of two integers safely (without overflow).
    std::midpoint(1, 3); // == 2

    // A safer way to reinterpret an object from one type to another.
    float f = 123.0;
    int i = std::bit_cast<int>(f);

    // Associative containers such as sets and maps have a contains member function,
    // which can be used instead of the "find and check end of iterator" idiom.
    std::map<int, char> map {{1, 'a'}, {2, 'b'}};
    map.contains(2); // true
    map.contains(123); // false
    std::set<int> set {1, 2, 3};
    set.contains(2); // true

    // C++20 provides a new <bit> header which provides some bit operations including popcount.
    std::popcount(0u); // 0
    std::popcount(1u); // 1
    std::popcount(0b1111'0000u); // 4

    return 0;
}
