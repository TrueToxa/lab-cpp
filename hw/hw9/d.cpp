#include <iostream>
using namespace std;

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

int main()
{
    long long S;
    int N;
    cin >> S >> N;
    int* a = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    heapSort(a, N);
    // for (int i = 0; i < N; i++) {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    int count = 0;
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        if (sum + a[i] <= S) {
            sum += a[i];
            count++;
        } else {
            break;
        }
    }
    cout << count;
    delete[] a;
    return 0;
}