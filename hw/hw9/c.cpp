#include <iostream>
using namespace std;

int greedy_change(int M, int k, int* a_k) {
    int count = 0;
    int sum = 0;
    for (int idx=k-1; idx>=0; idx--) {
        count = count + M/a_k[idx];
        // cout << M/a_k[idx] << "*";
        M = M- (M/a_k[idx])*a_k[idx];
    }
    // cout << "$" << count << "$" << endl;
    return count;
}
int min_non_zero(int a, int b) {
    if (a<b) return a;
    return b;
}
int change(int M, int k, int* a_k) {
    return min( greedy_change(M, k, a_k), 
                greedy_change(M, k-1, a_k));
}

int main()
{
    int k;
    cin >> k;
    int* a_k = new int[k];
    for (int idx = 0; idx<k; idx++) {
        cin >> a_k[idx];
    }
    // cout << m << ' ' << n << endl;
    int M;
    cin >> M;

    // for (int idx = 0; idx<k; idx++) {
    //     cout << a_k[idx] << " ";
    // }
    // cout << "greedy: " << greedy_change(M, k, a_k) << endl;
    // cout << "change: " << change(M, k, a_k) << endl;
    cout << change(M, k, a_k) << endl;

    delete[] a_k;
}