#include <iostream>

void print(int arr[], unsigned int size){
    for (unsigned int idx=0; idx < size; ++idx){
        std::cout << arr[idx] << ' ';
    }
    std::cout << std::endl;
}

int main(){
    int arr[10] = {0};
    for (int idx = 0; idx<20; ++idx){
        arr[idx]=idx;
    }

    print(arr, 50);
}