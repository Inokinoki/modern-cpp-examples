#include <iostream>
#include <variant>
#include <any>
#include <optional>

// std::byte
#include <cstddef>

std::optional<std::string> create(bool b) {
    if (b) {
        return "Godzilla";
    } else {
        return {};
    }
}

int main()
{
    // The class template std::variant represents a type-safe union.
    std::variant<int, double> v{ 12 };
    std::cerr << std::to_string(std::get<int>(v)) << std::endl;       // == 12
    std::cerr << std::to_string(std::get<0>(v)) << std::endl;         // == 12
    v = 12.0;
    std::cerr << std::to_string(std::get<double>(v)) << std::endl;    // == 12.0
    std::cerr << std::to_string(std::get<1>(v)) << std::endl;         // == 12.0

    // The class template std::optional manages an optional contained value, i.e. a value that may or may not be present.
    auto r1 = create(false).value_or("empty"); // == "empty"
    auto r2 = create(true).value(); // == "Godzilla"
    // optional-returning factory functions are usable as conditions of while and if
    if (auto str = create(true)) {
        std::cerr << str.value() << std::endl;
    }
    // Panic
    // create(false).value();

    // A type-safe container for single values of any type.
    std::any x {5};
    x.has_value(); // == true
    std::any_cast<int>(x); // == 5
    std::any_cast<int&>(x);// = 10;
    std::any_cast<int>(x); // == 10

    // std::byte
    std::byte a {0};
    std::byte b {0xFF};
    int i = std::to_integer<int>(b); // 0xFF
    std::byte c = a & b;
    int j = std::to_integer<int>(c); // 0

    return 0;
}
