#include <iostream>
#include <random>

using std::cout;
using std::endl;

double * create_array(int N) {
    // double array[N];
    double * array = new double[N];
    return array;
}

double *create_random_array(int N, std::default_random_engine& rng) { 
    //убрать имперсант, чтобы одинаковый сид
    // unsigned seed = 1001;
    double *array = new double[N];
    // std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned> dstr(0, 999);
    for (unsigned idx = 0; idx < N; ++idx){
        array[idx] = dstr(rng);
    }
    return array;
}



int main() {
    unsigned seed = 0;
    std::default_random_engine rng(seed);
    double *first = create_array(1'000);
    double *random0 = create_random_array(100, rng);
    double *random1 = create_random_array(100, rng);
    for (unsigned idx = 0; idx < 100; ++idx){
        cout << idx << ": " << (random0[idx] == random1[idx]) << endl;
    }
    return 0;
}