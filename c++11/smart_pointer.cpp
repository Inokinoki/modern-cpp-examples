#include <iostream>
#include <memory>

#include <cstring>

#include "common.h"

void function_use_shared_ptr(std::shared_ptr<LifecycleLogger> p)
{
    // There is a ref counter in `p`,
    // the counter is augmented upon copy,
    // and reduced when going out the scope
    std::cerr << "[SharedPtr] Ref count " << p.use_count() << std::endl;
}

void function_use_unique_ptr(std::unique_ptr<LifecycleLogger> p)
{
    // The ownership of the instance in unique ptr is the function, and will be released
}

void function_use_weak_ptr(std::weak_ptr<LifecycleLogger> p)
{
    // Weak ptr does not affect ref count
    if (!p.expired())
    {
        std::cerr << "[SharedPtr] Ref count " << p.use_count() << std::endl;
        // Once locked, the ref is incremented by 1 if possible, to be used safely
        std::shared_ptr<LifecycleLogger> ptr = p.lock();
        std::cerr << "[SharedPtr] Ref count " << p.use_count() << std::endl;
    }
}

int main(int argc, char *argv[])
{
    // std::unique_ptr is a non-copyable, movable pointer that manages its own heap-allocated memory.
    std::unique_ptr<LifecycleLogger> p1 { new LifecycleLogger(std::cerr) };

    std::cerr << std::endl << "Creating std::unique_ptr p2" << std::endl;
    std::unique_ptr<LifecycleLogger> p2 { new LifecycleLogger(std::cerr) };

    // std::shared_ptr is a smart pointer that manages a resource that is shared across multiple owners.
    std::cerr << std::endl << "Creating std::shared_ptr sp1" << std::endl;
    std::shared_ptr<LifecycleLogger> sp1 { new LifecycleLogger(std::cerr) };

    std::cerr << "[SharedPtr] Ref count of sp1: " << sp1.use_count() << std::endl;
    function_use_shared_ptr(sp1);   // Ref count +1 when copied, -1 when the copied instance is out-of-scope
    if (sp1)
    {
        std::cerr << std::endl << "[SharedPtr] Ref count of sp1: " << sp1.use_count() << std::endl;
    }
    function_use_weak_ptr(sp1);     // Weak ref does not change anything
    if (sp1)
    {
        std::cerr << std::endl << "[SharedPtr] Ref count of sp1: " << sp1.use_count() << std::endl;
    }

    function_use_unique_ptr(std::move(p2)); // Ownership is passed to the function
    if (!p2)
    {
        std::cerr << std::endl << "p2 is already moved due to the function calling" << std::endl;
    }

    {
        // The instance will be deconstructed when the std::unique ptr is out-of-scope
        std::unique_ptr<LifecycleLogger> p3 { new LifecycleLogger(std::cerr) };

        if (argc > 1 && std::strcmp(argv[1], "--test-std-move") == 0)
        {
            // The ownership is passed from p1 to p3
            std::unique_ptr<LifecycleLogger> p4 = std::move(p1);
            // The first instance will be released here, if `--test-std-move` is set
        }
    }

    if (!p1)
    {
        std::cerr << std::endl << "p1 is already moved" << std::endl;
    }

    std::cerr << std::endl << "The program will be finished" << std::endl;

    return 0;
}
