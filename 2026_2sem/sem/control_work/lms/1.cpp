#include <iostream>
using namespace std;
unsigned long long int sum_arr(unsigned long long * arr, int start, int end) {
    //  сумма элементов массива в срезе [strt; end] включая концы
    unsigned long long sum = 0;
    for (int idx = start; idx<=end; idx++) {
        sum = sum + arr[idx];
    }
    return sum;
}
int main() {
    int N;
    cin >> N;
    unsigned long long *nums = new unsigned long long[N];
    for (int idx = 0; idx < N; idx++) {
        cin >> nums[idx];
    }
    bool flag = false;
    for (int idx=1; idx<N; idx++) {
        // int sum_1 = ((idx-1)+0)*((idx-1)-0)/2;
        // int sum_2 = ((N-1)+idx)*((N-1)-idx)/2;
        unsigned long long sum1 = sum_arr(nums, 0, idx-1);
        unsigned long long sum2 = sum_arr(nums, idx, N-1);
        if (sum1 == sum2) {
            cout << idx << endl;
            flag = true;
            break;
        }
    }
    if (!flag) {
        cout << N << endl;
    }
    delete[] nums;
    return 0;
}