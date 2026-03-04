#include <iostream>
#include <random>
#include <chrono>
#include <fstream>
#include <iomanip>

using std::cout;
using std::endl;

// Задаем N - кол-во элементов в массиве, при компиляции
#ifndef N
#define N 10
#endif
// Задаем M - кол-во повторений для усреднения
#ifndef M
#define M 10
#endif

int * create_array(int n=N);
int * create_random_array(int n=N, std::default_random_engine& rng);
int find_num_in_array(int *array, int n=N, int num);
int find_num_in_array(int *array, int n=N, int num);

int main() {
    // Инициализируем таймер
    auto begin = std::chrono::steady_clock::now();

    unsigned seed = 0;
    std::default_random_engine rng(seed);
    int *first = create_array(1'000);
    int *random0 = create_random_array(100, rng);
    int *random1 = create_random_array(100, rng);
    for (unsigned idx = 0; idx < 100; ++idx){
        cout << idx << ": " << (random0[idx] == random1[idx]) << endl;
    }

    // Выводим время работы программы
    auto end = std::chrono::steady_clock::now();
    auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "\n\n";
    std::cout << time_span.count() << std::endl;
    return 52;
}

int * create_array(int n) {
    // double array[N];
    int * array = new int[n];
    return array;
}

int * create_random_array(int n, std::default_random_engine& rng) { 
    //убрать имперсант, чтобы одинаковый сид
    // unsigned seed = 1001;
    // std::default_random_engine rng(seed);
    int array[n];
    std::uniform_int_distribution<unsigned> dstr(0, 999);
    for (int idx = 0; idx < n; ++idx){
        array[idx] = dstr(rng);
    }
    return array;
}

int find_num_in_array(int *array, int n, int num) {
    /* принимет на вход число num и массив array размера n
    возращает индекс первого вхождения элемента num 
    если не найден - возвращает -1*/
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
    /* принимет на вход число num и сортированный массив array размера n
    возращает индекс первого вхождения элемента num,
    если не найде - возращает -1 */

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

void time_test_find_num_in_array(int m, int n, unsigned seed) {
    std::default_random_engine rng(seed);
    int * array = create_random_array(n, rng);
    

}

void write_file_example() { 
    std::ofstream file("example.csv", std::ios::out); 
    // зн. по ум. - std::ios::out - очищает файл при открытии
    // если нужно дописывать - std::ios::app

    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла\n";
        return 1;
    }

    file << "n;t_ms\n";

    // форматный вывод (если необходимо)
    // file << std::fixed << std::setprecision(2);

    int size = 5; 
    int n_values[] = {100, 100, 100, 1000, 1000000};
    double times[] = {52.52, 11., 9., 1001., 23952.};

    // const int size = sizeof(N_values) / sizeof(N_values[0]);

    for (int i = 0; i < size; ++i) {
        file << N_values[i] << ";" << times[i] << "\n";
    }

    file.close();

}

void write_file(int n_values[],
                double times[],
                int size,
                std::string& filename)
{
    /*
    функция записи данных в filename.csv в заданнном формате
    n;      t_ms
    100;    52.52
    ...
    */ 
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла\n";
        return;
    }

    file << "n;t_ms\n";

    // форматный вывод (если необходимо)
    // file << std::fixed << std::setprecision(2);

    for (int i = 0; i < size; ++i) {
        file << n_values[i] << ";" << times[i] << "\n";
    }

    file.close();
}

