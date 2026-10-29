#include <iostream>
#include <utility>

template <typename T, unsigned n>
class Grid final {
public:
    using value_type = T;
    using size_type = unsigned;
private:
    T* data;
    size_type y_size, x_size;
public:
    Grid(T* data, size_type y_size, size_type x_size) :
        data(data), y_size(y_size), x_size(x_size) {
    }
    
    // 1. Конструкторы копирования
    Grid(T const& t) : y_size(1), x_size(1), data(new T[x_size*y_size]) {
        data[0] = t;
    }
    Grid(size_type y_size, size_type x_size) : y_size(y_size), x_size(x_size), data(new T[x_size*y_size]){}
    Grid(size_type y_size, size_type x_size, T const& t) : Grid(y_size, x_size) {
        for (size_type y_idx = 0; y_idx<y_size; y_idx++) {
            for (size_type x_idx = 0; x_idx<x_size; x_idx++) {
                // auto get_idx(x_idx, y_idx) = y_idx*x_size+x_idx
                data[get_idx(x_idx, y_idx)] = t;
        }
        }
    }

    void swap(Grid<T> &other) {
        std::swap(y_size, other.y_size);
        std::swap(x_size, other.x_size);
        std::swap(data, other.data);
        // std::swap(value_type, other.value_type); //итак проверяется
        // std::swap(size_type, other.size_type);
    }

    // 1. RAII Правило пяти 
    //Копирующий конструктор
    Grid(Grid<T> const& other) : y_size(other.y_size), x_size(other.x_size), data(new T[x_size * y_size]) {
        for (size_type y_idx = 0; y_idx < y_size; y_idx++) {
            for (size_type x_idx = 0; x_idx < x_size; x_idx++) {
                data[get_idx(x_idx, y_idx)] = other(x_idx, y_idx);
            }
        }
    }
    //перемещающий конструктор
    Grid(Grid<T>&& other) {
        swap(other);
    }

    //оператор копирующего присваивания
    Grid<T>& operator=(Grid<T>& other) {
        if (this != &other) {
            Grid<T> tmp(other);
            swap(tmp);
        }
        return *this;
    }

    // оператор перемещающего присваивания
    Grid<T>& operator=(Grid<T>&& other) {
        swap(other);
        return *this;
    }
    //И, наконец, десттруктор Ж)
    ~Grid() {
        delete[] data;
        x_size = 0;
        y_size = 0;
    }

    T operator()(size_type y_idx, size_type x_idx) const {
        return data[y_idx * x_size + x_idx];
    }

    T& operator()(size_type y_idx, size_type x_idx) {
        return data[y_idx * x_size + x_idx];
    }

    Grid<T>& operator=(T const& t) {
        for (
            auto it = data, end = data + x_size * y_size;
            it != end; ++it
            ) *it = t;
        return *this;
    }

    size_type get_y_size() const { return y_size; }
    size_type get_x_size() const { return x_size; }
    size_type get_idx(size_type x_idx, size_type y_idx) const { return y_idx * x_size + x_idx; }

    //2. оператор индексирования, код в main.cpp
    T* operator[](size_type y_idx) {
        return data + y_idx * x_size;
    }

    T const* operator[](size_type y_idx) const {
        return data + y_idx * x_size;
    }
};

// int main() {
//     return 0;
// }