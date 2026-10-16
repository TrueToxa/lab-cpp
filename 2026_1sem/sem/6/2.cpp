#include <iostream>

template <typename U, typename V, typename... Args>
struct is_same {
    const static bool field = 
        is_same<U, V>::field and is_same<V, Args...>::field;
};

template <typename U, typename V>
struct is_same<U, V>{
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
    std::cout << is_same<int, char>::field << std::endl;
    std::cout << is_same<int, int, int, char>::field << std::endl;
    
}