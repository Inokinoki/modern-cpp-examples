#include <iostream>

constexpr int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main()
{
    constexpr int i = 100 + 300;
    factorial(5);  // == 120
    return 0;
}
