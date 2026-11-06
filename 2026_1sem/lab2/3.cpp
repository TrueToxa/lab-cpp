#include <iostream>
template<typename U, typename V>
void func(U x, V y){
    std::cout << x << y << std::endl;
}

template<typename U>
void func<U, int>(U x, int y){
    std::cout << x << "Int" << y << std::endl;
}

int main() {
    func<float, int>(1.0f, 1.0f);
    func<float, int>(1.0f, 1);
    return 0;
}