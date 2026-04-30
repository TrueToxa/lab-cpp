#include <iostream>

using std::cout;
using std::endl;
using namespace std;
int main(){
    std::cout << "Hello, Me!" << ' ' << 239 << std::endl;

    int x, y = 0; float z = 0;
    x = 10 + 12;
    y = x * 5;
    z = y;
    z /= 7;
    z = y /7.f;
    z = static_cast<float>(x)/y;
    std::cout << x << ' ' << y << ' ' << z << '\n' << std::endl;

    z = 5.5;
    for (int idx = 1; idx<5; ++idx) {
        z *= 5.5;
    }

    std::cout << z << std::endl;
    
    int i = 0;

    std::cout << i << ++i << i++ << std::endl;
    x = y%10;
    std::cout << x << std::endl;
    if (x<y){
        std::cout << "X<Y" << std::endl;
    } else {
        std::cout << "X>=Y" << std::endl;
    }

    x=0;

    while (x<10) {
        ++x;
    }

    std::cin >> z;

    return 0;
}