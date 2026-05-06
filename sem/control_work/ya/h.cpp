#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int **yamki = new int*[N];
    for (int i = 0; i < N; ++i) {
        yamki[i] = new int[N];
        for (int j = 0; j < N; ++j) {
            if (i == j)
                yamki[i][j] = 0;
            else
                cin >> yamki[i][j];
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << "Sight " << i << " is connected with: ";
        bool flag = true;
        for (int j = 0; j < N; ++j) {
            if (yamki[i][j] != 0) {
                if (!flag)
                    cout << ", ";
                cout << j << " (distance is " << yamki[i][j] << ")";
                flag = false;
            }
        }
        cout << "," << endl;
    }

    for (int i = 0; i < N; ++i)
        delete[] yamki[i];
    delete[] yamki;
    return 0;
}