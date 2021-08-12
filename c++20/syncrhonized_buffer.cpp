#include <iostream>

#include <thread>
#include <vector>

#include <syncstream>

int foo()
{
    std::osyncstream{std::cerr} << "Executing" << std::endl;

    return 1000;
}

int main()
{
    std::vector<std::thread> threadsVector;
    for (int i = 0; i < 10; i++)
    {
        threadsVector.emplace_back(foo);  // thread will run foo()
    }
    for (auto& thread : threadsVector) {
        thread.join(); // Wait for threads to finish
    }

    return 0;
}
