#include <iostream>

class String {
private:
    unsigned int m_size;
    char* m_buffer;
public:
    String(char ch, unsigned int size);
    ~String();
};

String::String(char ch, unsigned int size) : m_size(size), m_buffer(new char[m_size]) {
    for (unsigned int idx = 0; idx < m_size; ++idx) {
        m_buffer[idx] = ch;
    }
}
String::~String() {
    delete[] m_buffer;
}

int main() {
    String s = {'a', 15};
    return 0;
}