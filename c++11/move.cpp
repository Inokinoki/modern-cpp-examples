#include <vector>
#include <ctime>
#include <iostream>

#include <chrono>

int main()
{
    std::vector<int> move_target;
    std::vector<int> copy_target;

    {
        std::vector<int> move_source(1000000, 114514);

        // Get ending timepoint
        auto start = std::chrono::high_resolution_clock::now();
        copy_target = move_source;
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        std::cerr << "Time taken by copy: " << duration.count() << " ms" << std::endl;

        start = std::chrono::high_resolution_clock::now();
        move_target = std::move(move_source);
        stop = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        std::cerr << "Time taken by std::move: " << duration.count() << " ms" << std::endl;
    }

    return 0;
}
