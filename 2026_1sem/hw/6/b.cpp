#include <cstddef>
#include <iostream>

template <typename T>
class Array
{
public:
    // Список операций:

    //   конструктор класса, который создает
    //   Array размера size, заполненный значениями
    //   value типа T. Считайте что у типа T есть
    //   конструктор, который можно вызвать без
    //   без параметров, либо он ему не нужен.
    explicit Array(size_t size = 0, const T& value = T()) :
        size_(size), data_(new T[size]) {
            for (size_t idx=0; idx < size_; idx++) {
                data_[idx] = value;
            }
        }
    
    
    //   конструктор копирования, который создает
    //   копию параметра. Считайте, что для типа
    //   T определен оператор присваивания.
    Array(const Array & init) :
        size_(init.size_), data_(new T[init.size_]) {

        for (size_t idx=0; idx < size_; idx++) {
                data_[idx] = init.data_[idx];
            }
    }


    //   деструктор, если он вам необходим.
    ~Array() {
        delete[] data_;
    }
    

    //   оператор присваивания.
    Array& operator=(const Array & init) {
        delete[] data_;
        T* data_ = new T[init.size_];
        size_ = init.size_;
        for (size_t idx=0; idx < size_; idx++) {
                data_[idx] = init.data_[idx];
            }
        return *this;
    }
    
    //   возвращает размер массива (количество
    //                              элементов).
    size_t size() const {
        return size_;
    }

    //   две версии оператора доступа по индексу.
    T& operator[](size_t idx) {
        return data_[idx];
    }
    const T& operator[](size_t idx) const {
        return data_[idx];
    }
    

    // Операторы ввода-вывода
    template <typename U>
    friend std::ostream& operator<<(std::ostream &out, const Array<U> &obj);

    // Оператор вывода выводит массив в квадратных скобках: [el0, el1, el2, el3 ..., eln]
    // вывод начинается с открывающей квадратной скобки и заканчивается закрывающей квадратной скобкой
    // если больше одного элемента, то они выводятся через запятую с пробелом ", "
    template <typename U>
    friend std::istream& operator>>(std::istream &in, Array<U> &obj);

private:
    size_t size_;
    T* data_;
};

template <typename U>
std::ostream& operator<<(std::ostream &out, const Array<U> &obj) {
    out << '[';
    for (size_t i = 0; i < obj.size(); ++i)
    {
        if (i > 0)
            out << ", ";
        out << obj[i];
    }
    out << ']';
    return out;
}
// std::ostream& operator<<(std::ostream& os, const A& obj) {
//     os << "class A(x1=" << obj.x1 << ", " <<" x2=" << obj.x2 << ")"; 
//     return os;
// }
template <typename U>
std::istream& operator>>(std::istream &in, Array<U> &obj) {
    for (size_t i = 0; i < obj.size(); ++i)
        in >> obj[i];
    return in;
}

int main() {
    return 0;
}