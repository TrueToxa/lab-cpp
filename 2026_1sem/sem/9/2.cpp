#include <iostream>

template <typename T>
void func(T x) {
    std::cout << "lvalue" << std::endl;
}

template <typename T>
void func(T&& x) {
    std::cout << "rvalue" << std::endl;
}

// template<typename T>
// void wrapper(T&&) {
//     ...
// }

void foo(int& x) {
    std::cout << "lvalue" << std::endl;
}

void foo(int&& x) {
    std::cout << "rvalue" << std::endl;
}

void boo(int y) {
    foo(std::forward<int>(y));
}

int main() {
    foo(3);
    int x = 5;
    foo(x);
    std::cout << "***" << std::endl;
    boo(x);
    boo(3);
    return 0;
}