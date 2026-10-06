#include <iostream>

int main() {
    // hello world
    std::cout << "Hello, me!" << std::endl;
   

    // initialisation
    int a, b = 5;
    int c = 1, d = 2;
    int e(3), r(a);
    int const c1 = 1;
    std::cout << a;

    //basic types
    char ch;
    bool bl;
    int i;
    long l;
    
    //how to know type size (byte)
    std::cout <<
      sizeof(i) << " " << sizeof(int)
      << std::endl;
    
     return 0;

     //auto
     int a=1;
     auto e = a+a;
     auto ch = 'e';
     auto t = true;
     auto f = 1.f;
     auto d = 1.;


}