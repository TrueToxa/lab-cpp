#include <iostream>

template <size_t N>
struct Fibonacci{
    const static size_t value = Fibonacci<N-1>::value + Fibonacci<N-2>::value;
};

template <>
struct Fibonacci<1>{
    const static size_t value = 1;
};

template <>
struct Fibonacci<2>{
    const static size_t value = 1;
};

size_t  fibonacci(int N) {
    if (N>2) {
        return fibonacci(N-1)+fibonacci(N-2);
    }
    return 1;
}

int main() {
    std::cout << Fibonacci<800>::value << std::endl;
    std::cout << fibonacci(45) << std::endl;
    return 0;
}