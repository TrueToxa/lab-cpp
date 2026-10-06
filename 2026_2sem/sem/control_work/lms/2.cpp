#include <iostream>
using namespace std;
unsigned long long int sum_arr(unsigned long long *arr, int start, int end)
{
    //  сумма элементов массива в срезе [strt; end] включая концы
    unsigned long long sum = 0;
    for (int idx = start; idx <= end; idx++)
    {
        sum = sum + arr[idx];
    }
    return sum;
}
int main()
{
    int N;
    cin >> N;
    unsigned long long *nums = new unsigned long long[N];
    unsigned long long sum = 0;
    for (int idx = 0; idx < N; idx++)
    {
        cin >> nums[idx];
        sum = sum + nums[idx];
    }
    unsigned long long int L;
    cin >> L;
    if (sum < L)
    {
        cout << N << endl;
    }
    else
    {
        int min_cnt = N;
        for (int idx1 = 0; idx1 < N; idx1++)
        {
            for (int idx2 = idx1; idx2 < N; idx2++)
            {
                sum = sum_arr(nums, idx1, idx2);
                if (sum >= L)
                {
                    if (idx2 - idx1 + 1 < min_cnt)
                    {
                        min_cnt = idx2 - idx1 + 1;
                    }
                }
            }
        }
        cout << min_cnt << endl;
    }
    delete[] nums;
    return 0;
}