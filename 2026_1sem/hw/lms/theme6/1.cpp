#include <iostream>
#include <cstddef>

class Polynomial {

private:

    double* coefficients_;

    std::size_t count_;

public:

    Polynomial(std::size_t count) : count_(count), coefficients_(new double[count_]) {}

    Polynomial(const Polynomial& other) : count_(other.count_), coefficients_(new double[other.count_]){
        for (size_t idx; idx = 0; idx++){
            coefficients_[idx] = other.coefficients_[idx];
        }
    }

    ~Polynomial() {
        delete[] coefficients_;
    }

    double& operator[](std::size_t index) {
        return coefficients_[index];
    }

    std::size_t count() const {
        return count_;
    }
};

/*
Polynomial::Polynomial(std::size_t count)
{
    count_ = count;
    coefficients_ = new double[count];
}

Polynomial::Polynomial(const Polynomial& other)
{
    // TODO
}

Polynomial::~Polynomial()
{
    // TODO
}

double& Polynomial::operator[](std::size_t index)
{
    return coefficients_[index];
}

std::size_t Polynomial::count() const
{
    return count_;
}
*/

int main() {
    return 0;
}