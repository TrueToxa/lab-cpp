## Импорт
```python
sin = lambda x: x
from numpy import *
print(sin(10)) #!=10
```

## Область видимости переменных

Область видимости переменных находится внутри фигурных скобок.
Глобальные переменные бъявляются и могут быть вызваны с помощью :: перед именем файла

Пример:
```cpp 
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
```

Мы можем передавать в функцию либо копию переменной, либо ссылку на переменную используя `&`: `int prefix_increment(int &value)`

В функции main() можно использовать еще не определенные функции, в помощью первооопределения `forward declaration`

```cpp
int prefix_increment(int&);
int postfix_increment(int&);

int main(){}
```

В c++ используется линковщик, который соединяет различные куски кода, которые явно описаны вме нашей программы (исполняемы байткод работы, например `std::endl`)