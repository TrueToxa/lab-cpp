#include <iostream>

using std::cout;
using std::endl;
using std::cin;

long long int a_pow_k_mod_m(long long a, long long k, long long m){
    long long int ans = 1;
    
    a = a % m;
    
    while (k > 0) {
        // испоьзуем св-ва группы остатков m по умножению
        if (k % 2 == 1) {
            ans = (ans * a) % m;
        }
        a = (a * a) % m;
        k = k / 2;
    }
    return ans;
}

long long int sup(long long a, long long k, long long m){
    if (k==1){
        return a_pow_k_mod_m(a, 1, m);
    }
    else{
        long long int tmp = sup(a, k-1, m);
        return a_pow_k_mod_m(tmp, a, m); 
    }
}

int main() {
    long long int a, k_sup, m;
    cin >> a >> k_sup >> m;
    
    long long int ans = sup(a, k_sup, m);
    cout << ans << endl;
    
    return 0;
}