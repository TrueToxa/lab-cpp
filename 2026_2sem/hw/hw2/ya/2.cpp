#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main(){
    int count=0;
	int num;
    cin >> num;
    while (num!=0){
        if (num%2==0){
            count++;
        }
        cin >> num;
    }
    cout << count << endl;
}