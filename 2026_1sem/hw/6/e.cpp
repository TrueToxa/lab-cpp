#include <iostream>

template <typename U, typename V, typename... Args>
struct is_same_struct {
    const static bool field = 
        is_same_struct<U, V>::field and is_same_struct<V, Args...>::field;
};

template <typename U, typename V>
struct is_same_struct<U, V>{
    const static bool field = false;
};

template <typename U>
struct is_same_struct<U, U>{
    const static bool field = true;
};

template <typename T, typename U>
bool is_same(T lha, U rha) {
    return is_same_struct<T, U>::field;
}

int main() {
    std::cout<<is_same(1, 2)<<std::endl;
    std::cout<<is_same(1, 1.20)<<std::endl;
    return 0;
}