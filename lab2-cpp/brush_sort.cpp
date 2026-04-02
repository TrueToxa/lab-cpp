#include <iostream>
#include <random>
#include <chrono>
#include <fstream>
#include <iomanip>

unsigned long long swap_counter = 0;

void swap(unsigned &lhv, unsigned &rhv);
void print_arr(unsigned arr[], unsigned n);
bool brush_N(unsigned arr[], unsigned const size, unsigned const N);
void brush_sort(unsigned arr[], unsigned const size);
void bubble_sort(unsigned arr[], unsigned const size);

unsigned* create_random_array(unsigned n, std::default_random_engine &rng);
unsigned* copy_array(unsigned* arr, unsigned n);

double test_brush_sort(unsigned n, std::default_random_engine &rng, long long &swaps);
void time_test_brush_sort(int ns[], int size_ns, int m, unsigned seed);

int main()
{
    {
        unsigned arr[] = {5, 1, 4, 2, 8};
        brush_sort(arr, 5);
        print_arr(arr, 5);
    }

    {
        int ns[] = {100, 200, 500, 1000, 2000, 5000, 10000};
        int size_ns = sizeof(ns) / sizeof(ns[0]);

        // количество повторов для усреднения
        int m = 10;
        unsigned seed = 52;

        time_test_brush_sort(ns, size_ns, m, seed);
    }
    return 0;
}

void swap(unsigned &lhv, unsigned &rhv)
{
    unsigned tmp = lhv;
    lhv = rhv;
    rhv = tmp;
    swap_counter++; // добавляем счетчик, чтобы считать кол-во замен по заданию
}

void print_arr(unsigned arr[], unsigned n)
{
    for (unsigned i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

bool brush_N(unsigned arr[], unsigned const size, unsigned const N)
{
    // flag=true - если не отсортирован
    bool flag = false;
    for (unsigned idx = 0; idx + N < size; idx++)
    {
        if (arr[idx] > arr[idx + N])
        {
            swap(arr[idx], arr[idx + N]);
            flag = true;
        }
    }
    return flag;
}

void brush_sort(unsigned arr[], unsigned const size)
{
    unsigned N = size / 2;
    while (N > 1)
    {
        /* по условию нужно проверить 1 раз,
        а не до стабилизации по N/2^k элментам*/
        // bool flag = true;
        // while (flag){
        //     flag = brush_N(arr, size, N);
        // }
        brush_N(arr, size, N); // 1 шаг оптимизации
        N = N / 2;
    }
    while (brush_N(arr, size, 1))
        ; // реализация bubble_sort через brush_N
}

// формально лучше использовать данную реализацию, т.к. не n^2 проходов, а n^2/2
void bubble_sort(unsigned arr[], unsigned const size)
{
    for (unsigned i = 0; i < size; i++)
    {
        for (unsigned j = 0; j + 1 < size - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

unsigned *create_random_array(unsigned n, std::default_random_engine &rng)
{
    unsigned *arr = new unsigned[n];
    std::uniform_int_distribution<unsigned> d(0, n - 1);

    for (unsigned i = 0; i < n; i++)
        arr[i] = d(rng);

    return arr;
}

unsigned *copy_array(unsigned *arr, unsigned n)
{
    unsigned *copy = new unsigned[n];
    for (unsigned i = 0; i < n; i++)
        copy[i] = arr[i];
    return copy;
}

double test_brush_sort(unsigned n, std::default_random_engine &rng, long long &swaps)
{
    unsigned *arr = create_random_array(n, rng);
    swap_counter = 0;

    auto begin = std::chrono::steady_clock::now();
    brush_sort(arr, n);
    auto end = std::chrono::steady_clock::now();
    auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    swaps = swap_counter;

    delete[] arr;

    return time_span.count();
}

void time_test_brush_sort(int ns[], int size_ns, int m, unsigned seed)
{
    std::default_random_engine rng(seed);
    std::ofstream file("./lab2-cpp/csv/brush_sort.csv");

    file << "n,t_ns,swaps\n";
    file << std::scientific;
    file.precision(10);
    for (int i = 0; i < size_ns; i++)
    {
        for (int j = 0; j < m; j++)
        {
            long long swaps = 0;

            auto time_span = test_brush_sort(ns[i], rng, swaps);

            file << ns[i] << "," << time_span << "," << swaps << "\n"; //*,* - *coloms* separated values = csv
        }
    }

    file.close();
}

