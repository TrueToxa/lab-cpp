#include <iostream>

using namespace std;

long long zero_cnt(long long val)
{
    long long ans = 0;
    while (val > 0 && val % 10 == 0)
    {
        ans += 1;
        val = val / 10;
    }
    return ans;
}

int main()
{
    long long N;
    cin >> N;

    long long **optimals = new long long *[N];
    for (long long row = 0; row < N; ++row)
    {
        optimals[row] = new long long[N]();
        for (long long col = 0; col < N; ++col)
        {
            cin >> optimals[row][col];
        }
    }

    for (long long row = 0; row < N; ++row)
    {
        for (long long col = 0; col < N; ++col)
        {
            if (row == 0 && col > 0)
            {
                optimals[row][col] = optimals[row][col] * optimals[row][col - 1];
            }
            else if (row > 0 && col == 0)
            {
                optimals[row][col] = optimals[row][col] * optimals[row - 1][col];
            }
            else if (row > 0 && col > 0)
            {
                long long cnt_up = zero_cnt(optimals[row][col] * optimals[row - 1][col]);
                long long cnt_left = zero_cnt(optimals[row][col] * optimals[row][col - 1]);
                if (cnt_up < cnt_left)
                {
                    optimals[row][col] = optimals[row][col] * optimals[row - 1][col];
                }
                else
                {
                    optimals[row][col] = optimals[row][col] * optimals[row][col - 1];
                }
            }
        }
    }

    cout << zero_cnt(optimals[N - 1][N - 1]) << endl;

    for (long long idx = 0; idx < N; ++idx)
    {
        delete[] optimals[idx];
    }
    delete[] optimals;

    return 0;
}