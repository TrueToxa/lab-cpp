# Семинар 1
`python` - медленный язык программирования:
```python
%timeit for i in range(1000): i*i
# пример тестирования времени работы программы, с набором статистики
```
Вывод:
```
29.3 μs ± 5.15 μs per loop (mean ± std. dev. of 7 runs, 10,000 loops each)
```
Из-за этого, его не возможно применять для обработки больших массивов данных

## Примеры экспериментов
- alice experiment cern
- super kamiakande
- juno experiment
- калининская АЭС
- свойства белков

Для задач, где необходимо обрабатывать большое кол-во данных, используется C++.

## Базовый синтаксис

```c++
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using namespace std;

int main(){
    std::cout << "Hello, Me!" << ' ' << 239 << std::endl;

    int x, y = 0; float z = 0;
    x = 10 + 12;
    y = x * 5;
    z = y;
    z /= 7;

    std::cout << x << ' ' << y << ' ' << z << std::endl;

    return 0;
}
```

# Полезное
```c++
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using namespace std;

static_cast<double>(x)

```

## Лекция 1

@aikado

```c++

```