#include <iostream>
#include <random>
#include <chrono>
#include <fstream>
#include <iomanip>
/*доп задача: итерировать shell sort по списку*/

void swap(unsigned &lhv, unsigned &rhv);
unsigned *create_random_array(unsigned n, std::default_random_engine &rng);
unsigned *copy_array(unsigned *arr, unsigned n);
void reverse_arr(int *arr, int size);

int *gen_i_shell_sort(int size, int &size_i);
int find_hibbard_i(int n);
int *gen_i_shell_hibbard_sort(int size, int &size_i);
int *gen_i_shell_fibonacci_sort(int size, int &size_i);

void union_shell_sort(unsigned *array, int size, int *i_vals, int size_i);
double test_sort(unsigned n, std::default_random_engine &rng, long long &swaps,
                 int* (*gen_func)(int, int&));
void time_test_sort(int ns[], int size_ns, int m, unsigned seed,
                    int* (*gen_func)(int, int&), const std::string &filename);

long long unsigned swap_counter = 0;

int main()
{
    int ns[] = {100, 112, 126, 142, 159, 179, 201, 226, 254, 285, 320, 359, 404, 453, 509, 572, 643, 722, 811, 911, 1024, 1150, 1292, 1451, 1630, 1831, 2057, 2310, 2595, 2915, 3275, 3678, 4132, 4642, 5214, 5857, 6579, 7391, 8302, 9326, 10476, 11768, 13219, 14850, 16681, 18738, 21049, 23645, 26561, 29836, 33516, 37649, 42292, 47508, 53367, 59948, 67342, 75646, 84975, 95455, 107227, 120450, 135305, 151991, 170735, 191791, 215443, 242013, 271859, 305386, 343047, 385353, 432876, 486260, 546228, 613591, 689261, 774264, 869749, 977010, 1097499, 1232847, 1384886, 1555676, 1747528, 1963041, 2205131, 2477076, 2782559, 3125716, 3511192, 3944206, 4430621, 4977024, 5590810, 6280291, 7054802, 7924829, 8902151, 10000000};
    int size_ns = sizeof(ns) / sizeof(ns[0]);
    int m = 10;
    unsigned seed = 52;

    // 1. s_{i+1} = s_i/2
    time_test_sort(ns, size_ns, m, seed, gen_i_shell_sort, "./lab2-cpp/csv/shell_sort_l.csv");
    // 2. последовательность Хиббарта s_i = 2^i-1
    time_test_sort(ns, size_ns, m, seed, gen_i_shell_hibbard_sort, "./lab2-cpp/csv/shell_hibbard_sort_l.csv");
    // 3. последовательность Фиббоначи
    time_test_sort(ns, size_ns, m, seed, gen_i_shell_fibonacci_sort, "./lab2-cpp/csv/shell_fibonacci_sort_l.csv");

    return 0;
}

void swap(unsigned &lhv, unsigned &rhv)
{
    unsigned tmp = lhv;
    lhv = rhv;
    rhv = tmp;
    swap_counter++;
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

// 
/****************************************************************************/
// *доп задание*

/* // void half_generate_i_vals(int size, size, unsigned &*i_vals, int &size_i)
// {
//     i_vals[0] = size / 2 for (int idx = 1; idx < size_ns; ++idx)
//     {
//         i_vals[i] = i_vals
//     }
// } // какой-то набросок, жаль удалять */

void reverse_arr(int *arr, int size) {
    for (int idx = 0; idx < size / 2; ++idx) {
        int tmp = arr[idx];
        arr[idx] = arr[size - 1 - idx];
        arr[size - 1 - idx] = tmp;
    }
}

/* функции для генерации массива size_i согласно правилам,
 которые затем будут подавться в union_shell_sort */

// 1. s_{i+1} = s_i/2
int *gen_i_shell_sort(int size, int &size_i)
{
    // Подсчёт количества шагов
    size_i = 0;
    for (int s = size / 2; s > 0; s /= 2)
    {
        size_i++;
    }

    int *i_vals = new int[size_i];
    int idx = 0;
    for (int s = size / 2; s > 0; s /= 2)
    {
        i_vals[idx++] = s;
    }
    return i_vals;
}
// 2. последовательность Хиббарта s_i = 2^i-1
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

int *gen_i_shell_hibbard_sort(int size, int &size_i)
{
    size_i = find_hibbard_i(size);
    int *i_vals = new int[size_i];

    int pow2 = 2;
    for (int idx = 0; idx < size_i; idx++)
    {
        i_vals[idx] = pow2 - 1;
        pow2 *= 2;
    }

    reverse_arr(i_vals, size_i);

    return i_vals;
}

// 3. последовательность Фиббоначи
int* gen_i_shell_fibonacci_sort(int size, int& size_i) {
    if (size <= 1) {
        size_i = 0;
        return nullptr;
    }

    int* fib_all = new int[size];
    int count = 0;
    
    fib_all[count++] = 1;
    fib_all[count++] = 1;
    
    while (true) {
        int next = fib_all[count - 1] + fib_all[count - 2];
        if (next > size)
            break;
        fib_all[count++] = next;
    }
    
    size_i = count;
    int* i_vals = new int[size_i];
    
    int s = fib_all[count - 1];
    int s_next = fib_all[count - 2];
    int idx = 0;
    
    while (s > 0) {
        i_vals[idx++] = s;
        if (s == 1)
            break;
        int tmp = s_next;
        int tmp_next = s - s_next;
        s = tmp;
        s_next = tmp_next;
    }
    
    delete[] fib_all;
    return i_vals;
}

/**********************************************/
void union_shell_sort(unsigned *array, int size, int *i_vals, int size_i)
{
    // итераци по списку i_vals
    for (int idx = 0; idx < size_i; ++idx)
    {
        int s = i_vals[idx];
        for (int i = s; i < size; ++i)
        {
            for (int j = i - s; j >= 0 && array[j] > array[j + s]; j -= s)
            {
                swap(array[j], array[j + s]);
            }
        }
    }
}

double test_sort(unsigned n, std::default_random_engine &rng, long long &swaps,
                 int* (*gen_func)(int, int&))
{
    unsigned *arr = create_random_array(n, rng);
    swap_counter = 0;

    // Генерируем последовательность шагов s
    int size_i = 0;
    int* s = gen_func(n, size_i);

    auto begin = std::chrono::steady_clock::now();
    union_shell_sort(arr, n, s, size_i);
    auto end = std::chrono::steady_clock::now();

    auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    swaps = swap_counter;

    delete[] arr;
    delete[] s;
    return time_span.count();
}

void time_test_sort(int ns[], int size_ns, int m, unsigned seed,
                    int* (*gen_i)(int, int&), const std::string &filename)
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
            double time_ns = test_sort(ns[i], rng, swaps, gen_i);
            file << ns[i] << "," << time_ns << "," << swaps << "\n";
        }
    }

    file.close();
}