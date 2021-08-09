#include <iostream>
#include <string>

const char* message = R"(
Hello,
    world!
)";

int main()
{
    char32_t utf8_str_c32[] = U"\u4567";
    char16_t utf8_str_c16[] = u"\u5678";
    std::cout << utf8_str_c32 << std::endl;
    std::cout << utf8_str_c16 << std::endl;

    return 0;
}