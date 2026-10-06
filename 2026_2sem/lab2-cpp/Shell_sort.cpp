#include <iostream>
#include <random>
#include <chrono>
#include <fstream>
#include <iomanip>

void swap(unsigned &lhv, unsigned &rhv);
void shell_sort(unsigned *array, int size);
void shell_hibbard_sort(unsigned *array, int size);
void shell_fibonacci_sort(unsigned *array, int size);
unsigned *create_random_array(unsigned n, std::default_random_engine &rng);
unsigned *copy_array(unsigned *arr, unsigned n);
double test_sort(unsigned n, std::default_random_engine &rng, long long &swaps,
                 void (*sort_func)(unsigned *, int));
void time_test_sort(int ns[], int size_ns, int m, unsigned seed,
                    void (*sort_func)(unsigned *, int), const std::string &filename);

long long unsigned swap_counter = 0;

int main()
{

    int ns[] = { 100, 112, 126, 142, 159, 179, 201, 226, 254, 285, 320, 359, 404, 453, 509, 572, 643, 722, 811, 911, 1024, 1150, 1292, 1451, 1630, 1831, 2057, 2310, 2595, 2915, 3275, 3678, 4132, 4642, 5214, 5857, 6579, 7391, 8302, 9326, 10476, 11768, 13219, 14850, 16681, 18738, 21049, 23645, 26561, 29836, 33516, 37649, 42292, 47508, 53367, 59948, 67342, 75646, 84975, 95455, 107227, 120450, 135305, 151991, 170735, 191791, 215443, 242013, 271859, 305386, 343047, 385353, 432876, 486260, 546228, 613591, 689261, 774264, 869749, 977010, 1097499, 1232847, 1384886, 1555676, 1747528, 1963041, 2205131, 2477076, 2782559, 3125716, 3511192, 3944206, 4430621, 4977024, 5590810, 6280291, 7054802, 7924829, 8902151, 10000000 };
    int size_ns = sizeof(ns) / sizeof(ns[0]);
    int m = 10;
    unsigned seed = 52;

    // 1. s_{i+1} = s_i/2
    time_test_sort(ns, size_ns, m, seed, shell_sort, "./lab2-cpp/csv/shell_sort.csv");
    // 2. последовательность Хиббарта s_i = 2^i-1
    time_test_sort(ns, size_ns, m, seed, shell_hibbard_sort, "./lab2-cpp/csv/shell_hibbard_sort.csv");
    // 3. последовательность Фиббоначи
    time_test_sort(ns, size_ns, m, seed, shell_fibonacci_sort, "./lab2-cpp/csv/shell_fibonacci_sort.csv");

    return 0;
}

void swap(unsigned &lhv, unsigned &rhv)
{
    unsigned tmp = lhv;
    lhv = rhv;
    rhv = tmp;
    swap_counter++;
}

// 1. s_{i+1} = s_i/2
void shell_sort(unsigned *array, int size)
{
    for (int s = size / 2; s > 0; s /= 2)
    {
        for (int i = s; i < size; ++i)
        {
            for (int j = i - s; j >= 0 && array[j] > array[j + s]; j -= s)
            {
                swap(array[j], array[j + s]);
            }
        }
    }
}

int find_hibbard_i(int n)
{
    int i = 0;
    int pow2i = 1;
    while (true)
    {
        pow2i = pow2i * 2;
        if (pow2i - 1 > n)
        {
            return i;
        }
        i++;
    }
}

// 2. последовательность Хиббарта s_i = 2^i-1
void shell_hibbard_sort(unsigned *array, int size)
{
    int i = find_hibbard_i(size);
    int s0 = 1;
    for (int idx = 0; idx < i; idx++)
    {
        s0 = s0 * 2;
    }
    s0 = s0 - 1;

    for (int s = s0; s > 0; s = (s + 1) / 2 - 1)
    {
        for (int i = s; i < size; ++i)
        {
            for (int j = i - s; j >= 0 && array[j] > array[j + s]; j -= s)
            {
                swap(array[j], array[j + s]);
            }
        }
    }
}

// 3. последовательность Фиббоначи
void shell_fibonacci_sort(unsigned *array, int size)
{
    if (size <= 1)
        return;

    // Находим два наибольших числа Фибоначчи
    int fib_prev = 1; // F_{k-1}
    int fib_curr = 1; // F_k
    while (fib_curr <= size)
    {
        int next = fib_prev + fib_curr;
        if (next > size)
            break;
        fib_prev = fib_curr;
        fib_curr = next;
    }

    int s = fib_curr;
    int s_next = fib_prev;

    while (s > 0)
    {
        for (int i = s; i < size; ++i)
        {
            for (int j = i - s; j >= 0 && array[j] > array[j + s]; j -= s)
            {
                swap(array[j], array[j + s]);
            }
        }

        if (s == 1)
            break;
        int tmp = s_next;
        int tmp_next = s - s_next;
        s = tmp;
        s_next = tmp_next;
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

double test_sort(unsigned n, std::default_random_engine &rng, long long &swaps,
                 void (*sort_func)(unsigned *, int))
{
    unsigned *arr = create_random_array(n, rng);
    swap_counter = 0;

    auto begin = std::chrono::steady_clock::now();
    sort_func(arr, n);
    auto end = std::chrono::steady_clock::now();

    auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    swaps = swap_counter;

    delete[] arr;
    return time_span.count();
}

void time_test_sort(int ns[], int size_ns, int m, unsigned seed,
                    void (*sort_func)(unsigned *, int), const std::string &filename)
{
    std::default_random_engine rng(seed);
    std::ofstream file(filename);

    file << "n,t_ns,swaps\n";
    file << std::scientific;
    file.precision(10);

    for (int i = 0; i < size_ns; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            long long swaps = 0;
            double time_ns = test_sort(ns[i], rng, swaps, sort_func);
            file << ns[i] << "," << time_ns << "," << swaps << "\n";
        }
    }

    file.close();
}