class Interface {
public:
    virtual unsigned roll() = 0;

    virtual ~Interfacce() = default;
};

class FairDice : public Interface {
public:
    unsigned roll() override {
        return 1;
    }
};

class UnairDice : public Interface {
public:
    unsigned roll() override {
        return 0;
    }
};

int main() {
    // Interface instance = {};
    Interface *fair = new FairDice();
    Interface *unfair = new UnfairDice();
    fair->roll();
    unfair->roll();

    delete fair;
    delete unfair;
}