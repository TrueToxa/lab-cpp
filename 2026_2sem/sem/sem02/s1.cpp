#include <iostream>

int c=10;
int main(){
    int x=0;
    int idx = 1;
    for (int idx=0; idx!=10; idx++){
        std::cout<< idx << ' ';
    }
    idx *=2;
    std::cout << std::endl;
    while (true) {
        ++idx;
        std::cout<< idx << ' ';
        if (idx>100){
            break;
        }
    }

    {
        int idx = 5;
    }
    int c=0;
    std::cout<< ++c << std::endl;
    std::cout<< ++::c << ' ';

    return 0;
}