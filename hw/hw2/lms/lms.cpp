#include <iostream>
#include <cstdint>

using std::cout;
using std::cin;
using std::endl;

uint64_t gcd(uint64_t, uint64_t);
unsigned long long redux(unsigned long long);
unsigned long long collatz_conjecture_count(unsigned long long);
bool is_powerof2(uint64_t);
bool is_square(uint64_t num);
unsigned max_true_inarow(bool const elements[], unsigned size);
int main(){
    cout << "1 " << gcd(3, 6) << endl;
    cout << "2 " << redux(999) << endl;
    cout << "3 " << collatz_conjecture_count(3) << endl;
    cout << "4 " << is_powerof2(1024) << endl;
    cout << "5 " << is_square(123) << endl;
    bool arr[] = {true, true, false, true, true, true};
    cout << "6 " << max_true_inarow(arr, 6) << endl;
    return 0;
}

//1
uint64_t gcd(uint64_t a, uint64_t b) {
    while (0!=b){
        a%=b;
        uint64_t tmp = a;
        a=b;
        b=tmp;
    }
    return a;
}

//2
unsigned long long redux(unsigned long long a) {
    unsigned long long sum = 0;
    while (a!=0){
        sum += a%10;
        a /= 10;
    }
    if (sum>9){
        auto tmp = sum;
        sum = redux(tmp);
        return sum;
    }
    else {
        return sum;
    }
}

// 3
unsigned long long collatz_conjecture_count(unsigned long long a) {
    // Code goes here;
    if (a==1){
        return 0;
    }
    else if (a%2==0){
        return collatz_conjecture_count(a/2)+1;
    }
    else {
        return collatz_conjecture_count(a*3+1)+1;
    }
}

//4 
bool is_powerof2(uint64_t num) {
    if (num == 1){
        return true;
    }
    else{
    if (num==1 or num%2==1){
        return false;
    }
    else if (num==2 or num==0){
        return true;
    }
    else{
        return is_powerof2(num/2);
    }
    }
}

//5
bool is_square(uint64_t num) {
    auto a = num/2;
    while (a*a>num){
        a=(a+num/a)/2;
    }
    if (a*a==num or (a+1)*(a+1)==num){
            return true;
        }
    return false;
}

// 6

unsigned max_true_inarow(bool const elements[], unsigned size) {
    unsigned max = 0;
    unsigned local_max = 0;
    
    for (unsigned i = 0; i < size; ++i) {
        if (elements[i] == true) {
            local_max++;
            if (local_max > max) {
                max = local_max;
            }
        } else {
            local_max = 0;
        }
    }
    
    return max;
}

// 7
char redux_array(char first, char const elements[], unsigned size) {
    char result = first;
    
    for (unsigned i = 0; i < size; ++i) {
        result = redux(result, elements[i]);
    }
    
    return result;
}

// 8
void reverse_array(int input_array[], unsigned size) {
    for (unsigned  i = 0; i < size / 2; ++i) {
        int tmp = input_array[i];
        input_array[i] = input_array[size - 1 - i];
        input_array[size - 1 - i] = tmp;
    }
}

// 9

unsigned max_unique_subarray_length(char const symbols[], unsigned size) {
    unsigned max_len = 0;
    unsigned start = 0;
    
    for (unsigned end = 0; end < size; ++end) {
        for (unsigned i = start; i < end; ++i) {
            if (symbols[i] == symbols[end]) {
                start = i + 1;
                break;
            }
        }
        
        unsigned local_len = end - start + 1;
        if (local_len > max_len) {
            max_len = local_len;
        }
    }
    
    return max_len;
}