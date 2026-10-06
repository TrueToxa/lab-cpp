#include <iostream>
template<typename T, size_t const arr_size>
T sum_array(T* arr) {
    T ans = 0;
    for (size_t idx=0; idx<arr_size; ++idx) {
        ans += arr[idx];
    }
    return ans;
}

int main() {
    return 0;
}