#include <iostream>
using namespace std;

long max_ab(long a, long b)
{
    if (a > b)
        return a;
    return b;
}

int main()
{
    int N, M;
    cin >> N >> M;

    int **a = new int *[N];
    long **dp = new long *[N];
    long **cnt = new long *[N];

    for (int i = 0; i < N; i++)
    {
        a[i] = new int[M];
        dp[i] = new long[M];
        cnt[i] = new long[M];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = M - 1; j >= 0; j--)
        {

            if (i == N - 1 && j == M - 1)
            {
                dp[i][j] = a[i][j];
            }
            else
            {

                long best;
                bool has = false;

                if (i + 1 < N)
                {
                    best = dp[i + 1][j];
                    has = true;
                }

                if (j + 1 < M)
                {
                    if (!has)
                    {
                        best = dp[i][j + 1];
                        has = true;
                    }
                    else
                    {
                        best = max_ab(best, dp[i][j + 1]);
                    }
                }

                dp[i][j] = a[i][j] + best;
            }
        }
    }

    cnt[N - 1][M - 1] = 1;

    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = M - 1; j >= 0; j--)
        {

            if (i == N - 1 && j == M - 1)
                continue;

            cnt[i][j] = 0;

            if (i + 1 < N)
                cnt[i][j] += cnt[i + 1][j];

            if (j + 1 < M)
                cnt[i][j] += cnt[i][j + 1];
        }
    }

    cout << cnt[0][0] << endl;
    cout << dp[0][0] << endl;

    for (int i = 0; i < N; i++)
    {
        delete[] a[i];
        delete[] dp[i];
        delete[] cnt[i];
    }

    delete[] a;
    delete[] dp;
    delete[] cnt;

    return 0;
}