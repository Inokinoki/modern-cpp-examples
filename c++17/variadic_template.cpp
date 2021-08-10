#include <iostream>

template <typename... Args>
auto sumAll(Args... args)
{
    return (args + ...);
}

int main()
{
    std::cerr << sumAll(1, 2, 3, 4, 5) << std::endl;
    std::cerr << sumAll(1, 2, 3) << std::endl;
    return 0;
}
