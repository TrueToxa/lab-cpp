#include <iostream>
#include <random>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <string>

using std::cout;
using std::endl;
using std::string;

// Задаем N - кол-во элементов в массиве, при компиляции 
// постфактум не используется
#ifndef N
#define N 10
#endif
// Задаем M - кол-во повторений для усреднения
#ifndef M
#define M 10
#endif
// Задаем K - кол-во повторений для усреднения одного измерения 
// (затем в коде нормируем на размер массива, чтобы быстрее работало)
// нивелирует очередь в планировщике ОС
#ifndef K
#define K 100000
#endif

// Предварительные объявления функций
int * create_array(int n=N);
int * create_random_array(int n, std::default_random_engine& rng);
int find_num_in_array(int *array, int n, int num);
int find_num_in_sorted_array(int *array, int n, int num);
void time_test_find_num_in_array(int ns[], int size_ns, int m, unsigned seed);
void time_test_find_num_in_sorted_array(int ns[], int size_ns, int m, unsigned seed);
void write_file(int n_values[], double times[], int size, std::string filename);

bool find_pair_with_sum(int *array, int n, int sum);
bool find_pair_with_sum_in_sorted_array(int *array, int n, int sum);
void time_test_find_pair_with_sum(int ns[], int size_ns, int m, unsigned seed);
void time_test_find_pair_with_sum_in_sorted_array(int ns[], int size_ns, int m, unsigned seed);

bool find_O (int *array, int n, int num, int *counter=nullptr);
bool find_A (int *array, int n, int num, int *counter=nullptr);
bool find_B (int *array, int n, int num, int *counter=nullptr);
bool find_C (int *array, int n, int num, int *counter=nullptr);

int parabolic_transform(int x, int n);
int id_transform(int x, int n);
int * create_random_array_with_transformed_uniform(int n, std::default_random_engine& rng, int (* transform)(int, int));

void time_test (int ns[], 
        int size_ns, 
        int m, 
        unsigned seed, 
        bool find_X(int*, int, int, int*), 
        bool data_uniform = true,
        bool request_uniform = true,
        string file_name = "time_test_1_example.csv");


/*****************************************************************************************************/
int main() {
    int ns[6] = {314, 1000, 3141, 10000, 31415, 100000}; // измеряемые длины массивов
    int size_ns = 6;
    unsigned seed = 52;

    // поиск числа
    // time_test_find_num_in_array(ns, size_ns, M, seed);
    // time_test_find_num_in_sorted_array(ns, size_ns, M, seed);

    // поиск суммы
    // time_test_find_pair_with_sum(ns, size_ns, M, seed);
    // time_test_find_pair_with_sum_in_sorted_array(ns, size_ns, M, seed);
    
    //1
    
    time_test (ns, size_ns, M, seed, find_A, true, true, "A11.csv");
    time_test (ns, size_ns, M, seed, find_B, true, true, "B11.csv");
    time_test (ns, size_ns, M, seed, find_C, true, true, "C11.csv");
    time_test (ns, size_ns, M, seed, find_O, true, true, "O11.csv");

    //2
    
    time_test (ns, size_ns, M, seed, find_A, true, false, "A10.csv");
    time_test (ns, size_ns, M, seed, find_B, true, false, "B10.csv");
    time_test (ns, size_ns, M, seed, find_C, true, false, "C10.csv");
    time_test (ns, size_ns, M, seed, find_O, true, false, "O10.csv");

    //3
    
    time_test (ns, size_ns, M, seed, find_A, false, true, "A01.csv");
    time_test (ns, size_ns, M, seed, find_B, false, true, "B01.csv");
    time_test (ns, size_ns, M, seed, find_C, false, true, "C01.csv");
    time_test (ns, size_ns, M, seed, find_O, false, true, "O01.csv");

    //false, false - возвращает равномерное распределение запросов по данным
    return 0;
}

