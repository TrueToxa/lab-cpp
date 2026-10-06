#include <cstddef>
// void quick_sort(T* arr, size_t arr_size);

template<typename T> 
void quick_sort(T* arr, size_t arr_size) {
    int left = 0;
    int right = arr_size - 1;
    T pivot = arr[arr_size / 2];
    while (left <= right) {
        while(arr[left] < pivot) {
            ++left;
        }
        while(arr[right] > pivot) {
            --right;
        }
        if (left <= right) {
            std::swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }

    if(right > 0) {
        quick_sort(arr, right + 1);
    }
    if (left < arr_size) {
        quick_sort(arr + left, arr_size - left);
    }
}

int main() {
    return 0;
}