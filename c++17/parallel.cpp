#include <chrono>
#include <vector>
#include <algorithm>
#include <execution>
#include <iostream>

int main()
{
    // Many of the STL algorithms, such as the copy, find and sort methods,
    // started to support the parallel execution policies: seq, par and par_unseq
    // which translate to "sequentially", "parallel" and "parallel unsequenced".
    std::vector<int> longVector(10000, 0);
    std::vector<int> longVector1(10000, 0);
    std::vector<int> longVector2(10000, 0);
    std::vector<int> longVector3(10000, 0);
    for (int i = 0; i < 10000; i++) {
        longVector[i] = std::rand();
        longVector1[i] = longVector[i];
        longVector2[i] = longVector[i];
        longVector3[i] = longVector[i];
    }

    auto begin = std::chrono::high_resolution_clock::now();
    // Sort elements using sequential execution policy
    std::sort(std::execution::seq, std::begin(longVector), std::end(longVector));
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    std::cerr << "Time taken by seq: " << duration.count() << " ms" << std::endl;

    auto begin1 = std::chrono::high_resolution_clock::now();
    // Find element using parallel execution policy
    std::sort(std::execution::par, std::begin(longVector1), std::end(longVector1));
    auto end1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - begin1);
    std::cerr << "Time taken by parallel: " << duration1.count() << " ms" << std::endl;

    auto begin2 = std::chrono::high_resolution_clock::now();
    // Find element using unseq execution policy
    std::sort(std::execution::unseq, std::begin(longVector2), std::end(longVector2));
    auto end2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - begin2);
    std::cerr << "Time taken by unseq: " << duration2.count() << " ms" << std::endl;

    auto begin3 = std::chrono::high_resolution_clock::now();
    // Find element using parallel execution policy
    std::sort(std::execution::par_unseq, std::begin(longVector3), std::end(longVector3));
    auto end3 = std::chrono::high_resolution_clock::now();
    auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(end3 - begin3);
    std::cerr << "Time taken by unseq+parallel: " << duration3.count() << " ms" << std::endl;

    return 0;
}
