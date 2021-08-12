#include <iostream>
#include <memory>

int main()
{
    auto p = std::make_shared<int[]>(5); // pointer to `int[5]`
    // OR
    auto p1 = std::make_shared<int[5]>(); // pointer to `int[5]`
    return 0;
}
