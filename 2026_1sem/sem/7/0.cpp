// private:
//     double field_d;
//     float field_f;
//     double *ptr;
//         buffer
//     size_t size

//     Array(size_t size) {
        
//     }
//     ~Array() {
//         delete[] buffer; 
//     }

#include <iostream>

class Array {
private: 
    size_t m_size;
    double *m_ptr;
public:
    explicit Array(size_t size) : m_size{size}, m_ptr(new double[m_size]) {}

    // Array(const Array& other) = default;
    Array(const Array& other) : m_size{other.m_size}, m_ptr{new double[m_size]} {
        for (size_t idx = 0; idx < m_size; idx++) {
            m_ptr[idx] = other.m_ptr[idx];
        }
    }

    Array& operator=(const Array& other) {
        if (this == &other) {
            return *this;
        }
        if (m_size == other.m_size) {
            for (size_t idx = 0; idx<m_size; idx++) {
                m_ptr[idx] = other.m_ptr[idx];
            }
            return *this;
        }

        m_size = other.m_size;
        delete[] m_ptr;
        double *m_ptr = new double[m_size];
        for (size_t idx = 0; idx<m_size; idx++) {
                m_ptr[idx] = other.m_ptr[idx];
            }
        return *this;

    }

    void print_ptr_adress() const {
        std::cout << m_ptr << std::endl;
    }
    ~Array () {
        delete[] m_ptr;
    }
};

int main() {
    Array arr = Array(12);
    // Array arr = 12; //explicit
    Array arr_copy = Array(arr);
    arr = arr_copy;
    arr.print_ptr_adress();
    arr_copy.print_ptr_adress();
    return 0;
}

int main() {
    std::vector<int>
}