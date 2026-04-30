#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    if (n == 0)
    {
        cout << 0 << endl;
    }
    else if (n == 1)
    {
        cout << 1 << endl;
    }
    else
    {
        long long g_1 = 1;
        long long g_2 = 1;
        long long g_3 = 0;
        long long g_idx = 2 * g_1 + 2 * g_2 - g_3;

        for (long long idx = 2; idx <= n; idx++)
        {
            g_idx = 2 * g_1 + 2 * g_2 - g_3;
            g_3 = g_2;
            g_2 = g_1;
            g_1 = g_idx;
        }

        cout << g_idx << endl;
    }
    return 0;
}