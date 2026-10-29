#include <iostream>
#include <utility>

class String {
private:
  size_t m_size = 0;
  char *m_storage = nullptr;
  // Меняет местами параметры входной строки и исходной
  // Полезна для избежания копий кода
  void swap(String &other) {
    std::swap(m_size, other.m_size);
    std::swap(m_storage, other.m_storage);
  }
  // Устанавливает ежевичный элемент для всех значений в массиве
  // Полезна для избежания копий кода
  void assign_element(char el) {
    for (size_t idx = 0; idx < m_size; ++idx) {
        m_storage[idx] = el;
    }
  }
public:
  // Конструктор
  explicit String(size_t size = 0, char el = 'a') : m_size(size), m_storage(new char[m_size]) {
        for (std::size_t idx = 0; idx < m_size; ++idx) {
            m_storage[idx] = el;
        }
    }
  // Копирующий конструктор
  String(const String &other): m_size(other.m_size), m_storage(new char[m_size]) {
        for (std::size_t idx = 0; idx < m_size; ++idx) {
            m_storage[idx] = other.m_storage[idx];
        }
    }
  // Деструктор
  ~String() {
    delete[] m_storage;
  }
  // Оператор копирующего присваивания
  String &operator=(const String &other) noexcept {
    if (this != &other) {
        String tmp(other);
        swap(tmp);
    }
    return *this;
  }
  // Перемещающий конструктор
  String(String &&other) noexcept {
        swap(other);
  }
  // Оператор перемещающего присваивания
  String &operator=(String &&other) noexcept {
    swap(other);
    return *this;
  }
  // Оператор +=
  String &operator+=(String const &other) {
    size_t new_size = m_size + other.m_size;
    String tmp(new_size);

    for (size_t idx = 0; idx < m_size; ++idx) {
        tmp.m_storage[idx] = m_storage[idx];
    }
    for (size_t idx = 0; idx < other.m_size; ++idx) {
        tmp.m_storage[m_size + idx] = other.m_storage[idx];
    }

    swap(tmp);
    return *this;
  }
  // Внешний оператор сложения
  friend String operator+(String const &lha, String const &rha) {
    String ans(lha);
    ans += rha;
    return ans;
  }
  // Возвращает размер строки
  size_t size() const {
    return m_size;
  }
  // Возвращает элемент строки с индексом idx
  char &operator[](size_t idx) {
    return m_storage[idx];
  }
  // Операторы ввода-вывода
  friend std::ostream &operator<<(std::ostream &out, const String &obj) {
    for (size_t idx = 0; idx < obj.m_size; ++idx) {
        out << obj.m_storage[idx];
    }
    return out;
  }
  friend std::istream& operator>>(std::istream& in, String& obj) {
    std::string buffer;
    if (in >> buffer) {
      String tmp(buffer.size());
      for (size_t idx = 0; idx < buffer.size(); ++idx) {
        tmp[idx] = buffer[idx];
      }
      obj.swap(tmp);
    }
    return in;
  }
};

int main(){
  return 0;
}