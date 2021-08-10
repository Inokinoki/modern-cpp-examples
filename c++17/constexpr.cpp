#include <iostream>

constexpr int addOne(int n) {
    return [n] { return n + 1; }();
}

template <typename T>
constexpr bool isIntegral() {
    if constexpr (std::is_integral<T>::value) {
        return true;
    } else {
        return false;
    }
}

int main()
{
    // Compile-time lambdas using constexpr.
    auto identity = [](int n) constexpr { return n; };
    static_assert(identity(123) == 123);

    constexpr auto add = [](int x, int y) {
        auto L = [=] { return x; };
        auto R = [=] { return y; };
        return [=] { return L() + R(); };
    };
    static_assert(add(1, 2)() == 3);

    static_assert(addOne(1) == 2);

    // Compile-time condition
    static_assert(isIntegral<int>() == true);
    static_assert(isIntegral<char>() == true);
    static_assert(isIntegral<double>() == false);
    struct S {};
    static_assert(isIntegral<S>() == false);

    return 0;
}
