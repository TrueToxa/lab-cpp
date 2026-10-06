#include <iostream>
using namespace std;

//передача в функцию
void print_arr(int* const arr, int size) {
    for(int idx = 0; idx<size; idx++) {
        cout << arr[idx] << " = " << *(arr+idx) << endl;
        // про работу с указателями
    }
    // arr = nullptr;
    return;
}
int main() {
    int n;
    cin >> n;
    int* arr = new int[n] {0}; // можем объявлять не зная размер перед инициализацией //{0} - нули по умолчанию
    for(int idx = 0; idx<n; idx++) {
        cin >> arr[idx];
    }
    int* arr1 = new int(n); // можем объявлять не зная размер перед инициализацией
    for(int idx = 0; idx<n; idx++) {
        cin >> arr1[idx];
    }
    
    print_arr(arr, n);
    print_arr(arr, n*2); // не как в стеке, а в случаеное место, поэтому не попадаем в arr
    
    delete[] arr; // избегаем утечек памяти, когда в куче место зарезервировано, а указатель на память теряется
    delete[] arr1;
}