#include <iostream>

class Interface {
public:
    virtual unsigned roll() = 0;

    virtual ~Interface() = default;
};

class FairDice : public Interface {
public:
    unsigned roll() override {
        return 1;
    }
};

class UnfairDice : public Interface {
public:
    unsigned roll() override {
        return 0;
    }
};

int main() {
    // Interface instance = {};
    Interface *fair = new FairDice();
    Interface *unfair = new UnfairDice();
    std::cout << fair->roll() << " " <<
                unfair->roll()<<std::endl;

    delete fair;
    delete unfair;
}