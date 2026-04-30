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

double d_maxwell_velocity_distribution(double velocity, double T)
{
    return (1. / sqrt(T * d_pi)) * exp(-velocity * velocity / T);
}

double mean(double const psi[], double const pdf[], double const dv, unsigned size)
{
    /*
    psi[] - массив значений некоторой величины, заданной в определённых точках
    pdf[] - массив значений функции распределения
    dv - интервал между соседними аргументами функции
    sise - количество значений в массивах
    */

    // наивная реализация
    double sum = 0.;
    for (unsigned idx = 0; idx != size; ++idx)
        sum += psi[idx] * pdf[idx];
    return dv * sum;
}

double mean_half_recursion(double const psi[], double const pdf[], double const dv, unsigned size)
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
           mean_half_recursion(&psi[size1], &pdf[size1], dv, size - size1);
}

double mean_double_step(double const psi[], double const pdf[], double const dv, unsigned size)
{
    /*
    Cуммирование близких значений:
    x[i] = x[i] + x[i+1], x[i+2] = x[i+2] + x[i+3] и т.д.,
    затем производим суммирование с удвоением шага:
    x[i] = x[i] + x[i+2], x[i+4] = x[i+4] + x[i+6]
    */
    if (size == 0)
        return static_cast<double>(0);
    else if (size == 1)
        return dv * psi[0] * pdf[0];
    double *ans = new double[size];
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
    double res = dv * ans[0];
    delete[] ans;
    return res;
}

double mean_kahan(double const psi[], double const pdf[], double const dv, unsigned size)
{
    /*
    суммирование Кехена
    "Алгоритм суммирования Кехена –
    это алгоритм суммирования рядов на основе EFT"
    */

    double sum = 0.;
    double t = 0.;
    for (unsigned idx = 0; idx != size; ++idx)
    {
        double y = psi[idx] * pdf[idx] - t;
        double z = sum + y;
        t = (z - sum) - y; // то, что отбросили, при преобразовнии типов
        sum = z;
    }
    return dv * sum;
}

double mean_velocity(unsigned N, double T, double inf)
{
    double dv = inf / N;
    double *psi = new double[N];
    double *pdf = new double[N];

    for (unsigned idx = 0; idx < N; ++idx)
    {
        psi[idx] = dv * idx;
        pdf[idx] = d_maxwell_velocity_distribution(dv * idx, T);
    }
    /*\int_{-inf}^{inf} |v| f(v) dv = 2 * \int_0^{inf}...dv*/
    double res = 2 * mean(psi, pdf, dv, N);
    delete[] psi;
    delete[] pdf;
    return res;
}

double mean_velocity_half_recursion(unsigned N, double T, double inf)
{
    double dv = inf / N;
    double *psi = new double[N];
    double *pdf = new double[N];
    for (unsigned idx = 0; idx < N; ++idx)
    {
        psi[idx] = dv * idx;
        pdf[idx] = d_maxwell_velocity_distribution(dv * idx, T);
    }

    double res = 2 * mean_half_recursion(psi, pdf, dv, N);
    delete[] psi;
    delete[] pdf;
    return res;
}

double mean_velocity_double_step(unsigned N, double T, double inf)
{
    double dv = inf / N;
    double *psi = new double[N];
    double *pdf = new double[N];
    for (unsigned idx = 0; idx < N; ++idx)
    {
        psi[idx] = dv * idx;
        pdf[idx] = d_maxwell_velocity_distribution(dv * idx, T);
    }

    double res = 2 * mean_double_step(psi, pdf, dv, N);

    delete[] psi;
    delete[] pdf;
    return res;
}

double mean_velocity_kahan(unsigned N, double T, double inf)
{
    double dv = inf / N;
    double *v = new double[N];
    double *psi = new double[N];
    double *pdf = new double[N];
    for (unsigned idx = 0; idx < N; ++idx)
    {
        v[idx] = dv * idx + dv / 2.;
        psi[idx] = v[idx];
        pdf[idx] = d_maxwell_velocity_distribution(v[idx], T);
    }
    double res = 2. * mean_kahan(psi, pdf, dv, N);
    delete[] v;
    delete[] psi;
    delete[] pdf;
    return res;
}

double analytic_mean(double T)
{
    return sqrt(T / d_pi);
}

int test(unsigned N = 1000,
         double T = 300.,
         double inf = 1000.,
         int precision = 7)
{

    cout << setprecision(precision) << scientific;
    cout << "naive:             " << mean_velocity(N, T, inf) << endl;
    cout << "half recursion:    " << mean_velocity_half_recursion(N, T, inf) << endl;
    cout << "double step:       " << mean_velocity_double_step(N, T, inf) << endl;
    cout << "kahan:             " << mean_velocity_kahan(N, T, inf) << endl;
    cout << "analytical:        " << analytic_mean(T) << endl;

    return 0;
}

int test_to_csv(float T, unsigned N, float inf, bool header = false, int precision = 7)
{
    // ofstream fout("adisabebe.csv", ios::app);

    if (header)
    {
        cout << "T,N,inf,analytical,naive,half_recursion,double_step,kahan" << endl;
    }

    cout << setprecision(precision) << scientific;
    cout << T << "," << N << "," << inf << ",";
    cout << analytic_mean(T) << ",";
    cout << mean_velocity(N, T, inf) << ",";
    cout << mean_velocity_half_recursion(N, T, inf) << ",";
    cout << mean_velocity_double_step(N, T, inf) << ",";
    cout << mean_velocity_kahan(N, T, inf) << endl;

    // fout.close();

    return 0;
}
int main()
{
    // test();
    test_to_csv(1e-1, 1e1, 1e2, true, 7);
    test_to_csv(1e-1, 1e2, 1e2, false, 7);
    test_to_csv(1e-1, 1e3, 1e2, false, 7);
    test_to_csv(1e-1, 1e4, 1e2, false, 7);
    test_to_csv(1e-1, 1e5, 1e2, false, 7);
    test_to_csv(1e0, 1e1, 1e2, false, 7);
    test_to_csv(1e0, 1e2, 1e2, false, 7);
    test_to_csv(1e0, 1e3, 1e2, false, 7);
    test_to_csv(1e0, 1e4, 1e2, false, 7);
    test_to_csv(1e0, 1e5, 1e2, false, 7);
    test_to_csv(1e2, 1e1, 1e2, false, 7);
    test_to_csv(1e2, 1e2, 1e2, false, 7);
    test_to_csv(1e2, 1e3, 1e2, false, 7);
    test_to_csv(1e2, 1e4, 1e2, false, 7);
    test_to_csv(1e2, 1e5, 1e2, false, 7);
    test_to_csv(1e4, 1e1, 1e3, false, 7);
    test_to_csv(1e4, 1e2, 1e3, false, 7);
    test_to_csv(1e4, 1e3, 1e3, false, 7);
    test_to_csv(1e4, 1e4, 1e3, false, 7);
    test_to_csv(1e4, 1e5, 1e3, false, 7);
    return 0;
}