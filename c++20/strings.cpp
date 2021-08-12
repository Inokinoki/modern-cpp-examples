#include <string>

int main()
{
    // Strings (and string views) now have the starts_with and ends_with
    // member functions to check if a string starts or ends with the given string.
    std::string str = "foobar";
    str.starts_with("foo"); // true
    str.ends_with("baz"); // false

    char8_t utf8_str[] = u8"\u0123";

    return 0;
}