#include <iostream>

//  различные сигнатуры
int power_sqr(int);
float power_sqr(float); 


using std::cout;
using std::endl;

int main(){
    // ++x;
    int x = 1;
    cout << x << ' ';
    cout << power_sqr(x) << ' ';
    cout << x << endl;

    float y = 1.2;
    cout << y << ' ';
    cout << power_sqr(y) << ' ';
    cout << y << endl;

    // double d = 2.1;
    // cout << d << ' ';
    // cout << power_sqr(d) << ' ';
    // cout << d << endl;

    return 0;
}

int power_sqr(int value){
    value = value*value;
    return value;
}

float power_sqr(float value){
    value = value*value;
    return value;
}
