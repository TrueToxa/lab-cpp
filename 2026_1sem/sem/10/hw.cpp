#include <iostream>
#include <cmath>

struct base_exception {
public:
    base_exception() = default;

    virtual const char* what() const {return "BaseException()";}
};

struct math_exception final : base_exception {
    math_exception() = default;

    virtual const char* what() const { return "MathException()"; }
};

struct invalid_argument final : base_exception {
    invalid_argument() = default;

    virtual const char* what() const { return "InvalidArgument()"; }
};

double inverse(double x) {
    if (x == 0)
        throw math_exception();
    return 1. / x;
}

double root(double x) {
    if (x < 0)
        throw invalid_argument();
    return std::sqrt(x);
}

int main() {
    try {
        inverse(0);
    } catch (math_exception& exc) {
        std::cout << "1. " << exc.what() << std::endl;
    } catch (base_exception& exc) {
        std::cout << "2. " << exc.what() << std::endl;
    }

    try {
        root(-1);
    } catch (math_exception& exc) {
        std::cout << "1. " << exc.what() << std::endl;
    } catch (base_exception& exc) {
        std::cout << "2. " << exc.what() << std::endl;
        throw invalid_argument();
    }

    // try {
    //     root(1);
    //     inverse(1);
    // }
    // catch (math_exception& exc) {
    //     std::cout << "1. " << exc.what() << std::endl;
    // }
    // catch (base_exception& exc) {
    //     std::cout << "2. " << exc.what() << std::endl;
    // }

}