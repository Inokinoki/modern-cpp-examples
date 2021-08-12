#include <vector>
#include <iostream>

int main()
{
    // This feature simplifies common code patterns, helps keep scopes tight,
    // and offers an elegant solution to a common lifetime problem.
    for (auto v = std::vector{1, 2, 3}; auto& e : v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
    return 0;
}
