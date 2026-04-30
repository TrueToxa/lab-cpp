#include <iostream>

using namespace std;

int main(){
    bool ans=1;
    long int n;
    cin >> n;
    long int p=1;
    int x, y;
    while (p*10<n){
        p*=10;
    }
    // cout << p << endl;
    while (p>=10) {
        // число =  x...y, 
        //x!=y на какой-то итерации => не палиндром
        // x, y = n/p, n%10; нельзя так
        x = n/p;
        y = n%10;
        if (x!=y){
            ans=0;   
            // cout << n << " " << x << " " << y << endl;         
            break;
        }
        n = n%p/10;
        p/=100;
    }
    cout << ans << endl;

}