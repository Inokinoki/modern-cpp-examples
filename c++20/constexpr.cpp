#include <iostream>

constexpr bool is_compile_time() {
    return std::is_constant_evaluated();
}

struct X1 {
    virtual int f() const = 0;
};

struct X2: public X1 {
    constexpr virtual int f() const { return 2; }
};

struct X3: public X2 {
    virtual int f() const { return 3; }
};

struct X4: public X3 {
    constexpr virtual int f() const { return 4; }
};

int main()
{
    constexpr bool a = is_compile_time(); // true
    std::cerr << "a is computed " << (a ? "at compile time" : "at runtime") << std::endl;
    bool b = is_compile_time(); // false
    std::cerr << "b is computed " << (b ? "at compile time" : "at runtime") << std::endl;

    // Virtual functions can now be constexpr and evaluated at compile-time.
    constexpr X4 x4;
    x4.f(); // == 4

    return 0;
}
