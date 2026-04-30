#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    long long n;
    std::cin >> n;
    std::vector<long long> s(n, 0);
    std::vector<long long> c(n, 0);
    for (long long idx = 0; idx < n; idx++)
    {
        std::cin >> s[idx] >> c[idx];
    }
    long long ans = -1, l = -100, r = -100; //, last = 0;
    for (long long idx = 0; idx < n; idx++)
    {

        if (r < s[idx])
        {
            ans += r - l + 1;
            l = s[idx];
            r = c[idx];
        }
        else
        {
            r = std::max(r, c[idx]);
        }
        //        std::cout << l << " " << r << std::endl;
    }
    std::cout << ans + r - l + 1;

    return 0;
}