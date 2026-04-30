#include <iostream>
using namespace std;

// где то в counts сохраняет несколько раз, непорядок
int raspil(int n, int *prices, int *counts, int size, int *raspil_memory)
{
    if (size == 1)
    {
        return (n / 1) * prices[0];
    }
    // если уже вычисляли, возвращаем из памяти
    if (raspil_memory[n] != -1)
    {
        return raspil_memory[n];
    }

    // рекурсия по добавлению большей длины
    int max = 0;
    int idx_max = 0;
    for (int idx = n / size; idx >= 0; idx--)
    {
        // обнуляем, чтобы не считалос несколько раз
        // for (int i = 0; i < size-1; i++) {
        //     counts[i] = 0;
        // }
        
        int sum = idx * prices[size - 1] + raspil(n - idx * size, prices, counts, size - 1, raspil_memory);
        // int sum = idx * prices[size - 1] + raspil(n - idx * size, prices, counts, size, raspil_memory);
        if (sum > max)
        {
            max = sum;
            idx_max = idx;

        
            counts[size - 1] = idx_max;
        }
    }
    // raspil_memory[n-prices[size - 1]*idx_max] = max - prices[size - 1]*idx_max;
    raspil_memory[n] = max;
    return max;
}

int main()
{
    long long n;
    cin >> n;
    int prices[10] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int counts[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int raspil_memory[500];
    for (int i = 0; i < 500; i++) {
        raspil_memory[i] = -1;
    }
    // выводим цены
    //  for (int idx =0; idx<10; idx++) {
    //      cout << prices[idx] << " ";
    //  }

    // cout << '$' << raspil(n, prices, counts, 10) << endl;
    cout << raspil(n, prices, counts, 10, raspil_memory) << endl;
    for (int idx =0; idx<10; idx++) {
        cout << counts[idx] << " ";
    }
    return 0;
}