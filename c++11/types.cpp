#include <iostream>
#include <vector>

#include "common.h"

/* Error, must use decltype to have a type
template <typename X, typename Y>
auto add(X x, Y y) {
    return x + y;
}
*/

// Type traits defines a compile-time template-based interface to query or modify the properties of types.
static_assert(std::is_same<int32_t, int>::value);
static_assert(std::has_virtual_destructor<LifecycleLogger>::value);
static_assert(std::is_same<std::conditional<true, int, double>::type, int>::value);

// This uses `tailing return types
template <typename X, typename Y>
auto addWithDecltype(X x, Y y) -> decltype(x + y) {
    return x + y;
}

// Type alias
template <typename T>
using Vec = std::vector<T>;

int main()
{
    // decltype is an operator which returns the declared type of an expression passed to it.
    decltype(114514) a = 114514;    // int
    const int &b = a;
    decltype(b) c = a;              // int&

    auto r1 = addWithDecltype(1, 2);
    std::cerr << std::to_string(r1) << std::endl;
    auto r2 = addWithDecltype(1, 2.0);
    std::cerr << std::to_string(r2) << std::endl;
    auto r3 = addWithDecltype(1.0, 2);
    std::cerr << std::to_string(r3) << std::endl;
    auto r4 = addWithDecltype(1.0, 2.0);
    std::cerr << std::to_string(r4) << std::endl;

    // Type alias
    Vec<int> v(1000, 1);

    return 0;
}
