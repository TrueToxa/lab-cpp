#include <iostream>
using namespace std;

int main()
{
    int N, k;
    cin >> N >> k;
    int S;
    cin >> S;
    int *ost = new int[S + 2];
    ost[0] = 0;
    for (int i = 1; i <= S; i++)
    {
        cin >> ost[i];
    }
    ost[S + 1] = N;

    int count = 0;
    int current = 0;
    int idx = 0;
    bool flag = true;

    while (current + k < N)
    {
        int next = current;
        while (idx < S + 2 and ost[idx] <= current + k)
        {
            next = ost[idx];
            idx++;
        }
        if (next == current)
        {
            flag = false;
            break;
        }
        current = next;
        count++;
        idx--;
    }

    if (flag)
    {
        cout << count;
    }
    else
    {
        cout << -1;
    }

    delete[] ost;
    return 0; //52
}