#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int log2(int x){
    int p = 0;
    int power = 1;  // 2^p
    
    while (power * 2 <= x) {
        power *= 2;
        p++;
    }
    
    return p;
}

int main(){
    int n;
    int x;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        cin >> x;
        cout << log2(x) << endl;
    }
    
    return 0;
}