void swap(int& lhv, int& rhv){
    int tmp = lhv;
    lhv = rhv;
    rhv = tmp;
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
                num = static_cast<int>(dstr(rng));
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

// если хотим возвращать индексы:
// bool find_pair_with_sum(int *array, int n, int sum, int &i, int &j) 
// записываем в i, j
bool find_pair_with_sum(int *array, int n, int sum) {
    /*
    рефлизует нахождение элементов, 
    сумма которых равна заданной
    методом полного перебора
    */
    
    for (int i=0; i<n; ++i) {
        for (int j=i+1; j<n; ++j) {
            if (array[i]+array[j]==sum) {
                return true;
            }
        }
    }

    return false;
}

bool find_pair_with_sum_in_sorted_array(int *array, int n, int sum) {
    /*
    рефлизует нахождение элементов 
    отсортированного массива, 
    сумма которых равна заданной
    */
    int left = 0;
    int right = n - 1;
    
    while (left < right) {
        int sum_lr = array[left] + array[right];
        
        if (sum_lr == sum) {
            return true;
        } else if (sum_lr < sum) {
            left++;
        } else {
            right--;
        }
    }
    
    return false;
}

void time_test_find_pair_with_sum(int ns[], int size_ns, int m, unsigned seed) {
    // реализует тестирование времени работы функции линейного поиска и сохраняет результаты в файл
    std::default_random_engine rng(seed);

    int size = size_ns * (m + 1); // общее количество измерений
    double *times = new double[size];
    int *n_values = new int[size];

    for (int i = 0; i < size_ns; ++i) {
        int *arr = create_random_array(ns[i], rng);

        std::uniform_int_distribution<unsigned> dstr(0, ns[i]*2); //*2
        
        std::cout << ns[i] << std::endl;
        for (int j = 0; j <= m; ++j) {
            int sum;
            if (j == 0) {
                sum = -1; // нет отрицательной суммы
            } else {
                sum = static_cast<int>(dstr(rng));
            }

            // измеряем k раз
            auto begin = std::chrono::steady_clock::now();
            for (int k = 0; k < K/ns[i]; ++k) {
                find_pair_with_sum(arr, ns[i], sum);
            }
            auto end = std::chrono::steady_clock::now();
            auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
            
            times[i * (m + 1) + j] = time_span.count()/(K/ns[i]);
            n_values[i * (m + 1) + j] = ns[i];
        }

        delete[] arr;
    }

    write_file(n_values, times, size, "./lab1-cpp/csv/find_pair_with_sum.csv");

    delete[] times;
    delete[] n_values;
}

void time_test_find_pair_with_sum_in_sorted_array(int ns[], int size_ns, int m, unsigned seed) {
    // реализует тестирование времени работы полного перебора
    std::default_random_engine rng(seed);

    int size = size_ns * (m + 1); // общее количество измерений
    double *times = new double[size];
    int *n_values = new int[size];

    for (int i = 0; i < size_ns; ++i) {
        int *arr = create_array(ns[i]); 
        for (int idx = 0; idx < ns[i]; ++idx) {
            arr[idx] = idx + 1; 
        }

        std::uniform_int_distribution<unsigned> dstr(1, ns[i]*2);

        std::cout << ns[i] << std::endl;
        for (int j = 0; j <= m; ++j) {
            int sum;
            if (j == 0) {
                // наихудший случай
                sum = -1;
            } else {
                // случайная сумма
                sum = static_cast<int>(dstr(rng));
            }

            auto begin = std::chrono::steady_clock::now();
            for (int k = 0; k < (K / ns[i]); ++k) {
                find_pair_with_sum_in_sorted_array(arr, ns[i], sum);
            }
            auto end = std::chrono::steady_clock::now();
            auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

            times[i * (m + 1) + j] = time_span.count() / static_cast<double>(K / ns[i]); 
            n_values[i * (m + 1) + j] = ns[i];
        }

        delete[] arr;
    }

    write_file(n_values, times, size, "./lab1-cpp/csv/find_pair_with_sum_in_sorted_array.csv");

    delete[] times;
    delete[] n_values;
}

bool find_O (int *array, int n, int num, int *counter) {
    // int idx_n = -1;
    for (int idx = 0; idx < n; ++idx) {
        if (num == array[idx]) {
            return true;
            break;
        }
    }
    return false;
}

bool find_A (int *array, int n, int num, int *counter) {
    // int num_idx = -1;
    for (int idx = 0; idx < n; ++idx) {
        if (num == array[idx]) {
            // num_idx = idx;
            if (idx>=1) {
                swap(array[0], array[idx]);
            }
            return true;
            break; //по сути не нужно
        }
    }
    return false;
}

bool find_B (int *array, int n, int num, int *counter) {
    // int num_idx = -1;
    for (int idx = 0; idx < n; ++idx) {
        if (num == array[idx]) {
            // num_idx = idx;
            if (idx>=1) {
                swap(array[idx-1], array[idx]);
            } 
            return true;
            break;
        }
    }
    return false;
}

bool find_C (int *array, int n, int num,  int *counter) {
    // int num_idx = -1;
    for (int idx = 0; idx < n; ++idx) {
        if (num == array[idx]) {
            // num_idx = idx;
            counter[idx] += 1; 
            if (idx>=1 and counter[idx-1] < counter[idx]) {
                swap(array[idx-1], array[idx]);
                swap(counter[idx-1], counter[idx]);
            } 
            return true;
            break;
        }
    }
    return false;
}


int parabolic_transform(int x, int n) {
    /* x - равномерно-случайное число от 0 до n-1
    применяя неравномерное преобразование к функции распределения,
    получим неравномерное распределение

    используется фиксированная на концах парабола, 
    x: [0, n-1] |--> [0, n-1]
    распределение смещено к 0
    */

    return static_cast<int>((n - 1) - (static_cast<double>(x) * x) / (n - 1));


}

int id_transform(int x, int n) {
    return x;
}

int * create_random_array_with_transformed_uniform(int n, std::default_random_engine& rng, int (* transform)(int, int)) {
    int * array = new int[n];
    std::uniform_int_distribution<unsigned> dstr(0, n-1);
    for (int idx = 0; idx < n; ++idx){
        array[idx] = transform(dstr(rng), n);
    }
    return array;
}

void time_test (int ns[], 
        int size_ns, 
        int m, 
        unsigned seed, 
        bool find_X(int*, int, int, int*), 
        bool data_uniform,
        bool request_uniform,
        string file_name) 
{
    /* 
    реализует тестирование времени работы функции оптимизированнного поиска
    в качестве одного из аргументов принимает саму функцию поиска из A, B, C
    Для удобства, в сигнатуре find_AB также как в find_C ввели массив counter
    
    реализация полностью аналогично тестированию для линейного поиска, 
    поэтому можно использовать результаты оттуда для сравнения
    */

    
    std::default_random_engine rng(seed);

    int size = size_ns * (m + 1); // общее количество измерений
    double *times = new double[size];
    int *n_values = new int[size];
    

    for (int i = 0; i < size_ns; ++i) {
        std::cout << '\n' << "n=" << ns[i] << std::endl;
        // (не)равномерное распределение данных, по которым ведется поиск 
        int *arr = nullptr;
        if (data_uniform) {
            arr = create_random_array_with_transformed_uniform(ns[i], rng, id_transform);
        } else {
            arr = create_random_array_with_transformed_uniform(ns[i], rng, parabolic_transform);
        }
        
        int *counter = new int[ns[i]]{}; 

        std::uniform_int_distribution<unsigned> dstr(0, ns[i]-1);

        for (int j = 0; j <= m; ++j) {
            if (j%(m/10)==0) {
                std::cout << static_cast<int>(static_cast<double>(j)/m*1*10);;
            }
            
            // измеряем k раз, но теперь для различных входных значений
            // т.е. не рассматриваем влияние вариаций из-за планировщика ОС
            auto begin = std::chrono::steady_clock::now();

            for (int k = 0; k < K; ++k) {
                int num;

                if (request_uniform) {
                    num = id_transform(static_cast<int>(dstr(rng)), ns[i]); //равномерные запросы
                } else {
                    num = parabolic_transform(static_cast<int>(dstr(rng)), ns[i]); //неравномерные
                }

                find_X(arr, ns[i], num, counter);
            }
            auto end = std::chrono::steady_clock::now();
            auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
            
            times[i * (m + 1) + j] = time_span.count()/(K);
            n_values[i * (m + 1) + j] = ns[i];
        }
        delete[] arr;
        delete[] counter;
    }

    write_file(n_values, times, size, "./lab1-cpp/csv/"+file_name);

    delete[] times;
    delete[] n_values;
}
