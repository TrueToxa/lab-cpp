#include <iostream>

class ExplicitInt {
    int param;

public:
    ExplicitInt(int param) : param(param) {
    }

    int value() {
        return param;
    }
};

int main() {
    ExplicitInt x = 1;
    std::cout << x.value();
    return 0;
}