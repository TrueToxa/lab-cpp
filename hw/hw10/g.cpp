#include <iostream>
using namespace std;

/* Алгоритм взят отсюда:
https://foxford.ru/wiki/informatika/
naibolshaya-vozrastayuschaya-podposledovatelnost?utm_referrer=https%3A%2F%2Fyandex.ru%2F*/

int main()
{
    int n;
    cin >> n;

    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int *tails = new int[n];
    int *pos = new int[n];
    int *prev = new int[n];
    int length = 0;

    for (int i = 0; i < n; i++)
    {
        int l = 0, r = length;
        while (l < r)
        {
            int m = (l + r) / 2;
            if (tails[m] < a[i])
                l = m + 1;
            else
                r = m;
        }
        int j = l;
        tails[j] = a[i];
        pos[j] = i;

        if (j > 0)
        {
            prev[i] = pos[j - 1];
        }
        else
        {
            prev[i] = -1;
        }

        if (j == length)
        {
            length++;
        }
    }

    int *result = new int[length];
    int cur = pos[length - 1];

    for (int i = length - 1; i >= 0; i--)
    {
        result[i] = a[cur];
        cur = prev[cur];
    }

    for (int i = length - 1; i >= 0; i--)
    {
        cout << result[i] << " ";
    }
    cout << length << endl;

    delete[] a;
    delete[] tails;
    delete[] pos;
    delete[] prev;
    delete[] result;

    return 0;
}