#include <iostream>
using namespace std;

// реализация пиромиаидальной сортировки heapSort

void swap (int& lhv, int& rhv) {
    int tmp = rhv;
    rhv = lhv;
    lhv = tmp;
}
void heapify(int *arr, const int size, int idx_root) {
    int idx_largest = idx_root;

    int idx_l = idx_root*2+1;
    if (idx_l < size and arr[idx_largest] < arr[idx_l]) {
        idx_largest = idx_l;
    }

    int idx_r = idx_root*2+2;
    if (idx_r < size and arr[idx_largest] < arr[idx_r]) {
        idx_largest = idx_r;
    }

    if (idx_largest != idx_root) {
        swap(arr[idx_largest], arr[idx_root]);

        heapify(arr, size, idx_largest);
    }
}

void heapSort(int*arr,  const int size) {
    for (int idx = size - 1; idx>= 0; --idx) {
        heapify(arr, size, idx);
    }

    for (int idx = size - 1; idx >= 0; --idx) {
        swap(arr[0], arr[idx]);
        heapify(arr, idx, 0);
    }
}

void printArray(int *arr, const int size) {
    for (int idx = 0; idx < size; ++idx) {
        cout << arr[idx] << ' ';
    }
    cout << endl;
}

int main() {
    int arr[] = {7, 3, 1, 3, 7, 6, 4, 7, 9, 0};
    const int size = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, size);
    heapSort(arr, size);
    printArray(arr, size);

    return 0;
}