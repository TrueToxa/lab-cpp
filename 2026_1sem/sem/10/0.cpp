#include <exception>
#include <iostream>

struct my_base_exception{
public:
    my_base_exception() = default;

    virtual const char* what() const {return "MyBaseException()";}
};

struct my_derived_exception : my_base_exception 
{
    my_derived_exception() = default;

    const char* what() const override {return "MyDerivedException()"; }
};


int main() {
    try {
        throw my_base_exception();
    }
    catch (my_base_exception& exp) {
        std::cout << exp.what() << std::endl;
    } catch (...) {
        std::cout << "I caught everything" << std::endl;;
    }

    try {
        throw my_derived_exception();
    } catch (my_derived_exception& exp) {
        std::cout << exp.what() << std::endl;
        std::cout << "1" << std::endl;;
    }
    catch (my_base_exception& exp) {
        std::cout << exp.what() << std::endl;
        std::cout << "2" << std::endl;;
    }
    catch (...) {
        std::cout << "I caught everything" << std::endl;;
    }
    
    // try {
    //     std::cout << 1/0 << std::endl;
    // } catch (std::runtime_error& exp) {
    //     std::cout << "Basic exeption" << std::endl;
    // }

    try{
        try {
            double* x = new double[1'000'000'000'000];
            double x  = 123; //не выполняется
            x *= x; 
        } catch (std::runtime_error& exc) {
            std::cout << "1. runtime_error" << exc.what() << std::endl;

        } catch (std::bad_alloc& exc) {
            std::cout << "2. Basic exeption" << exc.what() << std::endl;
            throw std::runtime_error("My custom throw from exeption");
        }
    }catch(std::runtime_error& exc) {
        std::cout << "Ultimate catcher: " << exc.what() << std::endl;
    } catch (...) {
        std::cout << "Ultimate catcher: " << std::endl;
    }
    return 0;
}