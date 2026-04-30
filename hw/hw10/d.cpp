#include <iostream>
using namespace std;

int main()
{
    int x_1;
    cin >> x_1;

    int dp[61] = {0};

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= x_1; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    cout << dp[x_1] << endl;

    return 0;
}