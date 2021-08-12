#include <iostream>

struct A {
    int x;
    int y;
    int z = 123;
};

// Conditionally select at compile-time whether a constructor is made explicit or not. explicit(true) is the same as specifying explicit.
struct Foo {
    // Specify non-integral types (strings, floats, etc.) require explicit construction.
    template <typename T>
    explicit(!std::is_integral_v<T>) Foo(T t)
    { 
        if (std::is_integral<T>::value) std::cerr << "Init int " << t << std::endl;
        else std::cerr << "Init " << t << std::endl;
    }
};

struct Bar {
  Bar() = default;
  constexpr Bar(int) {}
};

template <Bar f>
auto get_foo() {
  return f;
}

int main()
{
    // C-style designated initializer syntax
    A a {.x = 1, .z = 2};   // a.x == 1, a.y == 0, a.z == 2

    std::cerr << a.x << " " << a.y << " " << a.z << std::endl;

    Foo intfoo = 123; // OK
    // foo b = "123"; // ERROR: explicit constructor is not a candidate (explicit specifier evaluates to true)
    Foo c {"123"}; // OK, because it is not explicit

    // Classes can now be used in non-type template parameters.
    // get_foo(); // uses implicit constructor
    get_foo<Bar{123}>();

    return 0;
}