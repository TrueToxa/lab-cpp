#include <iostream>

struct NodeS {
    int key = 0;
};

class NodeC {
private: //by default
    int key = 0;
    const int value = 1;

public:
    // // Bad practice
    // NodeC(int key, int value) {
    //     this->key = key;
    //     this->value = value //меняем константу
    // }
    
    NodeC(int key, int value) : key(key), value(value) {
        key = key * 2 / 3;
    } //конструктор
    explicit NodeC(int key) : NodeC(key, 1) {
    } // чтобы не попасть на неявное преобразование типов
    NodeC() = default;
    //NodeC(NodeC&other)=default; //копирующий конструктор

    void chandge_key(int new_key) {
        key = new_key;
    }

// private:
    void chandge_key_alt(int key) {
        this->key = key;
    }

    int get_key() const {
        // ++key; forbidden by "const" modifier of method
        return key;
    }

    NodeC operator+(NodeC& other) const {
        return NodeC(other.key+key, other.value +value);
    }
    // pre++
    NodeC operator++() {
        ++(this->key);
        return *this;
    }

    // post++
    NodeC operator++(int) {
        NodeC copy = NodeC(*this);
        ++(this->key);
        return copy;
    }

};

int main() {
    NodeS s = {};
    NodeC c0 = {123, -1};
    NodeC c = {};
    // NodeC c1 = 12;
    NodeC c1 = NodeC{12};
    s.key = 0;
    s.key = 0;

    c.chandge_key(-1);
    c.chandge_key_alt(-1);
    std::cout << s.key << std::endl;
    std::cout << c0.get_key() << std::endl;
    std::cout << c1.get_key() << std::endl;
    std::cout << (c0.operator+(c1)).get_key() << std::endl;
    std::cout << (c0+c1).get_key() << std::endl;

    std::cout << "*******" << std::endl;
    std::cout << c1.get_key() << std::endl;
    std::cout << "*******" << std::endl;
    std::cout << (++c1).get_key() << std::endl;
    std::cout << c1.get_key() << std::endl;
    std::cout << "*******" << std::endl;
    std::cout << (c1++).get_key() << std::endl;
    std::cout << c1.get_key() << std::endl;
    return 0;
}

//g++ example0.cpp -Wall