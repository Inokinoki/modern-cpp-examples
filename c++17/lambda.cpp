#include <iostream>

struct MyObj {
    int value {123};
    auto getValueCopy() {
        return [*this] { return value; };
    }
    auto getValueRef() {
        return [this] { return value; };
    }
};

int main()
{
    // Capturing this in a lambda's environment was previously reference-only. `*this` will make a copy
    MyObj mo;
    auto valueCopy = mo.getValueCopy();
    auto valueRef = mo.getValueRef();
    mo.value = 321;
    std::cerr << valueCopy() << std::endl;  // 123
    std::cerr << valueRef() << std::endl;   // 321

    return 0;
}