#include <iostream>
using std::cout;
using std::endl;

int array[1'000'000] = {0}

int main() {
    int N = 10'000'000;
    double *ptr; //хранит ссылку на выделенную в куче память (далеко от стека)
    ptr = new double[N]; // выделяем память в куче
    for (int idx = 0; idx < N; ++idx) {
        ptr[idx] = idx;
    }
    for (int idx = 0; idx < N; idx += 100,000) {
        // cout << ptr[idx] << endl;
    }
    cout << ptr << ' ' << &ptr << ' ' << &N << endl; // куча - стек - стек

    delete[] ptr;
    ptr = nullptr;

    ptr = new double; // 1 элемент
    *ptr = 12.34;
    cout << ptr << ' ' << *ptr << ' ' << ptr[0] << ' ' << *(ptr+0)<< endl;
    
    delete ptr;
    // ptr = NULL;
    // cout << nullptr << ' ' << ptr << endl;
    ptr = nullptr; //компилируется автоматически
    delete ptr;

    for (int  idx = 10; idx<10, ++idx){
        ptr = new double[10];
    }

    return 0;
}

// valgrind --leek-check=full .\a.exe  