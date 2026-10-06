// template<тайпнейм T, size_t arr_size>
// void print_array(T* arr);
// Для отработки кода можно воспользоваться куском кода

#include <iostream>

// Your realization of template <тайпнейм T, size_t arr_size> void print_array(T* arr);
template<typename T, size_t arr_size>
void print_array(T* arr) {
    if (arr_size==0) {return;}
    for (size_t idx=0; idx<arr_size-1; ++idx) {
        std::cout << arr[idx] <<" ";
    }
    std::cout << arr[arr_size-1] << std::endl;
}

int main() {
  int arr[12] = {1, 0, 2, -1, 3, -2, 4, -5, 6, -7, 8, -9};
  print_array<int, 12>(arr);
  return 0;
}
