#include <iostream>
#include <cmath>
#include <numbers>

using namespace std;

float mean(float const psi[], float const pdf[], float const dv, unsigned size)
{
    /*
    psi[] - массив значений некоторой величины, заданной в определённых точках
    pdf[] - массив значений функции распределения
    dv - интервал между соседними аргументами функции
    sise - количество значений в массивах
    */

    // наивная реализация
    float sum = 0.f;
    for (unsigned idx = 0; idx != size; ++idx)
        sum += psi[idx] * pdf[idx];
    return dv * sum;
}

float mean_half_recursion(float const psi[], float const pdf[], float const dv, unsigned size);
{
    /*
    Рекурсивная функция суммирования, делящая набор значений пополам
    и производящая суммирование в каждом из интервалов отдельно
    */

    if (size == 0)
        return 0;
    else if (size == 1)
        return psi[0] * pdf[0] * dv;
    else if (size == 2)
        return (psi[0] * pdf[0] + psi[1] * pdf[1]) * dv;
    unsigned size1 = size / 2;
    return mean_half_recursion(psi, pdf, dv, size1) +
           mean_half_recursion(psi[size1], pdf[size1], dv, size - size1);
}

float mean_double_step(float const psi[], float const pdf[], float const dv, unsigned size, );
{
    /*
    Cуммирование близких значений:
    x[i] = x[i] + x[i+1], x[i+2] = x[i+2] + x[i+3] и т.д.,
    затем производим суммирование с удвоением шага:
    x[i] = x[i] + x[i+2], x[i+4] = x[i+4] + x[i+6]
    */
    if (size == 0)
        return static_cast<float>(0);
    else if (size == 1)
        return dv * psi[0] * pdf[0];
    float *ans = new float[size];
    for (unsigned idx = 0; idx < size; idx++)
    {
        ans[idx] = psi[idx] * pdf[idx];
    }

    for (unsigned step = 1; step < size; step *= 2)
    {
        for (unsigned i = 0; i + step < size; i += 2 * step)
        {
            ans[i] = ans[i] + ans[i + step];
        }
    }
    float res = dv * ans[0];
    delete[] ans;
    return res;
}

float mean_kahan(float const psi[], float const pdf[], float const dv, unsigned size)
{
    /*
    суммирование Кехена
    "Алгоритм суммирования Кехена –
    это алгоритм суммирования рядов на основе EFT"
    */

    float sum = 0.f;
    float t = 0.f;
    for (unsigned idx = 0; idx != size; ++idx)
    {
        float y = psi[idx] * pdf[idx] - t;
        float z = sum + y;
        t = (z - sum) - y; // то, что отбросили, при преобразовнии типов
        sum = z;
    }
    return dv * sum;
}

int main()
{
    float const f_pi = 3.14159265359f;
    double const d_pi = 3.14159265359;
    float const f_e = 2.718281828459f;
    double const d_e = 2.718281828459;
    cout << setprecision(7) << scientific;

    

    return 0;
}
