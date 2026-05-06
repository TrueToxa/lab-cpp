#include <iostream>

using namespace std;

// using std::cout;
// using std::cin;
// using std::endl;

void swap(int &lhv, int &rhv)
{
    int tmp = lhv;
    lhv = rhv;
    rhv = tmp;
}

void quick_sort(int *arr, int l_idx, int r_idx, int size)
{
    if (l_idx >= r_idx)
    {
        return;
    }
    int l_tmp = l_idx, r_tmp = r_idx;

    int op = arr[(l_idx + r_idx) / 2];
    while (l_idx <= r_idx)
    {
        while (l_idx <= r_idx && arr[l_idx] < op)
            ++l_idx;
        while (l_idx <= r_idx && arr[r_idx] > op)
            --r_idx;
        if (l_idx <= r_idx)
        {
            swap(arr[l_idx], arr[r_idx]);
            ++l_idx;
            --r_idx;
        }
    }
    if (l_tmp < r_idx)
        quick_sort(arr, l_tmp, r_idx, size);

    if (l_idx < r_tmp)
        quick_sort(arr, l_idx, r_tmp, size);
}

void print_marks(int *marks, int N)
{
    for (int idx = 0; idx < N; ++idx)
    {
        cout << marks[idx] << ' ';
    }
    cout << endl;
    return;
}
int main()
{
    int K, M, N;
    cin >> K >> M >> N;
    // Karl Marx
    int *marks = new int[K];
    for (int idx = 0; idx < K; idx++)
    {
        cin >> marks[idx];
    }
    // print_marks(marks, K);
    quick_sort(marks, 0, K - 1, K);
    // print_marks(marks, K);

    int max_min = 0;
    float sum = 0;
    for (int idx = 0; idx + N <= K; idx = idx + N)
    {
        int diff = marks[idx + N - 1] - marks[idx];
        if (diff > max_min)
        {
            max_min = diff;
        }
        sum += diff;
    }
    
    cout << max_min << " " << sum / M;
    delete[] marks;
    return 0;
}
