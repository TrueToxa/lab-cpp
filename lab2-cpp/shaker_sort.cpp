#include <iostream>
#include <random>

void swap(unsigned &lhv, unsigned &rhv);
void print_arr(unsigned arr[], unsigned n);
void fill_random(unsigned arr[], int n, std::default_random_engine& rng);
void forward_step(
    unsigned arr[],
    unsigned const begin_idx, unsigned const end_idx);
void backward_step(
    unsigned arr[],
    unsigned const begin_idx, unsigned const end_idx);
void shaker_sort(
    unsigned arr[],
    unsigned const begin_idx, unsigned const end_idx);


int main()
{
    {
        unsigned arr[] = {5, 1, 4, 2, 8};
        print_arr(arr, 5);
    }
    int seed = 52;
    int n = 5;
    {   
        std::default_random_engine rng(seed);
        unsigned arr[n];
        fill_random(arr, n, rng);
        print_arr(arr, 5);
    }
    {
        std::default_random_engine rng(seed);
        unsigned arr[n];
        fill_random(arr, n, rng);
        forward_step(arr, 0, 4);
        print_arr(arr, 5);
    }

    {
        std::default_random_engine rng(seed);
        unsigned arr[n];
        fill_random(arr, n, rng);
        backward_step(arr, 0, 4);
        print_arr(arr, 5);
    }

    {
        std::default_random_engine rng(seed);
        unsigned arr[n];
        fill_random(arr, n, rng);
        shaker_sort(arr, 0, 4);
        print_arr(arr, 5);
    }
}

void forward_step(
    unsigned arr[],
    unsigned const begin_idx, unsigned const end_idx)
{
    for (unsigned idx = begin_idx; idx <= end_idx - 1; idx++)
    {
        if (arr[idx] > arr[idx + 1])
        {
            swap(arr[idx], arr[idx + 1]);
        }
    }
}

void backward_step(
    unsigned arr[],
    unsigned const begin_idx, unsigned const end_idx)
{
    for (unsigned idx = end_idx; idx > begin_idx; idx--)
    {
        if (arr[idx] < arr[idx - 1])
        {
            swap(arr[idx], arr[idx - 1]);
        }
    }
}

void shaker_sort(
    unsigned arr[],
    unsigned const begin_idx, unsigned const end_idx)
{
    unsigned left = begin_idx;
    unsigned right = end_idx;

    while (left < right)
    {
        forward_step(arr, left, right);
        right--;

        backward_step(arr, left, right);
        left++;
    }
}

void print_arr(unsigned arr[], unsigned n)
{
    for (unsigned i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

void swap(unsigned &lhv, unsigned &rhv)
{
    unsigned tmp = lhv;
    lhv = rhv;
    rhv = tmp;
}

void fill_random(unsigned arr[], int n, std::default_random_engine& rng)
{
    std::uniform_int_distribution<unsigned> d(0, n*2 - 1);

    for (int i = 0; i < n; i++)
        arr[i] = d(rng);
}