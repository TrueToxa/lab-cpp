#include <iostream>

unsigned fib(unsigned N) {
    if (N<2) {
        return 1;
    }
    return fib(N-1) + fib(N-2);
}

void swap(int& lhv, int& rhv) {
    int tmp = lhv;
    lhv = rhv;
    rhv = lhv;
}

void quick_sort(int *arr, int l_idx, int r_idx, int size) {
    int op = arr[(l_idx+r_idx) / 2];
    while (l_idx < r_idx) {
        while (arr[idx] < op) ++l_idx;
        while (arr[r_idx] > op) --r_idx;
        if (l_idx < r_idx) swap(arr[l_idx], arr[r_idx]);
    }
    quick_sort(arr, 0, l_idx, l_idx+1);
    quick_sort(arr, l_idx+1, size-1, size-l_idx-1);
}

int main() {
    std::cout << "***" << std::endl;
    std::cout << fib(42) << std::endl;

    // Velocity of n particles
    double *v_x = new double[1000];
    double *v_y = new double[1000];
    // v[idx_particle][idx_dimention];
    double **v2d = new double*[1000];
    for (size_t idx = 0; idx < 1000; ++idx) {
        v2d[idx] = new double[2];
    }
 
    return 52;
}