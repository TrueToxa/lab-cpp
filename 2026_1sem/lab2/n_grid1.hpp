#include <iostream>
#include <utility>

template <typename T, unsigned N = 2>
class NGrid;

template <typename T>
class NGrid<T, 1> final {
public:
    using value_type = T;
    using size_type = unsigned;
private:
    T* const data;
    size_type x_size;
public:
    NGrid(size_type x_size) : x_size(x_size), data(static_cast<T*>(operator new(sizeof(T)*x_size))) {} //*x_size!

    NGrid(size_type x_size, T const& t) : x_size(x_size), data(static_cast<T*>(operator new(sizeof(T)*x_size))) {
        for (size_type x_idx = 0; x_idx < x_size; x_idx++) {
            data[x_idx] = t;
        }
    }

    // 1. Конструкторы копирования
    NGrid(T const& t) : x_size(1), data(static_cast<T*>(operator new(sizeof(T)*x_size))) {
        *(data+0) = t;
    }

    void swap(NGrid<T, 1>& other) {
        std::swap(x_size, other.x_size);
        std::swap(data, other.data);
    }

    // 1. RAII Правило пяти 
    //Копирующий конструктор
    NGrid(NGrid<T, 1> const& other) : x_size(other.x_size), data(new T[other.x_size]) {
        for (size_type x_idx = 0; x_idx < x_size; x_idx++) {
            data[x_idx] = other.data[x_idx];
        }
    }
    //перемещающий конструктор
    NGrid(NGrid<T, 1>&& other) : data(nullptr), x_size(0) {
        swap(other);
    }

    //оператор копирующего присваивания
    NGrid<T, 1>& operator=(NGrid<T, 1> const& other) {
        if (this != &other) {
            NGrid<T, 1> tmp(other);
            swap(tmp);
        }
        return *this;
    }

    // оператор перемещающего присваивания
    NGrid<T, 1>& operator=(NGrid<T, 1>&& other) {
        swap(other);
        return *this;
    }
    //И, наконец, десттруктор Ж)
    ~NGrid() {
        // delete[] data;
        // for (size_type y_idx = 0; y_idx < y_size; y_idx++) {
            for (size_type x_idx = 0; x_idx < x_size; x_idx++) {
                data[x_idx].~T();
            }
        // }
        delete[] data;
    }

    T operator()(size_type x_idx) const {
        return data[x_idx];
    }

    T& operator()(size_type x_idx) {
        return data[x_idx];
    }

    NGrid<T, 1>& operator=(T const& t) {
        for (size_type idx = 0; idx < x_size; idx++) {
            data[idx] = t;
        }
        return *this;
    }

    size_type get_x_size() const { return x_size; }
    size_type get_size(size_type = 0) const { return x_size; }

    //2. оператор индексирования, код в main.cpp
    T& operator[](size_type x_idx) {
        return data[x_idx];
    }

    T const& operator[](size_type x_idx) const {
        return data[x_idx];
    }
};

/******************************/
template <typename T, unsigned N>
class NGrid final {
public:
    using value_type = T;
    using size_type = unsigned;
    using hyperplane_type = NGrid<T, N - 1>; //тип гиперплоскостей
private:
    hyperplane_type** data; //массив гиперплоскостей
    size_type y_size;
public:
    template <typename... Args>
    NGrid(size_type y_size, Args... args) : y_size(y_size), data(new hyperplane_type* [y_size]) {
        for (size_type y_idx = 0; y_idx < y_size; y_idx++) {
            data[y_idx] = new hyperplane_type(args...);
        }
    }

    // 1. Конструкторы копирования
    NGrid(T const& t) : y_size(1), data(new hyperplane_type* [1]) {
        data[0] = new hyperplane_type(t);
    }

    void swap(NGrid<T, N>& other) {
        std::swap(y_size, other.y_size);
        std::swap(data, other.data);
    }

    // 1. RAII Правило пяти 
    //Копирующий конструктор
    NGrid(NGrid<T, N> const& other) : y_size(other.y_size), data(new hyperplane_type* [other.y_size]) {
        for (size_type y_idx = 0; y_idx < y_size; y_idx++) {
            data[y_idx] = new hyperplane_type(*other.data[y_idx]);
        }
    }
    //перемещающий конструктор
    NGrid(NGrid<T, N>&& other) : data(nullptr), y_size(0) {
        swap(other);
    }

    //оператор копирующего присваивания
    NGrid<T, N>& operator=(NGrid<T, N> const& other) {
        if (this != &other) {
            NGrid<T, N> tmp(other);
            swap(tmp);
        }
        return *this;
    }

    // оператор перемещающего присваивания
    NGrid<T, N>& operator=(NGrid<T, N>&& other) {
        swap(other);
        return *this;
    }
    //И, наконец, десттруктор Ж)
    ~NGrid() {
        if (data) {
            for (size_type y_idx = 0; y_idx < y_size; y_idx++) {
                data[y_idx].~T();
            }
            delete[] data;
        }
        y_size = 0;
    }

    //оператор () - вызывается по рекусрии
    template <typename... Args>
    T operator()(size_type y_idx, Args... args) const {
        return (*data[y_idx])(args...);
    }

    template <typename... Args>
    T& operator()(size_type y_idx, Args... args) {
        return (*data[y_idx])(args...);
    }

    NGrid<T, N>& operator=(T const& t) {
        for (size_type y_idx = 0; y_idx < y_size; y_idx++) {
            *data[y_idx] = t;
        }
        return *this;
    }

    size_type get_y_size() const { return y_size; }

    //2. оператор индексирования абсолютно такой же
    hyperplane_type& operator[](size_type y_idx) {
        return *data[y_idx];
    }

    hyperplane_type const& operator[](size_type y_idx) const {
        return *data[y_idx];
    }
};

// int main() {
//     return 0;
// }