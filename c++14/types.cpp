#include <iostream>
#include <chrono>

// Deduce return type as `int`.
auto fi(int i) {
    return i;
}

template <typename T>
auto& f(T& t) {
    return t;
}

// Return type is `int`.
auto f1(const int& i) {
    return i;
}
// Return type is `const int&`.
decltype(auto) g1(const int& i) {
    return i;
}

int main()
{
    int i1 = 0b1111'1111;   // == 255
    std::cerr << std::hex << "0x" << i1 << std::dec << std::endl;

    // Returns a reference to a deduced type.
    static_assert(std::is_same<int, decltype(fi(1))>::value);

    auto g = [](auto& x) -> auto& { return f(x); };
    int y = 123;
    int& z = g(y); // reference to `y`

    // The decltype(auto) type-specifier also deduces a type like auto does.
    // However, it deduces return types while keeping their references and cv-qualifiers, while auto will not.
    int x = 123;
    static_assert(std::is_same<const int&, decltype(f1(x))>::value == 0);
    static_assert(std::is_same<int, decltype(f1(x))>::value == 1);
    static_assert(std::is_same<const int&, decltype(g1(x))>::value == 1);

    // User-defined chronos
    using namespace std::chrono_literals;
    auto day = 24h;
    day.count(); // == 24
    std::chrono::duration_cast<std::chrono::minutes>(day).count(); // == 1440

    return 0;
}

