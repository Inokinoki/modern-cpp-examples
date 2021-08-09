#include <string>
#include <memory>
#include <iostream>

int factory(int i) { return i * 10; }

int main()
{
    // C++14 now allows the auto type-specifier in the parameter list, enabling polymorphic lambdas.
    auto identity = [](auto x) { return x; };
    static_assert(std::is_same<decltype(identity("foo")), const char*>::value);
    static_assert(std::is_same<decltype(identity(3)), int>::value);

    // Lambda capture initializers
    auto f = [x = factory(2)] { return x; }; // returns 20

    auto generator = [x = 0] () mutable {
    // this would not compile without 'mutable' as we are modifying x on each call
        return x++;
    };
    auto a = generator(); // == 0
    auto b = generator(); // == 1
    auto c = generator(); // == 2

    auto p = std::make_unique<int>(1);

    // auto task1 = [=] { *p = 5; }; // ERROR: std::unique_ptr cannot be copied
    // vs.
    auto task2 = [p = std::move(p)] { *p = 5; }; // OK: p is move-constructed into the closure object
    // the original p is empty after task2 is created
    if (!p) {
        std::cerr << "p is empty" << std::endl;
    }
    task2();
    task2();

    auto x = 1;
    auto f1 = [&r = x, x = x * 10] {
        ++r;
        return r + x;
    };
    f1(); // sets x to 2 and returns 12

    return 0;
}