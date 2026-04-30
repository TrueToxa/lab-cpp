#include <iostream>
#include <string>

using std::cout, std::endl, std::cin;

int main() {
    int m, n, k;
    cin >> m >> n >> k;
    double **v2d = new double*[m];
    for (unsigned idx = 0; idx < m; ++idx) {
        v2d[idx] = new double[n];
    }
    for (unsigned i = 0; i < m; ++i) {
        for (unsigned j = 0; j < n; ++j) {
            cin >> v2d[i][j];
        }
    }
    bool flag = 0;
    for (unsigned i = 0; i < m; ++i) {
        for (unsigned j = 0; j < n; ++j) {
            if (v2d[i][j] == k)
            {
                flag = 1;
                break;
            }
        }
        if (flag) break;
    }
    cout << flag;
    delete[] v2d;
    return 0;
}