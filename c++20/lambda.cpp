#include <vector>
#include <iostream>

struct int_value {
    int n = 0;
    auto getter_fn() {
        // BAD:
        // return [=]() { return n; };

        // GOOD:
        return [=, *this]() { return n; };
    }
};

// Capture parameter packs by value:
template <typename... Args>
auto f1(Args&&... args){
    // BY VALUE:
    return [...args = std::forward<Args>(args)] {
        // ...
    };
}

// Capture parameter packs by reference:
template <typename... Args>
auto f2(Args&&... args){
    // BY REFERENCE:
    return [&...args = std::forward<Args>(args)] {
        // ...
    };
}

int main()
{
    // Use familiar template syntax in lambda expressions.
    auto f = []<typename T>(std::vector<T> v) {
        for (T i: v) std::cerr << i << " ";
        std::cerr << std::endl;
    };
    std::vector<double> vi = {1, 2, 3, 4, 5};
    f(vi);

    std::vector<double> vf = {1.0, 2.0, 3.0, 4.0, 5.0};
    f(vf);

    // Lambda capture of parameter pack

    return 0;
}
