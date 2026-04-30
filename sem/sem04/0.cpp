#include <iostream>

double buble[4'000'000] = {0}; //статическая память

int main() {
    // нельзя
    // int array[4'000'000] = {0}; // -> 15 Mb // динамическая память
    int array[1'000'000] = {0}
    return 0;
}