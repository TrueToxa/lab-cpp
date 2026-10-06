#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main(){
    int year;
    cin >> year;
    if (year%400==0 or (year%4==0 and !(year%100==0))){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}