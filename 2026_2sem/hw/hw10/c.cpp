#include <iostream>
using namespace std;

// где то в counts сохраняет несколько раз, непорядок
int raspil(int n, int *prices, int *counts, int size, int *raspil_memory)
{
    if (size == 1)
    {
        counts[0] = n / 1;
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
    // !!!!!!!!!!!!!!!!!!!!!!
    int counts_tmp[10] = {0}; // сохраняем для каждого кол-ва надрезов и выбираем лучший

    for (int idx = n / size; idx >= 0; idx--)
    {
        // обнуляем, чтобы не считалос несколько раз
        for (int i = 0; i < size - 1; i++)
        {
            counts[i] = 0;
        }

        int sum = idx * prices[size - 1] + raspil(n - idx * size, prices, counts, size - 1, raspil_memory);
        if (sum > max)
        {
            max = sum;
            idx_max = idx;

            for (int i = 0; i < size - 1; i++)
            {
                counts_tmp[i] = counts[i];
            }
            counts_tmp[size - 1] = idx_max;
        }
    }

    for (int i = 0; i < size; i++)
    {
        counts[i] = counts_tmp[i];
    }

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
    for (int i = 0; i < 500; i++)
    {
        raspil_memory[i] = -1;
    }

    raspil(n, prices, counts, 10, raspil_memory);

    for (int len = 1; len <= 10; len++)
    {
        for (int j = 0; j < counts[len - 1]; j++)
        {
            cout << len << " ";
        }
    }
    cout << endl;

    return 0;
}