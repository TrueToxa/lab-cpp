#include <iostream>

class Base {
protected:
    int base_field = 0;

public:
    Base() {
        std::cout << "Base()" << std::endl;
    }
    void print_base() {
        // std::cout << "My derived field=" << derived_field << std::endl;
        std::cout << "My base field=" << base_field << std::endl;
    }

    virtual ~Base() {
        std::cout << "~Base()" << std::endl;
    }
};

class Derived : public Base {
private:
    int derived_field = 1;

public:
    Derived() {
        std::cout << "Derived()" << std::endl;
    }
    void print_derived() {
        std::cout << "My derived field=" << derived_field << std::endl;
        std::cout << "My base field=" << base_field << std::endl;
    }
    ~Derived() {
        std::cout << "~Derived()" << std::endl;
    }
};

int main() {
    Base base_instance;
    Derived derived_instance;

    base_instance.print_base();
    derived_instance.print_base();
    derived_instance.print_derived();

    Base* base_ptr = &base_instance;
    Base* base_ptr_to_derived_instance = &derived_instance;
    Base* base_new_ptr = new Base();
    Base* base_new_ptr_to_derived = new Derived();
    // Derived* base_new_ptr_to_derived = new Derived();
    delete base_new_ptr;
    delete base_new_ptr_to_derived;
    return 0;
}