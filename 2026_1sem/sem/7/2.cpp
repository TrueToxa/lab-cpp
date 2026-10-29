#include <iostream>

class Array {
private:
    size_t m_size;
    double* m_ptr;

    void copy_ptr(double* ptr) {
        for (size_t idx = 0; idx < m_size; ++idx) {
            m_ptr[idx] = ptr[idx];
        }
    }

public:
    explicit Array(size_t size) : m_size{size}, m_ptr{new double[m_size]} {
        std::cout << "Array(" << m_size << ")" << std::endl;
    }

    Array(const Array& other) = delete;
    Array& operator=(const Array& other) = delete;

    Array& operator=(Array&& other) noexcept {
        std::cout << "operator=(Array&&)" << std::endl;
        std::swap(m_size, other.m_size);
        std::swap(m_ptr, other.m_ptr);   
        // m_size = other.m_size;
        // delete[] m_ptr;
        // m_ptr = other.m_ptr;
        // other.m_ptr = nullptr;
        // other.m_size = 0;
        return *this;
    }

    Array(Array&& other) noexcept {
        // throw std::runtime_error("");
        std::cout << "~Array(Array&&)" << std::endl;
        m_size = other.m_size;
        m_ptr = other.m_ptr;
        // other.m_ptr = nullptr;
        // other.m_size = 0;
    }

    size_t size() {
        return m_size;
    }

    void print_ptr_address() const {
        std::cout << m_ptr << std::endl;
    }

    ~Array() {
        std::cout << "~Array()" << std::endl;
        delete[] m_ptr;
        // m_ptr = nullptr;  // NOTE: Nonsense
    }
};
int main() {
    // Array(32);
    int x = 3 + 5;
    Array arr = Array(12);
    arr.print_ptr_address();
    // Array&& arr_copy = std::move(arr);
    Array arr_copy = Array(32);
    arr_copy.print_ptr_address();
    arr = std::move(arr_copy);
    arr.print_ptr_address();
    arr_copy.print_ptr_address();
    return 0;
}

/*
 * C1
 * ^
 * C2 : public C1
 * ^
 * C3 : public C2
 * C1* obj = new C1 / C2 / C3;
 * C1* obj_new = C3;
 * ~C1()
 */
