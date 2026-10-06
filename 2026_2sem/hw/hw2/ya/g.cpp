#include <iostream>

using std::cout;
using std::endl;
using std::cin;

bool is_prime(int n){
    if (n == 2) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    if (is_prime(n)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}