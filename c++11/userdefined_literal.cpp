#include <cmath>
#include <iostream>

// User-defined literals allow you to extend the language and add your own syntax.
// To create a literal, define a T operator "" X(...) { ... } function that returns a type T, with a name X.
// Note that the name of this function defines the name of the literal.
// Any literal names not starting with an underscore are reserved and won't be invoked.

// `unsigned long long` parameter required for integer literal.
long long operator "" _celsius(unsigned long long tempCelsius) {
  return std::llround(tempCelsius * 1.8 + 32);
}

int main()
{
    std::cerr << 24_celsius << std::endl; // == 75
    return 0;
}
