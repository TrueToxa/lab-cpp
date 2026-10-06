#include <iostream>
using namespace std;

int *create_new_arr(int *arr, int n)
{
    int size = (n - 1) * 2 + 1;
    int *new_arr = new int[size];
    new_arr[0] = n;
    for (int idx = 1; idx < size; idx++)
    {
        new_arr[idx] = arr[idx % (n - 1)];
    }
    return new_arr;
}

int main()
{
    int N;
    cin >> N;
    // int *a = new int[N];

    int *arr = new int[1];
    arr[0] = 1;
    for (int idx = 2; idx <= 33; idx++)
    {
        int *new_arr = create_new_arr(arr, idx);
        arr = new_arr;
        delete[] new_arr;
    }

    for (int idx = 0; idx < N; idx++)
    {
        int a;
        cin >> a
        arr[a];
    }

    // delete[] a;
    delete[] arr;
    return 0;
}