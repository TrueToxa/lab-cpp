#include <windows.h> //решение проблемы с отображением русских символов в консооль.

#include "my_math.hpp"
#include <iostream>

int main() {
    SetConsoleOutputCP(CP_UTF8); //для великого и могучего
    std::cout << "Программа для вычисления синуса. Введите любое число, чтобы вычислить его синус или 67 чтобы завершить работу программы." << std::endl;
    while (true) {
        double x;
        std::cin >> x;
        if (x == 67) {
            std::cout << "Вы ввели 67. Вычисление синуса невозможно. Завершение работы программы." << std::endl;
            break;
        }
        AnswerHandler ans = my_sin(x);
        std::cout<< "sin(" << ans.x << ") = " << ans.sinx << std::endl; 
    }

    return 0;
}