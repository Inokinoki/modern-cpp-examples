#include <iostream>
#include <initializer_list>

int sum(const std::initializer_list<int>& list) {
  int total = 0;
  for (auto& e : list) {
    total += e;
  }

  return total;
}

struct A {
  A(int) { std::cerr << "1 param constructor is called" << std::endl; }
  A(int, int) { std::cerr << "2 params constructor is called" << std::endl; }
  A(int, int, int) { std::cerr << "3 params constructor is called" << std::endl; }
  A(std::initializer_list<int>) { std::cerr << "initializer_list constructor is called" << std::endl; }
};

int main()
{
    // A lightweight array-like container of elements created using a "braced list" syntax.
    auto list = {1, 2, 3};
    std::cerr << sum(list) << std::endl;        // == 6
    std::cerr << sum({1, 2, 3}) << std::endl;   // == 6
    std::cerr << sum({}) << std::endl;          // == 0

    A a {0, 0};     // calls A::A(std::initializer_list<int>)
    A b(0, 0);      // calls A::A(int, int)
    A c = {0, 0};   // calls A::A(std::initializer_list<int>)
    A d {0, 0, 0};  // calls A::A(std::initializer_list<int>)

    return 0;
}
