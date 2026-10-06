#include <iostream>
using namespace std;

int main()
{
    long long int m, n;
    cin >> m >> n;
    // cout << m << ' ' << n << endl;
    while (m >= 1)
    {
        long long int rem = (n + m - 1) / m; // деление с округлением вверх
        cout << rem;
        m = m * rem - n; // берем остаток (-n) по mod(m)
        n = n * rem;     // обновляем знаменатель
        if (m >= 1)
        {
            cout << " ";
        }
    }
}