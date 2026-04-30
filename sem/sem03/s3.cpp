#include <iostream>

#ifndef N
#difine N 10
#endif



void print(int arr[], unsigned int size) {
    for (unsigned int idx=0; idx < size; ++idx){
        std::cout << arr[idx] << ' ';
    }
    std::cout << std::endl;
    // return; если нужно закончить раньше
}

void assign(int arr[]) {
    for (int idx=0; idx < N; ++idx){
        arr[idx] = idx;
    }
}

void swap(int& lhv, int& rhv){
    int tmp = lhv;
    lhv = rhv;
    rhv = tmp;
}

int main(){
    int arr[N] = {0};
    float f = 1.14f;
    double d = 2.2224;
    assign(arr);
    swap(arr[1], arr[5]);
    print(arr, N);
    std::cout << &d << std::endl;
    std::cout << &f << std::endl;
    return 0;
}
