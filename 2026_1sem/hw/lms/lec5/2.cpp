template <unsigned N>
double apply(double (*f)(double), double x){
    for (unsigned i = 0; i < N; i++)
        x = f(x);
    return x;
}