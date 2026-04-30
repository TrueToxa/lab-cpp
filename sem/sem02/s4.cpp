#include <iostream>

using std::cout;
using std::endl;

void print(int value){
    // return;
    cout << '"' << value << '"' << endl;
}

int main(){
    int long_name_of_my_favotite_variable; // = 10101; // случайное значение
    long_name_of_my_favotite_variable = 10101;
    // int& ref; //= long_name_of_my_favotite_variable;
    int& ref = long_name_of_my_favotite_variable;
    cout << ref << ' ' << long_name_of_my_favotite_variable << endl;
    
    ref += 52;
    cout << ref << ' ' << long_name_of_my_favotite_variable << endl;
    
    print(ref);
    
    return 0;
}