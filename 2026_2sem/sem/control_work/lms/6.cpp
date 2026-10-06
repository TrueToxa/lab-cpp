#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    if (N % 2 == 1)
    {
        cout << 0 << endl;
    }
    else
    {
        long long dp[33] = {0};
        dp[0] = 1;
        dp[2] = 3;

        for (int i = 4; i <= N; i += 2)
        {
            dp[i] = 4 * dp[i - 2] - dp[i - 4];
        }

        cout << dp[N] << endl;
    }
    return 0;
}