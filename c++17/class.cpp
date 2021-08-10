#include <iostream>

template <typename T = float>
struct MyContainer {
    T val;
    MyContainer() : val{} {}
    MyContainer(T val) : val{val} {}
    // ...
};

int main()
{
    // Automatic template argument deduction
    MyContainer c1 {1}; // OK MyContainer<int>
    MyContainer c2;     // OK MyContainer<float>

    return 0;
}
