#include <iostream>

constexpr bool is_compile_time() {
    return std::is_constant_evaluated();
}

int main()
{
    constexpr bool a = is_compile_time(); // true
    std::cerr << "a is computed " << (a ? "at compile time" : "at runtime") << std::endl;
    bool b = is_compile_time(); // false
    std::cerr << "b is computed " << (b ? "at compile time" : "at runtime") << std::endl;

    return 0;
}
