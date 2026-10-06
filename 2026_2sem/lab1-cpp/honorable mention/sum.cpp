#include <iostream>
#include <random>
#include <chrono>
#include <fstream>
#include <iomanip>

using std::cout;
using std::endl;

// Задаем N - кол-во элементов в массиве, при компиляции 
// постфактум не используется
#ifndef N
#define N 10
#endif
// Задаем M - кол-во повторений для усреднения
#ifndef M
#define M 100
#endif
// Задаем K - кол-во повторений для усреднения одного измерения 
// (затем в коде нормируем на размер массива, чтобы быстрее работало)
// нивелирует очередь в планировщике ОС
#ifndef K
#define K 100'000'000
#endif

// Предварительные объявления функций
int * create_array(int n=N);
int * create_random_array(int n, std::default_random_engine& rng);
int find_num_in_array(int *array, int n, int num);
int find_num_in_sorted_array(int *array, int n, int num);
void time_test_find_num_in_array(int ns[], int size_ns, int m, unsigned seed);
void time_test_find_num_in_sorted_array(int ns[], int size_ns, int m, unsigned seed);
void write_file(int n_values[], double times[], int size, std::string filename);

int main() {
    int ns[8] = {500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000}; // измеряемые длины массивов
    int size_ns = 8;
    unsigned seed = 52;

    time_test_find_num_in_array(ns, size_ns, M, seed);
    time_test_find_num_in_sorted_array(ns, size_ns, M, seed);

    return 0;
}

int * create_random_array(int n, std::default_random_engine& rng) {
    int * array = new int[n];
    std::uniform_int_distribution<unsigned> dstr(0, n-1);
    for (int idx = 0; idx < n; ++idx){
        array[idx] = dstr(rng);
    }
    return array;
}

int * create_array(int n) {
    int * array = new int[n];
    return array;
}

int find_num_in_array(int *array, int n, int num) {
    /* реализует алгоритм линейного поиска
       принимает на вход число num и массив array размера n
       возвращает индекс первого вхождения элемента num 
       если не найден - возвращает -1 */
    int idx_n = -1;
    for (int idx = 0; idx < n; ++idx) {
        if (num == array[idx]) {
            idx_n = idx;
            break;
        }
    }
    return idx_n;
}

int find_num_in_sorted_array(int *array, int n, int num) {
    /* Реализует алгоритм бинарного поиска
       принимает на вход число num и сортированный массив array размера n
       возвращает индекс первого вхождения элемента num,
       если не найден - возвращает -1 */
    int left = 0;
    int right = n - 1;
    
    while (left <= right) {
        int idx = left + (right - left) / 2;
        
        if (array[idx] == num) {
            return idx;
        } else if (array[idx] < num) {
            left = idx + 1;
        } else {
            right = idx - 1;
        }
    }
    
    return -1;
}

void time_test_find_num_in_sorted_array(int ns[], int size_ns, int m, unsigned seed) {
    // реализует тестирование времени работы бинарного поиска в упорядоченном массиве
    std::default_random_engine rng(seed);

    int size = size_ns * (m + 1); // общее количество измерений
    double *times = new double[size];
    int *n_values = new int[size];

    for (int i = 0; i < size_ns; ++i) {
        int *arr = create_array(ns[i]); 
        for (int idx = 0; idx < ns[i]; ++idx) {
            arr[idx] = idx + 1; 
        }

        std::uniform_int_distribution<unsigned> dstr(1, ns[i]);

        for (int j = 0; j <= m; ++j) {
            int num;
            if (j == 0) {
                // наихудший случай
                num = 0;
            } else {
                // случайный элемент из массива
                int num = static_cast<int>(dstr(rng));
            }

            auto begin = std::chrono::steady_clock::now();
            for (int k = 0; k < (K / ns[i]); ++k) {
                find_num_in_sorted_array(arr, ns[i], num);
            }
            auto end = std::chrono::steady_clock::now();
            auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

            times[i * (m + 1) + j] = time_span.count() / static_cast<double>(K / ns[i]); 
            n_values[i * (m + 1) + j] = ns[i];
        }

        delete[] arr;
    }

    write_file(n_values, times, size, "./lab1-cpp/csv/find_num_in_sorted_array.csv");

    delete[] times;
    delete[] n_values;
}


void time_test_find_num_in_array(int ns[], int size_ns, int m, unsigned seed) {
    // реализует тестирование времени работы функции линейного поиска и сохраняет результаты в файл
    std::default_random_engine rng(seed);

    int size = size_ns * (m + 1); // общее количество измерений
    double *times = new double[size];
    int *n_values = new int[size];

    for (int i = 0; i < size_ns; ++i) {
        int *arr = create_random_array(ns[i], rng);

        std::uniform_int_distribution<unsigned> dstr(0, ns[i]-1);

        for (int j = 0; j <= m; ++j) {
            int num;
            if (j == 0) {
                num = ns[i]; // нет в массиве
            } else {
                num = static_cast<int>(dstr(rng));
            }

            // измеряем k раз
            auto begin = std::chrono::steady_clock::now();
            for (int k = 0; k < K/ns[i]; ++k) {
                find_num_in_array(arr, ns[i], num);
            }
            auto end = std::chrono::steady_clock::now();
            auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
            
            times[i * (m + 1) + j] = time_span.count()/(K/ns[i]);
            n_values[i * (m + 1) + j] = ns[i];
        }

        delete[] arr;
    }

    write_file(n_values, times, size, "./lab1-cpp/csv/find_num_in_array.csv");

    delete[] times;
    delete[] n_values;
}

void write_file(int n_values[], double times[], int size, std::string filename) {
    /*
    функция записи данных в filename.csv в заданном формате:
    n;      t_ns
    100;    52.523e0
    ...
    */ 
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла\n";
        return;
    }

    file << "n;t_ns\n";

    // форматный вывод
    file << std::scientific << std::setprecision(3);

    for (int i = 0; i < size; ++i) {
        file << n_values[i] << ";" << times[i] << "\n";
    }

    file.close();
}
