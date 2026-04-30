#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main(){
	int num;
    bool ans = true;
    cin >> num;
    while (num!=1){
        if (num%2 != 0){
            ans = false;
            break;
        }
        num /= 2;
    }
    if (ans){
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}