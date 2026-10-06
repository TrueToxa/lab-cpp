#include <iostream>

class A {
private:
    int x1 = 0; 
    int x2 = 0;
public:
    A(int x1, int x2) : x1(x1), x2(x2) {
    }
    friend std::ostream& operator<<(std::ostream& os, const A& obj);
    friend A operator+(const A& lhv,const A& rhv) ;
};

std::ostream& operator<<(std::ostream& os, const A& obj) {
    os << "class A(x1=" << obj.x1 << ", " <<" x2=" << obj.x2 << ")"; 
    return os;
}

A operator+(const A& lhv,const A& rhv) {
    return A(lhv.x1+rhv.x1, lhv.x2+rhv.x2);
}

int main() {
    A my_first = {1, 1};
    A a1 = {1, 2};
    A a2 = {3, 4};
    std::cout << my_first << std::endl;
    std::cout << a1 << a2 << a1+a2 << std::endl;
    return 0;
}