#include <tuple>
#include <string>
#include <iostream>

int main()
{
    auto personInfo = std::make_tuple("Inoki", 25, "CA", "FR");

    std::string name, r, u;
    int age;

    // Extract values to corresponding
    std::tie(name, age, r, u) = personInfo;
    std::cout << "Name: " << name << std::endl;
    std::cout << r << " " << u << std::endl;
    // Extract with ignored
    std::tie(name, std::ignore, r, u) = personInfo;

    return 0;
}
