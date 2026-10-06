#include <iostream>
#include <string>

using std::cout, std::endl, std::cin;
// struct Px {
//     int deg;
//     int *p;

//     // что то про конструкторы
// }

int main() {
    int n1;
    cin >> n1;
    float *p1 = new float[n1];
    int *deg1 = new int[n1];
    for (int i = 0; i < n1; ++i) {
        cin >> p1[i] >> deg1[i];
    }

    int n2;
    cin >> n2;
    float *p2 = new float[n2];
    int *deg2 = new int[n2];
    for (int i = 0; i < n2; ++i) {
        cin >> p2[i] >> deg2[i];
    }

    int n3 = deg1[0] + deg2[0];
    float *p3 = new float[n3 + 1]{0};
    int *deg3 = new int[n3 + 1];
    for (int i = 0; i <= n3; ++i) {
        deg3[i] = n3 - i;
    }
    

    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            p3[n3 - (deg1[i] + deg2[j])] += p1[i] * p2[j];
        }
    }
    

    int n0 = 0;
    for (int i = 0; i <= n3; ++i) {
        if (p3[i] != 0) n0++;
    }
    

    cout << n0;
    for (int i = 0; i <= n3; ++i) {
        if (p3[i] != 0) {
            cout << ' ' << p3[i] << ' ' << deg3[i];
        }
    }

    delete[] p1;
    delete[] deg1;
    delete[] p2;
    delete[] deg2;
    delete[] p3;
    delete[] deg3;

    return 0;
}