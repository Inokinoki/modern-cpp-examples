#include <type_traits>
#include <iostream>

/*
Concepts are named compile-time predicates which constrain types. They take the following form:

template < template-parameter-list >
concept concept-name = constraint-expression;

where constraint-expression evaluates to a constexpr Boolean.
*/

// `T` is not limited by any constraints.
template <typename T>
concept always_satisfied = true;
// Limit `T` to integrals.
template <typename T>
concept integral = std::is_integral_v<T>;
// Limit `T` to both the `integral` constraint and signedness.
template <typename T>
concept signed_integral = integral<T> && std::is_signed_v<T>;
// Limit `T` to both the `integral` constraint and the negation of the `signed_integral` constraint.
template <typename T>
concept unsigned_integral = integral<T> && !signed_integral<T>;

// Forms for function parameters:
// `T` is a constrained type template parameter.
template <signed_integral T>
T reciprocal(T v)
{
    return -v;
}

// `T` is a constrained type template parameter.
template <typename T>
  requires signed_integral<T>
T reciprocal2(T v)
{
    return -v;
}

// `T` is a constrained type template parameter.
template <typename T>
T reciprocal3(T v) requires signed_integral<T>
{
    return -v;
}

// `v` is a constrained deduced parameter.
auto reciprocal4(signed_integral auto v)
{
    return -v;
}

// Note that the parameter list in a requires expression is optional.
// Each requirement in a requires expression are one of the following:
// - Simple requirements - asserts that the given expression is valid.
// - Type requirements - denoted by the typename keyword followed by a type name, asserts that the given type name is valid.
// - Compound requirements - an expression in braces followed by a trailing return type or type constraint.
// - Nested requirements - denoted by the requires keyword, specify additional constraints (such as those on local parameter arguments).

int main()
{
    int i = 120;
    auto negative_i = reciprocal(i);
    auto negative_i2 = reciprocal2(i);
    auto negative_i3 = reciprocal3(i);
    auto negative_i4 = reciprocal4(i);

    // unsigned int ui = 120;
    // auto negative_ui = reciprocal(ui);  // Error because ui is not unsigned
    // auto negative_ui2 = reciprocal2(ui);
    // auto negative_ui3 = reciprocal3(ui);
    // auto negative_ui4 = reciprocal4(ui);

    signed_integral auto si = 120;
    std::cerr << std::is_signed<decltype(si)>::value << std::endl;
    // unsigned_integral auto ui = 120;
    // std::cerr << std::is_signed<decltype(ui)>::value << std::endl;

    return 0;
}
