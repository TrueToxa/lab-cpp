#include <iostream>

class Base {
protected:
    double base = 0;
};

class Left : public Base {
protected:
    double left = 1;
};
class Right : public Base {
protected:
    double right = 2;
};
class Derived : public Left, public Right {
protected:
    double derived = 4;
public:
    void print() const {
        std::cout << "derived=" << derived << std::endl;
        std::cout << "left=" << left << std::endl;
        std::cout << "right=" << right << std::endl;
        std::cout << "Left::base=" << (this->Left::base) << std::endl;
        std::cout << "Right::base=" << (this->Right::base) << std::endl;
    }
    void print_ptr() const {
        std::cout << "derived       =" << &derived << std::endl;
        std::cout << "left          =" << &left << std::endl;
        std::cout << "right         =" << &right << std::endl;
        std::cout << "Left::base    =" << &(this->Left::base) << std::endl;
        std::cout << "Right::base   =" << &(this->Right::base) << std::endl;
    }
};

int main() {
    std::cout << sizeof(Base) << std::endl;
    std::cout << sizeof(Left) << std::endl;
    std::cout << sizeof(Right) << std::endl;
    std::cout << sizeof(Derived) << std::endl;
    Derived d = {};
    d.print();
    d.print_ptr();
    return 0;
}