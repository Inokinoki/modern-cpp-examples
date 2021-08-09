#include <iostream>

constexpr int square(int x) {
    return x * x;
}

int square2(int x) {
    return x * x;
}

int main()
{
    constexpr int x = 1;
    constexpr int y = 2;
    constexpr int z = y * y;

    // Constant expressions are expressions evaluated by the compiler at compile-time.
    // Only non-complex computations can be carried out in a constant expression.
    static_assert(x == square(x), "sqaure(1) != 1");
    static_assert(z == square(y), "sqaure(2) != 4");

    return 0;
}
