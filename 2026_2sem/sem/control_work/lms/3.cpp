#include <iostream>
using namespace std;

void swap(int &lhv, int &rhv)
{
    int tmp = lhv;
    lhv = rhv;
    rhv = tmp;
}

void quick_sort(int *arr, int l_idx, int r_idx, int size)
{
    if (l_idx >= r_idx)
    {
        return;
    }
    int l_tmp = l_idx, r_tmp = r_idx;

    int op = arr[(l_idx + r_idx) / 2];
    while (l_idx <= r_idx)
    {
        while (l_idx <= r_idx && arr[l_idx] < op)
            ++l_idx;
        while (l_idx <= r_idx && arr[r_idx] > op)
            --r_idx;
        if (l_idx <= r_idx)
        {
            swap(arr[l_idx], arr[r_idx]);
            ++l_idx;
            --r_idx;
        }
    }
    if (l_tmp < r_idx)
        quick_sort(arr, l_tmp, r_idx, size);

    if (l_idx < r_tmp)
        quick_sort(arr, l_idx, r_tmp, size);
}

unsigned long long int pow10(int n) {
    int p = 1;
    for (int idx = 0; idx < n; idx++) {
        p = p*10;
    }
    return p;

}


int main() {
    int N;
    cin >> N;
    int *nums = new int[N];
    for (int idx = 0; idx < N; idx++) {
        cin >> nums[idx];
    }

    quick_sort(nums, 0, N-1, N);
    unsigned long long int sum = 0;
    for (int idx = 0; idx<N; idx++) {
        sum += pow10(idx)*nums[idx];
    }
    
    cout << sum << endl;


    delete[] nums;
    return 0;
}