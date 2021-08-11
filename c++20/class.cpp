#include <iostream>

struct A {
    int x;
    int y;
    int z = 123;
};

int main()
{
    // C-style designated initializer syntax
    A a {.x = 1, .z = 2};   // a.x == 1, a.y == 0, a.z == 2

    std::cerr << a.x << " " << a.y << " " << a.z << std::endl;

    return 0;
}