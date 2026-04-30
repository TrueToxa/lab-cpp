#include <iostream>
using std::cout;
using std::endl;

int main() {
    int N = 1'000'000, M = 1234;
    double pi = 3.141592, e = 2.;
    int* ptr_N = &N, *ptr_M = &M;
    double* ptr_pi = &pi, *ptr_e = &e;
    // & - имперсант
    cout << &N << ' ' << ptr_N << ' ' << N << endl;
    cout << &M << ' ' << M << endl;
    cout << &pi << ' ' << pi << endl;
    cout << &e << ' ' << e << endl;
    cout << ptr_N-ptr_M << endl; // = 1 = кол-во ячеек via указательная ариметика
    // cout << ptr_e-ptr_M << endl; // forbiden
    // cout << ptr_N+ptr_M << endl; // forbiden
    cout << ptr_M+3 << endl;
    *(ptr_pi+1) = 3.14;
    *(ptr_pi+1) = 3.14;
    cout << ptr_pi+1 << ' ' << *(ptr_pi+1) << endl;
    cout << &M << ' ' << M << endl;
    return 0;
}