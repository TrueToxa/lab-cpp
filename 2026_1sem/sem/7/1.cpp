#include <iostream>

class Array {
private: 
    size_t m_size;
    double *m_ptr;
public:
    explicit Array(size_t size) : m_size{size}, m_ptr(new double[m_size]) {
        std::cout << "~Array(" << m_size << ")" << std::endl;
    }

    // Array(const Array& other) = default;
    Array(const Array& other) = delete;
    Array& operator=(const Array& other) = delete;

    Array& operator=(Array&& other)  {
        std::cout << "~Array(Array&&)" << std::endl;
        m_ptr = other.m_ptr;
        m_size = other.m_size;
        // other.m_ptr = nullptr;
        // other m_size = 0; 
        return *this;
    }

    void print_ptr_adress() const {
        std::cout << m_ptr << std::endl;
    }
    ~Array () {
        std::cout << "~Array()" << std::endl;
        delete[] m_ptr;
    }
};

int main() {
    //type lvalue = rvalue 
    Array(32);
    int x = 3+5;
    Array arr = Array(12);
    arr.print_ptr_adress();
    Array&& arr_copy = std::move(arr);
    // arr = arr_copy;
    arr.print_ptr_adress();
    arr_copy.print_ptr_adress();
    return 0;
}