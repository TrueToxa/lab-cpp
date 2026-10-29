#include <cstddef>
#include <utility>

template <typename T>
class Array {
private:
  size_t m_size = 0;
  T *m_storage = nullptr;

  void swap(Array<T> &other){  // Приватный метод для упрощения перемещения
    std::swap(m_size, other.m_size);
    std::swap(m_storage, other.m_storage);
  }
public:
  // Конструктор
  explicit Array(size_t size = 0, const T &value = T()) : m_size(size), m_storage(new T[m_size]) {
        for (std::size_t idx = 0; idx < m_size; ++idx) {
            m_storage[idx] = value;
        }
    }
  // Копирующий  конструктор
  Array(const Array &other): m_size(other.m_size), m_storage(new T[m_size]) {
        for (std::size_t idx = 0; idx < m_size; ++idx) {
            m_storage[idx] = other.m_storage[idx];
        }
    }
  //Деструктор
  ~Array() {
    delete[] m_storage;
  }

  // Оператор копирующего присваивания
  Array &operator=(Array<T>& other) noexcept {
    Array tmp(other);
    swap(tmp);
    return *this;
  }

  // Перемещающий конструктор
  Array(Array<T> &&other) noexcept {
        swap(other);
  }

  // Перемещающий оператор присваиваивания
  Array &operator=(Array<T> &&other) noexcept {
    swap(other);
    return *this;
  }
  // Возвращает размер массива
  size_t size() const {
    return m_size;
  }
  // Возвращает idx элемент массива
  T &operator[](size_t idx) {
    return m_storage[idx];
  }
};

int main() {

    return 0;
}