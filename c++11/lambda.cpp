#include <iostream>

int main()
{
    /*
    Capture list:
    [] - captures nothing.
    [=] - capture local objects (local variables, parameters) in scope by value.
    [&] - capture local objects (local variables, parameters) in scope by reference.
    [this] - capture this by reference.
    [a, &b] - capture objects a by value, b by reference.
     */
    // Arg list

    int x = 1;

    auto getX = [=] { return x; };
    getX(); // == 1

    auto addX = [=](int y) { return x + y; };
    addX(1); // == 2

    auto getXRef = [&]() -> int& { return x; };
    getXRef(); // int& to `x`

    return 0;
}
