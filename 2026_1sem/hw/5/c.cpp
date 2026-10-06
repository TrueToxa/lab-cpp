#include <iostream>
// template <тайпнейм T, size_t const arr_size>
// void read_array(T* arr);

// Your realization of template <typename T, size_t const arr_size>
// void read_array(T* arr);
template <typename T, size_t const arr_size>
void read_array(T* arr) {
    for (size_t idx=0; idx<arr_size; ++idx) {
        std::cin >> arr[idx];
    }
}

int main() {
  size_t const arr_size = 5;
  double* arr_d = new double[arr_size];
  read_array<double, arr_size>(arr_d);
  delete[] arr_d;
  return 0;
}