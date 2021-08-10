#include <iostream>
#include <tuple>

// std::invoke
#include <functional>

struct MyObj {
    int value {123};
    auto getValueCopy() {
        return [*this] { return value; };
    }
    auto getValueRef() {
        return [this] { return value; };
    }
};

template <typename Callable>
class Proxy {
    Callable c;
public:
    Proxy(Callable c): c(c) {}
    template <class... Args>
    decltype(auto) operator()(Args&&... args) {
        // ...
        return std::invoke(c, std::forward<Args>(args)...);
    }
};

int main()
{
    // Capturing this in a lambda's environment was previously reference-only. `*this` will make a copy
    MyObj mo;
    auto valueCopy = mo.getValueCopy();
    auto valueRef = mo.getValueRef();
    mo.value = 321;
    std::cerr << valueCopy() << std::endl;  // 123
    std::cerr << valueRef() << std::endl;   // 321

    // std::apply: Invoke a Callable object with a tuple of arguments.
    auto add = [](int x, int y) {
        return x + y;
    };
    std::cerr << std::apply(add, std::make_tuple(1, 2)) << std::endl; // == 3

    // std::invoke: Invoke a Callable object with parameters
    Proxy<decltype(add)> p {add};
    std::cerr << p(1, 2) << std::endl; // == 3

    return 0;
}