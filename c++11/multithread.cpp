#include <thread>
#include <vector>
#include <iostream>

#include <future>

std::mutex lock;

int foo(bool clause)
{
    if (clause)
    {
        lock.lock();
        std::cerr << "Executing" << std::endl;
        lock.unlock();
    }
    else
    {
        lock.lock();
        std::cerr << "Executing Async" << std::endl;
        lock.unlock();
    }

    return 1000;
}

int main()
{
    std::vector<std::thread> threadsVector;
    for (int i = 0; i < 10; i++)
    {
        threadsVector.emplace_back(foo, true);  // thread will run foo(true)
    }
    for (auto& thread : threadsVector) {
        thread.join(); // Wait for threads to finish
    }

    auto handle = std::async(std::launch::async, foo, false);  // create an async task
    auto result = handle.get();  // wait for the result

    auto handle_lazy = std::async(std::launch::deferred, foo, false);  // create an async task
    // handle_lazy.get();
    // Might not be executed when no get

    return 0;
}
