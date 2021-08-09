#include <memory>
#include <iostream>

void f(int& x)
{
    std::cerr << "x is a reference" << std::endl;
}

void f(int&& x)
{
    std::cerr << "x is a rvalue reference" << std::endl;
}

void g(int& x)
{
    x = 10;
}

void g(int&& x)
{
    std::cerr << "x is a rvalue reference" << std::endl;
}

// Since C++11 or later:
template <typename T>
void auto_ref_f(T&& t) {
    std::cerr << t << std::endl;
}

struct A {
    A() = default;
    A(const A& o) { std::cout << "copied" << std::endl; }
    A(A&& o) { std::cout << "moved" << std::endl; }
    A& operator=(A&& o) {
        std::cout << "assigned" << std::endl;
        return *this;
    }
};

template <typename T>
A wrapper(T&& arg) {
    return A{ std::forward<T>(arg) };
}

int main()
{
    int x = 0;          // `x` is an lvalue of type `int`
    int& xl = x;        // `xl` is an lvalue of type `int&`
    // int&& xr = x;    // compiler error -- `x` is an lvalue
    int&& xr2 = 0;      // `xr2` is an lvalue of type `int&&` -- binds to the rvalue temporary, `0`

    f(x);  // calls f(int&)
    f(xl); // calls f(int&)
    f(3);  // calls f(int&&)
    f(std::move(x)); // calls f(int&&), performing a move is nothing more than casting to an rvalue reference

    // rvalue is mutable through a rvalue reference
    std::cerr << "xr2: " << xr2 << std::endl;
    g(xr2);             // calls g(int&)
    std::cerr << "xr2: " << xr2 << std::endl;
    g(std::move(xr2));  // calls g(int&& x), performing a move is nothing more than casting to an rvalue reference
    std::cerr << "xr2: " << xr2 << std::endl;

    // Also known (unofficially) as universal references.
    // A forwarding reference is created with the syntax T&& where T is a template type parameter, or using auto&&
    auto&& al = x; // `al` is an lvalue of type `int&` -- binds to the lvalue, `x`
    auto&& ar = 20; // `ar` is an lvalue of type `int&&` -- binds to the rvalue temporary, `0`
    auto_ref_f(al);
    auto_ref_f(ar);

    // Forward
    wrapper(A{});           // moved
    A a;
    wrapper(a);             // copied
    wrapper(std::move(a));  // moved

    return 0;
}
