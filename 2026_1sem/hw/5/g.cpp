#include <iostream>
#include <cstring>
// В задаче три теста преобразований: 
// std::int64_t -> double, 
// float -> int, 
// int32_t -> uint32_t.

template<typename T, typename U>
T Cast(U value) {
    return static_cast<T>(value);
}

template<typename T, typename U>
void copy_n(T* ans, U* arr, size_t arr_size) {
    // T* ans = new double[arr_size];
    for (size_t idx=0; idx<arr_size; ++idx) {
        ans[idx] = Cast<T>(arr[idx]);
    }
    return;
}

int main(){
    int ints[] = {1, 2, 3, 4};
    double doubles[4] = {};
    copy_n(doubles, ints, 4); // теперь в массиве doubles содержатся элементы 1.0, 2.0, 3.0 и 4.0
}
