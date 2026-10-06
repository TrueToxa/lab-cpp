#include <iostream>

class Base{
    int base_field;
public:
    virtual void hello() const {
        std::cout << "I am base" << std::endl;
    }

    virtual ~Base() = default;
};

class Derived : public Base {
public:
    void hello() const{
        std::cout << "I am derived" << std::endl;
    }
    void hello2() const override{
        std::cout << "I am derived" << std::endl;
    }
};

int main() {
    Base base_instance;
    Derived derived_instance;
    Base* ptr_base = &base_instance;
    Base* ptr_base_to_derived = &derived_instance;

    // base_instance.hello();
    // derived_instance.hello();
    // derived_instance.Base::hello();

    ptr_base->hello();
    ptr_base_to_derived->hello();
    // ptr_base_to_derived->Base::hello();

    std::cout << sizeof(Base) << " " << sizeof(Derived);
    return 0;
}