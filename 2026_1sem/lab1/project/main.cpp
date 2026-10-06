#include <iostream>
#include <random>
#include <fstream>
#include <string>

template<typename T> T max(T lha, T rha);
template<typename T> T min(T lha, T rha);
//**************************
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

//*******************************
class Dice : public Interface {
public:
    Dice(unsigned max, unsigned seed):
        max(max), dstr(1, max), reng(seed) { }
    Dice() : Dice(6, 67) {}

    unsigned roll() override{
        return dstr(reng);
    }

private:
    unsigned max;
    std::uniform_int_distribution<unsigned> dstr;
    std::default_random_engine reng;
};

class ThreeDicePool : public Interface{
public:
    ThreeDicePool(Interface& dice1, Interface& dice2, Interface& dice3) :
            dice1(dice1), dice2(dice2), dice3(dice3)
    {}
    unsigned roll() override {
        return dice1.roll()+dice2.roll()+dice3.roll();
    }

private:
    Interface& dice1;
    Interface& dice2;
    Interface& dice3;
};

class PenaltyDice : virtual public Interface{
public:
    PenaltyDice(Interface& dice1, Interface& dice2) :
            dice1(dice1), dice2(dice2)
    {}
    unsigned roll() override {
        return min(dice1.roll(), dice2.roll());
    }

private:
    Interface& dice1;
    Interface& dice2;
};

class BonusDice : virtual public Interface{
public:
    BonusDice(Interface& dice1, Interface& dice2) :
            dice1(dice1), dice2(dice2)
    {}
    unsigned roll() override {
        return max(dice1.roll(), dice2.roll());
    }

private:
    Interface& dice1;
    Interface& dice2;
};
// class DoubleDice : public Interface{ //не совсем понял в чем смысл ромбовидного наследования здесь
// public:
//     DoubleDice(Interface& dice) :
//     {
//         this->penalty = new PenaltyDice(dice, dice);
//         this->bonus = new BonusDice(dice, dice);
//     }
//     unsigned roll() override {
//         return min(dice1.roll(), dice2.roll());
//     }

//     ~DoubleDice() {
//         delete penalty;
//         delete bonus;
//     }

// private:
//     Interface* penalty;
//     Interface* bonus;
// };

class DoubleDice : public PenaltyDice, public BonusDice {
public:
    DoubleDice(Interface& dice) : PenaltyDice(dice, dice), BonusDice(dice, dice)
    {}

    unsigned roll() override {
        return PenaltyDice::roll() + BonusDice::roll();
    }
};

template<typename T>
T max(T lha, T rha) {
    if (lha>rha) {return lha;}
    return rha;
}
template<typename T>
T min(T lha, T rha) {
    if (lha<rha) {return lha;}
    return rha;
}

double expected_value(Interface &d, unsigned number_of_rolls = 1) {
    auto accum = 0llu;
    for (unsigned cnt = 0; cnt != number_of_rolls; ++cnt)
        accum += d.roll();
    return static_cast<double>(accum) / static_cast<double>(number_of_rolls);
}

double value_probability(unsigned value, Interface &d, unsigned number_of_rolls = 1) {
    auto accum = 0llu;
    for (unsigned cnt = 0; cnt != number_of_rolls; ++cnt)
        if (d.roll() == value) {
            accum += 1;
        }
    return static_cast<double>(accum) / static_cast<double>(number_of_rolls);
}

void dice_distribution(Interface& d, unsigned number_of_rolls = 1, const std::string& name="distr", bool save_file = false)
{
    std::ofstream file; //загуглено
    std::ostream* out = &std::cout;

    if (save_file) {
        file.open(name + ".csv");
        out = &file;
    }
    else {
    *out << name << std::endl;
    }

    *out << "N,p" << std::endl;
    double p = 0;
    unsigned value = 0;
    while (p==0) {
        value++;
        p = value_probability(value, d, number_of_rolls);
        *out << value << "," << p << std::endl;
    }
    while (p != 0) {
        value++;
        p = value_probability(value, d, number_of_rolls);
        *out << value << "," << p << std::endl;
    }
}

int main() {
    // Interface instance = {};
    int k = 10e4;

    Interface *fair = new FairDice();
    Interface *unfair = new UnfairDice();
    Interface *dice = new Dice(6, 239);
    Interface *dice3 = new ThreeDicePool(*dice, *dice, *dice);
    Interface *bonus = new BonusDice(*dice, *dice);
    Interface *penalty = new PenaltyDice(*dice, *dice);
    std::cout << fair->roll() << " " <<
                dice->roll() << " " <<
                dice3->roll() << " " <<
                penalty->roll() << " " <<
                bonus->roll() << " " <<
                unfair->roll()<<std::endl;

    std::cout << expected_value(*fair, k) << " " <<
                expected_value(*dice, k)  << " " <<
                expected_value(*dice3, k)  << " " <<
                expected_value(*penalty, k)  << " " <<
                expected_value(*bonus, k)  << " " <<
                expected_value(*unfair, k) <<std::endl;

    dice_distribution(*penalty, k, "penalty");
    dice_distribution(*bonus, k, "bonus");
    dice_distribution(*penalty, 1e6, "csv/penalty", true);
    dice_distribution(*bonus, 1e6, "csv/bonus", true);

    //task 2
    Interface* dice100 = new Dice(100, 52);
    Interface* bonus100 = new BonusDice(*dice100, *dice100);
    Interface* penalty100 = new PenaltyDice(*dice100, *dice100);
    dice_distribution(*dice3, 1e6, "csv/threedice6", true);
    dice_distribution(*bonus100, 1e6, "csv/bonus100", true);
    dice_distribution(*penalty100, 1e6, "csv/penalty100", true);

    //task 3
    Interface* dice2 = new DoubleDice(*dice100);
    std::cout << "DoubleDice, <p>=" << expected_value(*dice2, 1e6) << std::endl;
    dice_distribution(*dice2, 1e6, "csv/dice2", true);


    delete fair;
    delete unfair;
    delete bonus;
    delete penalty;
    delete dice;
    delete dice3;
    delete dice2;
    delete penalty100;
    delete bonus100;
    delete dice100;
}

/*
1 1 11 2 2 0
1 3.50472 10.5021 4.47628 2.53288 0
penalty
N,p
1,0.02909
2,0.08355
3,0.13947
4,0.19738
5,0.25109
6,0.3078
7,0
bonus
N,p
1,0.3054
2,0.24966
3,0.19582
4,0.13951
5,0.08433
6,0.02742
7,0
DoubleDice, <p>=100.969
*/
