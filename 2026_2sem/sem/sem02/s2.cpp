#include <iostream>

//  первооопределение - forward declaration
int prefix_increment(int&);
float prefix_increment(float&); // разные функции имеют разную сигнатуру (принимаемые даннные различны)
int postfix_increment(int&);


using std::cout;
using std::endl;

int main(){
    // ++x;
    int x = 1;
    cout << x << ' ';
    cout << prefix_increment(x) << ' ';
    cout << x << endl;

    float y = 1.2;
    cout << y << ' ';
    cout << prefix_increment(y) << ' ';
    cout << y << endl;

    // double d = 2.1;
    // cout << d << ' ';
    // cout << prefix_increment(d) << ' ';
    // cout << d << endl;

    

    return 0;
}

// copy     != reference
// int vulue != int& value
int prefix_increment(int& value){
    // ++value;
    // value = value+1;
    value += 1;
    return value;
}

float prefix_increment(float& value){
    // ++value;
    // value = value+1;
    value += 1;
    return value;
}

int postfix_increment(int& value){
    int copy = value;
    // ++value;
    // value = value+1;
    value -= 1;
    return copy;
}

