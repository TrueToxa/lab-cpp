#include <iostream>

int main() {
    double arr0[] = {-1, -2, -3, -4}, arr1[] = {1, 2, 3};
    // arr0 = arr1; // ошибка даже при равных длинах массива
    
    std::cout << typeid(arr0).name() << std::endl;
    std::cout << typeid(arr1).name() << std::endl;

    std::cout << arr0 << std::endl;
    std::cout << arr0 + 1 << std::endl;
    /*
    Вывод
    0x39537ffa84
    0x39537ffa88
    Сдвиг на 4 - следующая ячейка хранения int
    */
    // std::cout << arr0 << ' ' << *arr0 << '=' << arr0[0] << std::endl;
    // std::cout << arr0+1 << ' ' << *(arr0+1) << '=' << arr0[1] << std::endl;
    std::cout << arr0+1 << ' ' << *(arr0+1) << '=' << arr0[1] << std::endl;
    std::cout << arr1+5 << ' ' << *(arr1+5) << '=' << arr1[5] << std::endl;
    // память: arr1:arr1[1]:arr1[2]:arr0[0]:arr0[1]:...
    // память: 1:2:3:x:-1:-2:-3:-4: //x-пропуск
    // обр. пор. инициализации: -1;-2;-3;-4;1;2;3;
    std::cout << arr1 - arr0 << std::endl;

    // no bounds checking
    for (int idx=0; idx < 4; ++idx){
        std::cout << arr0[idx] << " " << arr1[idx] << std::endl; 
    }

    return 0;
}