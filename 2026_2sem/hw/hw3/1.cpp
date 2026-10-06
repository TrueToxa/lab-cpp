#include <iostream>

#ifndef N
#difine N 10
#endif

void print(int arr[], unsigned int size);
void assign(int arr[], int st);
void swap(int& lhv, int& rhv);

void readArray(int (&arr)[N]){
	for (int idx=0; idx<N; ++idx) {
    	std::cin >> arr[idx];
    }
}

void printArray(int (&arr)[N]){
    for (unsigned int idx=0; idx < N; ++idx){
        std::cout << arr[idx] << ' ';
    }
    std::cout << std::endl;
}

void reverseArray(int (&arr)[N]){
    for (unsigned int idx=0; idx < N/2; ++idx){
        int tmp = arr[idx];
        arr[idx] = arr[N-1-idx];
        arr[N-1-idx] = tmp;
    }
}

void shiftArrayLeft(int (&arr)[N]){
    int start_num = arr[0];
    for (unsigned int idx=0; idx < N-1; ++idx){
        arr[idx] = arr[idx+1];
    }
    arr[N-1] = start_num;
}

void shiftArrayRight(int (&arr)[N]){
    int end_num = arr[N-1];
    int tmp = arr[0];
    for (unsigned int idx=0; idx < N-1; ++idx){
        int tmp1 = arr[idx+1];
        arr[idx+1] = tmp;
        tmp = tmp1;
    }
    arr[0] = end_num;
}

void moveNegativeToStart(int (&array)[N]){
    for (unsigned int idx=0; idx < N; ++idx){
        if (array[idx]<0){
            while (idx-1>0 and array[idx-1]>=0){
                swap(array[idx], array[idx-1]);
                idx-=1;
            }
            if (idx-1 == 0 and array[idx-1]>=0){
                swap(array[idx], array[idx-1]);
            }
        }
    }
}

void moveNegativeToEnd(int (&array)[N]){
    for (unsigned int idx=N-1; idx > 0; --idx){
        if (array[idx]<0){
            while (idx+1<N-1 and array[idx+1]>=0){
                swap(array[idx], array[idx+1]);
                idx+=1;
            }
            if (idx+1 == N-1 and array[idx+1]>=0){
                swap(array[idx], array[idx+1]);
            }
        }
    }
    int idx = 0;
        if (array[0]<0){
            while (idx+1<N-1 and array[idx+1]>=0){
                swap(array[idx], array[idx+1]);
                idx+=1;
            }
            if (idx+1 == N-1 and array[idx+1]>=0){
                swap(array[idx], array[idx+1]);
            }
        }
}

void mergeArrays(int (&lhs)[N], int (&rhs)[N], int (&res)[2 * N]){
    for (int idx=0; idx<N; ++idx){
        res[idx]=lhs[idx];
    }
    for (int idx=0; idx<N; ++idx){
        res[N+idx]=rhs[idx];
    }
}

int findLastZero(int (&array)[N]){
    if (array[N-1]==0) {
        return N-1;
    }
    int n0 = 0;
    int n1 = (N-1)/2;
    int n2 = (N-1);
    while (true) {
        if (array[n1]==0) {
            if (array[n1+1]==1) {
                return n1;
                break;
            }
            else {
                n0 = n1;
                n1 = (n1+n2)/2;
            }
        }
        else if (array[n1]==1) {
            n2 = n1;
            n1 = (n1+n0)/2;
        }
    }
    return -1;
}

// *********** 
int main(){
    int arr1[10] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    print(arr1, 10);
    std::cout << findLastZero(arr1) << std::endl;
    // assign(arr1, 0);
    // int arr2[N]={0};
    // // assign(arr2, N);
    // print(arr1, N);
    // print(arr2, N);
    // std::cout << "***" << std::endl;
    // int res[2*N];
    // mergeArrays(arr1, arr2, res);
    // print(res, 2*N);
    // std::cout << "***" << std::endl;
    return 0;

}

void print(int arr[], unsigned int size) {
    for (unsigned int idx=0; idx < size; ++idx){
        std::cout << arr[idx] << ' ';
    }
    std::cout << std::endl;
    // return; если нужно закончить раньше
}

void assign(int arr[], int st) {
    for (int idx=st; idx < st+N; ++idx){
        arr[idx] = (idx);
    }
}

void swap(int& lhv, int& rhv){
    int tmp = lhv;
    lhv = rhv;
    rhv = tmp;
}
