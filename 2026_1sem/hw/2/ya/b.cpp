#include <iostream>
#include <string>

class Rational final {
// private: //by default
private:
        int numerator = 0;
        int denominator = 1;
public:
    /********************************************/

    Rational(int numerator, int denominator) : numerator(numerator), denominator(denominator) {
    }
    Rational(int numerator) : Rational(numerator, 1) {
    }
    Rational(const Rational& other) : Rational(other.numerator, other.denominator){
    }
    Rational() = default;

    Rational& operator=(const Rational& other){
        numerator = other.numerator;
        denominator = other.denominator;
        return *this;
    }
    Rational& operator+=(const Rational &rha){
        numerator = numerator*rha.denominator+rha.numerator*denominator;
        denominator = denominator*rha.denominator;
        return *this;
    }
    Rational& operator-=(const Rational &rha){
        numerator = numerator*rha.denominator-rha.numerator*denominator;
        denominator = denominator*rha.denominator;
        return *this;
    }
    Rational& operator*=(const Rational &rha) {
        numerator = numerator*rha.numerator;
        denominator = denominator*rha.denominator;
        return *this;
    }
    Rational& operator/=(const Rational &rha){
        numerator = numerator*rha.denominator;
        denominator = denominator*rha.numerator;
        return *this;
    }
    // Rational operator+(const Rational& other) const {
    //     Rational ans = {};
    //     ans += *this;
    //     ans += other;
    //     return ans;
    // }
    // Rational operator-(const Rational& other) const {
    //     Rational ans = {};
    //     ans += *this;
    //     ans -= other;
    //     return ans;
    // }
    // Rational operator*(const Rational& other) const {
    //     Rational ans = {};
    //     ans *= *this;
    //     ans *= other;
    //     return ans;
    // }
    // Rational operator/(const Rational& other) const {
    //     Rational ans = {};
    //     ans /= *this;
    //     ans /= other;
    //     return ans;
    // }

    Rational operator+() const {
        return *this;
    }
    Rational operator-() const {
        return Rational(-numerator, denominator);
    }


    explicit operator double() const {
        return static_cast<double>(numerator) / denominator;
    }
    double toDouble() const {
        double ans = static_cast<double>(numerator)/denominator;
        return ans;
    }
    explicit operator std::string() const {
    return "(" + std::to_string(numerator) + "/" + std::to_string(denominator) + ")";
    }
    std::string toString() const {
    return "(" + std::to_string(numerator) + "/" + std::to_string(denominator) + ")";
    }

// private:
    friend bool operator<(const Rational &, const Rational &);
    friend bool operator>(const Rational &, const Rational &);
    friend bool operator<=(const Rational &, const Rational &);
    friend bool operator>=(const Rational &, const Rational &);
    friend bool operator==(const Rational &, const Rational &);
    friend bool operator!=(const Rational &, const Rational &);

    // int m_numerator = 0;
    // int m_denominator = 1;
};

bool operator>(const Rational &lha, const Rational &rha) {
    return (lha.numerator*rha.denominator > rha.numerator*lha.denominator);
}
bool operator<(const Rational &lha, const Rational &rha) {
    return (lha.numerator*rha.denominator < rha.numerator*lha.denominator);
}
bool operator<=(const Rational &lha, const Rational &rha) {
    return (lha.numerator*rha.denominator <= rha.numerator*lha.denominator);
}
bool operator>=(const Rational &lha, const Rational &rha) {
    return (lha.numerator*rha.denominator >= rha.numerator*lha.denominator);
}
bool operator==(const Rational &lha, const Rational &rha) {
    return (lha.numerator*rha.denominator == rha.numerator*lha.denominator);
}
bool operator!=(const Rational &lha, const Rational &rha) {
    return (lha.numerator*rha.denominator != rha.numerator*lha.denominator);
}

Rational operator+(const Rational& lha, const Rational& rha) {
    Rational ans = lha;
    ans += rha;
    return ans;
}
Rational operator-(const Rational& lha, const Rational& rha) {
    Rational ans = lha;
    ans -= rha;
    return ans;
}
Rational operator*(const Rational& lha, const Rational& rha) {
    Rational ans = lha;
    ans *= rha;
    return ans;
}
Rational operator/(const Rational& lha, const Rational& rha) {
    Rational ans = lha;
    ans /= rha;
    return ans;
}

int main() {
    Rational a(1, 2);
    Rational b(3, 4);
    Rational c = a + b;
    std::cout << a.toDouble() <<" " << b.toString() << " " << c.toString() << std::endl;
    std::cout << (-a).toDouble() <<" " << b.toString() << " " << c.toString() << std::endl;
    return 0;
}
