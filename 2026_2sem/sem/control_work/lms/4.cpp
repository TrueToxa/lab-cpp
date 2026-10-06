#include <iostream>
using namespace std;

int main()
{
    int P;
    cin >> P;

    int *nums = new int[P];
    for (int idx = 0; idx < P; idx++)
    {
        cin >> nums[idx];
    }

    int K;
    cin >> K;

    int left = 1;
    int right = P - 1;
    int ans = P - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        int cnt = 0;
        int idx = 0;

        while (idx < P - 1)
        {
            int next = idx + mid;
            if (next >= P - 1)
            {
                cnt++;
                break;
            }

            while (next > idx && nums[next] == 0)
            {
                next--;
            }

            if (next == idx)
            {
                cnt = K + 1;
                break;
            }

            cnt++;
            idx = next;
        }

        if (cnt <= K)
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << ans << endl;

    delete[] nums;
    return 0;
}