#include <iostream>

struct Velocity {
    double v_x = 0.0; // значения по умолчанию
    double v_y = 0.0; //поля класса
}

int main() {
    std::cout << "***" << std::endl;
    std::cout << fib(42) << std::endl;

    // Velocity of n particles
    double *v_x = new double[1000];
    double *v_y = new double[1000];
    // v[idx_particle][idx_dimention];
    double **v2d = new double*[1000];
    for (size_t idx = 0; idx < 1000; ++idx) {
        v2d[idx] = new double[2];
    }
    delete[] v2d;
    delete[] v_x;
    delete[] v_y;

    Velocity velocity;
    velocity.vx = 3.1415;
    velocity.vy = 3.1415;
    // Velocity arr_v[100];
    Velocity *arr_v = new Velocity[1000]; //динамический массив
    arr[10].v_x;
    arr[10].v_y;

    Velocity *dp_velocity = new Velocity;
    dp_velocity->v_x;
    (*dp_velocity).v_x;
    delete[] dp_velocity;

 
    return 52;
}