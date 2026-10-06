#include <iostream>
using namespace std;

int get_value(int step, long long pos) {
    while (step > 1) {
        long long prev_len = (1LL << (step - 1)) - 1;
        if (pos == 0) {
            return step;
        } else if (pos <= prev_len) {
            pos = pos - 1;
            step--;
        } else {
            pos = pos - 1 - prev_len;
            step--;
        }
    }
    return 1;
}

int main() {
    int N;
    cin >> N;
    for (int idx = 0; idx < N; idx++) {
        long long a;
        cin >> a;
        cout << get_value(33, a);
        if (idx != N - 1) cout << " ";
    }
    cout << endl;
    return 0;
}