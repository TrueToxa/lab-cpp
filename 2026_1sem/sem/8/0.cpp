#include <iostream>
#include "array.hpp"
#include <chrono> 

class TimeLogger {
    
public: 
    TimeLogger() : start{std::chrono}
}

int main() { 
    Array big_array = Array(200'000'000);

    {
    auto start = std::chrono::steady_clock::now(); 
    Array arr_copy = Array(std::move(big_array)); 
    auto stop = std::chrono::steady_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    std::cout << duration.count() << std::endl; 
}

    return 0;
}