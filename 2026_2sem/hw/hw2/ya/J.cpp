#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void reverse_array(int input_array[], unsigned size) {
    for (unsigned i = 0; i < size / 2; ++i) {
        int tmp = input_array[i];
        input_array[i] = input_array[size - 1 - i];
        input_array[size - 1 - i] = tmp;
    }
}

int main() {
    int n, b;
    cin >> n >> b;
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    int digits[52];  
    int rasr = 0;
    
    while (n != 0) {
        digits[rasr++] = n % b;
        n /= b;
    }
    
    reverse_array(digits, rasr);
    
    for (int i = 0; i < rasr; ++i) {
        cout << digits[i];
    }
    cout << endl;
    
    return 0;
}
