#include <iostream>
#include <utility>

template <typename T, unsigned n = 2>
class NGrid;

template <typename T>
class NGrid<T, 1> final {
public:
    using value_type = T;
    using size_type = unsigned;
private:
    T* data;
    size_type x_size;
public:
    NGrid(size_type x_size) : x_size(x_size), data(new T[x_size]) {}

    NGrid(size_type x_size, T const& t) : x_size(x_size), data(new T[x_size]) {
        for (size_type x_idx = 0; x_idx < x_size; x_idx++) {
            data[x_idx] = t;
        }
    }

    // 1. Конструкторы копирования
    NGrid(T const& t) : x_size(1), data(new T[1]) {
        data[0] = t;
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
        delete[] data;
        x_size = 0;
    }

    T operator()(size_type x_idx) const {
        return data[x_idx];
    }

    T& operator()(size_type x_idx) {
        return data[x_idx];
    }

    NGrid<T, 1>& operator=(T const& t) {
        for (auto it = data, end = data + x_size; it != end; ++it)
            *it = t;
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

/*****************************8 */
template <typename T, unsigned n>
class NGrid final {
public:
    using value_type = T;
    using size_type = unsigned;
    using hyperplane_type = NGrid<T, n - 1>; //тип гиперплоскостей
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

    void swap(NGrid<T, n>& other) {
        std::swap(y_size, other.y_size);
        std::swap(data, other.data);
    }

    // 1. RAII Правило пяти 
    //Копирующий конструктор
    NGrid(NGrid<T, n> const& other) : y_size(other.y_size), data(new hyperplane_type* [other.y_size]) {
        for (size_type y_idx = 0; y_idx < y_size; y_idx++) {
            data[y_idx] = new hyperplane_type(*other.data[y_idx]);
        }
    }
    //перемещающий конструктор
    NGrid(NGrid<T, n>&& other) : data(nullptr), y_size(0) {
        swap(other);
    }

    //оператор копирующего присваивания
    NGrid<T, n>& operator=(NGrid<T, n> const& other) {
        if (this != &other) {
            NGrid<T, n> tmp(other);
            swap(tmp);
        }
        return *this;
    }

    // оператор перемещающего присваивания
    NGrid<T, n>& operator=(NGrid<T, n>&& other) {
        swap(other);
        return *this;
    }
    //И, наконец, десттруктор Ж)
    ~NGrid() {
        if (data) {
            for (size_type y_idx = 0; y_idx < y_size; y_idx++) {
                delete data[y_idx];
            }
            delete[] data;
        }
        y_size = 0;
    }

    template <typename... Args>
    T operator()(size_type y_idx, Args... args) const {
        return (*data[y_idx])(args...);
    }

    template <typename... Args>
    T& operator()(size_type y_idx, Args... args) {
        return (*data[y_idx])(args...);
    }

    NGrid<T, n>& operator=(T const& t) {
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