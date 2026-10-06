#include <iostream>
using std::cout;
using std::endl;

int* give_N_elements(unsigned int N, int value) {
    int *array = new int[N]{value};
    for (unsigned idx=0; idx<N; ++idx) {
        array[idx] = value;
    }
    return array;
}

int* take_N_elements(int* ptr) {
    delete[] ptr;
    return nullptr;
}

void swap_arr(int*& ptr0, int*& ptr1) {
    int *tmp = ptr1;
    ptr1 = ptr0;
    ptr0 = tmp;
}

void reshape_arr(int*& ptr, unsigned int N, unsigned int M) {

}

void reshape_arr(int*& ptr, unsigned int N, unsigned int M) {
    int *new_ptr = new int[M];
    
    for (unsigned int i = 0; i < N; ++i) {
        new_ptr[i] = ptr[i];
    }

    for (unsigned int i = N; i < M; ++i) {
        new_ptr[i] = 0;
    }
    delete[] ptr;

    ptr = new_ptr;
}

void merge(int*& res, int*& ptr0, unsigned int N, int*& ptr1, unsigned int M) {
    int* new_res = new int[N + M];
    
    for (unsigned int i = 0; i < N; ++i) {
        new_res[i] = ptr0[i];
    }
    for (unsigned int i = 0; i < M; ++i) {
        new_res[N + i] = ptr1[i];
    }

    if (res != nullptr) {
        delete[] res;
    }

    res = new_res;
}

int main() {
    int N = 10;
    int value = 52;
    int* array = give_N_elements(N, value);
    for (int idx=0; idx<N; ++idx) {
        cout << array[idx] << ' ';
    }
    return 0;
}

