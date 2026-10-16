// template <typename T>
// <size_t N=10>

/*Шаблон -- метаязык, язык над языком*/

#include <iostream>

void print() {
    std::cout << std::endl;
}

template <typename T>
void print(T arg) {
    std::cout << arg << ' ';
}

template <typename T, typename... Args>
void print(T arg, Args ...args) {
    std::cout << arg << ' ';
    print(args...);
}

template <typename U, typename V>
struct is_same{
    //is_same<int, A>() -> false
    //is_same<float, float>() -> true
    const static bool field = false;
};

template <typename U>
struct is_same<U, U>{
    const static bool field = true;
};

template <>
struct is_same<int, char>{
    const static bool field = true;
};

int main() {
    std::cout << is_same<int, float>::field << std::endl;
    std::cout << is_same<int, int>::field << std::endl;
    std::cout << is_same<int, char>::field << std::endl;
    print(1, 2, "aboba", 67);
}