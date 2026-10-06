#include <iostream>
using namespace std;

int max(int lhv, int rhv)
{
    if (lhv >= rhv)
        return lhv;
    return rhv;
}
int min(int lhv, int rhv)
{
    if (lhv <= rhv)
        return lhv;
    return rhv;
}

int main()
{
    int n;
    cin >> n;

    int *sizes = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> sizes[i];
    }

    int m = n - 1; // количество матриц

    // Создаём и инициализируем dp
    int **dp = new int *[m];
    for (int i = 0; i < m; i++)
    {
        dp[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            if (i == j)
                dp[i][j] = 0;
            else
                dp[i][j] = -1;
        }
    }

    for (int len = 2; len <= m; len++)
    {
        for (int i = 0; i <= m - len; i++)
        {
            int j = i + len - 1;

            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k] + dp[k + 1][j] + sizes[i] * sizes[k + 1] * sizes[j + 1];

                if (dp[i][j] == -1 or cost < dp[i][j])
                {
                    dp[i][j] = cost;
                }
            }
        }
    }
    cout << dp[0][m - 1] << endl;

    for (int i = 0; i < m; i++)
    {
        delete[] dp[i];
    }
    delete[] dp;
    delete[] sizes;

    return 0;
}