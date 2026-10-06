#include <iostream>

struct Complex {
public:
    int real = 0;
    int imag = 0;
    Complex() = default;
    Complex(int real, int imag) : real(real), imag(imag){
    }
};

template<typename T>
T sum(T lha, T rha) {
    std::cout << "T sum(T, T)" << std::endl;
    return lha + rha;
}
template<typename T, typename V>
V sum(T lha, V rha) {
    std::cout << "V sum(T, V)" << std::endl;
    return lha + rha;
}
template<>
int sum(int lha, int rha) {
    std::cout << "T=int, T sum(T, T)" << std::endl;
    return lha + rha;
}

template<>
Complex sum(Complex lha, Complex rha) {
    std::cout << "T=Complex, T sum(T, T)" << std::endl;
    return Complex(lha.real+rha.real, lha.imag+rha.imag);
}

template <size_t N>
void print(int array[N]) {
    for (size_t idx = 0; idx<N; ++idx) {
        std::cout<< array[idx] << ' ';
    }
    std::cout<< std::endl;
}
// int sum(int lha, int rha) {
//     std::cout << "int sum(int, int)" << std::endl;
//     return lha + rha;
// }


int main() {
    std::cout << sum<int>(1, 2) << std::endl;
    std::cout << sum<int, double>(1, 2.4) << std::endl;
    Complex result = sum(Complex(1, 2), Complex());
    
    // std::cout << sum<float>(1, 2) << std::endl;

    int array0[10];
    int array1[20];
    std::cout << typeid(array0).name() << std::endl;
    print<10>(array0); 

    return 0;
}