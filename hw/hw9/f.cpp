#include <iostream>
using namespace std;

int greedy_count(int N, int idx, int *s, int *f, int last)
{
    if (idx >= N)
    {
        return 0;
    }
    if (s[idx] >= last)
    {
        return 1 + greedy_count(N, idx + 1, s, f, f[idx]);
    }
    return greedy_count(N, idx + 1, s, f, last);
}

int count_max(int N, int *s, int *f)
{
    return greedy_count(N, 0, s, f, 0);
}

int main()
{
    int N;
    cin >> N;
    int *s = new int[N];
    int *f = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> s[i] >> f[i];
    }

    cout << count_max(N, s, f) << endl;

    delete[] s;
    delete[] f;
    return 0;
    // return 52;
}