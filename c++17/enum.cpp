#include <iostream>

enum class Handle : uint32_t /* Typed-enum in C++11 */ { Invalid = 0 };

int main()
{
    // Enums can now be initialized using braced syntax like a class
    Handle h { 0 }, a { 114514 };
    return 0;
}
