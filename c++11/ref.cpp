#include <iostream>
#include <vector>
#include <memory>

struct Bar {
    // ...
};

struct Foo {
    Bar getBar() & { std::cerr << "Get from a ref" << std::endl; return bar; }
    Bar getBar() const& { std::cerr << "Get from a const ref" << std::endl; return bar; }
    Bar getBar() && { std::cerr << "Get from a rvalue ref" << std::endl; return std::move(bar); }
private:
    Bar bar;
};

int main()
{
    Foo foo{};
    Bar bar = foo.getBar(); // calls `Bar getBar() &`

    const Foo foo2{};
    Bar bar2 = foo2.getBar(); // calls `Bar Foo::getBar() const&`

    Foo{}.getBar(); // calls `Bar Foo::getBar() &&`
    std::move(foo).getBar(); // calls `Bar Foo::getBar() &&`

    std::move(foo2).getBar(); // calls `Bar Foo::getBar() const&&`

    // create a container to store reference of objects.
    auto val = 99;
    auto _ref = std::ref(val);
    _ref++;
    auto _cref = std::cref(val);
    //_cref++; does not compile
    std::vector<std::reference_wrapper<int>>vec; // vector<int&>vec does not compile
    vec.push_back(_ref); // vec.push_back(&i) does not compile
    std::cout << val << std::endl; // prints 100
    std::cout << vec[0] << std::endl; // prints 100
    std::cout << _cref; // prints 100

    return 0;
}
