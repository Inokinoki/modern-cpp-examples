#include <span>
#include <vector>
#include <iostream>

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

    return 0;
}
