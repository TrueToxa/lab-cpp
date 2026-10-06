#include <iostream>
#include <cmath>
// #include <numbers>
#include <iomanip>
// #include <fstream>

using namespace std;

float const f_pi = 3.14159265359f;
double const d_pi = 3.14159265359;
float const f_e = 2.718281828459f;
double const d_e = 2.718281828459;

float mean_half_recursion(float const psi[], float const pdf[], float const dv, unsigned size)
{
    /*
    Рекурсивная функция суммирования, делящая набор значений пополам
    и производящая суммирование в каждом из интервалов отдельно
    */
    /*
    psi[] - массив значений некоторой величины, заданной в определённых точках
    pdf[] - массив значений функции распределения
    dv - интервал между соседними аргументами функции
    sise - количество значений в массивах
    */

    if (size == 0)
        return 0;
    else if (size == 1)
        return psi[0] * pdf[0] * dv;
    else if (size == 2)
        return (psi[0] * pdf[0] + psi[1] * pdf[1]) * dv;
    unsigned size1 = size / 2;
    return mean_half_recursion(psi, pdf, dv, size1) +
           mean_half_recursion(&psi[size1], &pdf[size1], dv, size - size1);
}

float int_exp_xy2(unsigned N, float inf)
{
    //   \iint_-inf^inf e^(-x^2-y^2) dx dy =
    // = \int_0^2pi \int_-inf^inf e^(-r^2) r dr d\phi //method for numerical intagret
    // = 2 pi \int_0^\inf e^-z dz/2 = 
    // = pi \int_0^inf e^-z dz e
    // = pi //analytical value

    float dr = inf / N;
    float *psi = new float[N];
    float *pdf = new float[N];
    for (unsigned idx = 0; idx < N; ++idx)
    {
        float r = dr*idx;
        psi[idx] = exp(-r*r)*r;
        pdf[idx] = 1;
    }
    float c = 2 *  mean_half_recursion(psi, pdf, dr, N);
    float res = f_pi * c;
    delete[] psi;
    delete[] pdf;
    return c;
}

int main() {
    cout << setprecision(7) << scientific;
    cout << int_exp_xy2(1000, 10) << "*pi" << endl; 
    return 0;
}
