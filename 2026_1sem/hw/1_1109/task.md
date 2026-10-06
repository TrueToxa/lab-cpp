# Задание, неделя 1

## Цели

- Научится работать со сборкой проектов
- Понять различия типов линковки библиотек
- Попробовать подключить сторонню библиотеку для работы

## Сборка проектов

Сборка проектов на С++ осуществляется с помощь утилиты [CMake](https://github.com/Kitware/CMake/releases/tag/v3.26.4).
CMake не лучший инструмент для сборки проектов, но самый распространенный.

<!-- ## Установка требуемых компонент для WINDOWS

1. Установите [MSYS2](https://www.msys2.org/#installation). Скачайте установщик и следуйте
инструкции на сайте
2. После установки MSYS2 требуется его запустить. После запуска MSYS2 появится соответствующая
консоль. В консоли требуется ввести следующую команду: `pacman -S gcc make cmake`
3. Проверьте работоспособность команд сразу же в консоли MSYS2. Вызовите `gcc`, `g++`, `cmake`, `make`. Вывод **не** должен говорить, что **команды не удалось найти**
4. Обновите переменные среды WINDOWS. Для этого нужно:
    - Найти *Переменные среды*/*system environment*
    - Перейти в пункт *Переменные среды*/*Environment variables*
    - В списке *Системные переменные*/*System variables* найти переменную `Path` и нажать кнопку *Изменить*/*Edit*
    - После этого нажать кнопку /*New* и добавить путь к исполняемым приложениям MSYS2.
  В конце путь обязательно содержит `\usr\bin`
5. Открываем VSCode и модифицируем файл `.vscode/settings.json`. Пути к компилятором
**могут быть другими**
```json
{
    "terminal.integrated.profiles.windows": {
    "PowerShell": {
      "source": "PowerShell",
      "icon": "terminal-powershell"
    },
    "Command Prompt": {
      "path": [
        "${env:windir}/Sysnative/cmd.exe",
        "${env:windir}/System32/cmd.exe"
      ],
      "args": [],
      "icon": "terminal-cmd"
    },
    "MSYS2": {
      "path": "C:/msys64/usr/bin/bash.exe",  // Could be another for your system
      "args": [
        "--login",
        "-i"
      ],
      "env": {
        "MSYSTEM": "MINGW64",
        "CHERE_INVOKING": "1"
      }
    }
  },
  "terminal.integrated.defaultProfile.windows": "MSYS2",  // Choose default shell for VSCode
  "cmake.cmakePath": "C:/msys64/usr/bin/cmake.exe",  // Could be another for your system
  "C_Cpp.default.compilerPath": "C:/msys64/usr/bin/g++.exe",  // Could be another for your system
}
```
6. Перезапустите VSCode
7. Откройте новый терминал в VSCode и проверьте, что вы можете запускать `gcc`, `g++`, `cmake`, `make`
8. Перейдите в точку проекта (в место содержание файла `CMakeLists.txt`) с помощью команды
`cd ...` (`...` замените на путь к проекту)
9. Запустите последовательно команды:
    - `cmake -S . -B build`
    - `cd build`
    - `make`
    - `./%APPLICATION_NAME%` (`%APPLICATION_NAME%` имя бинарного файла)
10. В дереве проекта можете проверить наличие новых файлов и директорий `build`, `bin` -->

## Задача

Требуется создать библиотеку по работе с тригонометрическими функциями. Предлагается воспользоваться
разложением функции в [ряд Тейлора](https://ru.wikipedia.org/wiki/%D0%A2%D1%80%D0%B8%D0%B3%D0%BE%D0%BD%D0%BE%D0%BC%D0%B5%D1%82%D1%80%D0%B8%D1%87%D0%B5%D1%81%D0%BA%D0%B8%D0%B5_%D1%84%D1%83%D0%BD%D0%BA%D1%86%D0%B8%D0%B8)
для реализации функций.

Тригонометрическая функция принимает на вход переменную `double` и должна возвращать структуру
`AnswerHandler`. Структура содержит два поля: значение `x` и значение функции в точке `x`.

Структура проекта следующая:
```
week01/
 ├─project/
 ├───include/
 ├─────ans_handler.hpp    <- Contains definition of AnswerHandler
 ├─────my_math.hpp        <- Contains definition of functions
 ├───src/
 ├─────ans_handler.cpp    <- Contains realization of AnswerHandler (possible empty)
 ├─────my_math.cpp        <- Contains realization of functions
 ├───CMakeLists.txt          that are defined in my_math.hpp
 └───main.cpp             <- include "my_math.hpp" and use functions
```

Шаблоны для реализации указаны ниже:


#### CMakeLists.txt
```cmake
# Please, replace ??? and %PROJECTNAME% with proper things

cmake_minimum_required(VERSION 3.10)
# ^ Minimal of version of CMake you need to begin the build

set(CMAKE_C_COMPILER gcc)
# ^ Variable of path to C compiler
set(CMAKE_CXX_COMPILER g++)
# ^ Variable of path to C++ compiler
project(%YOURPROJECTNAME%Project)
# ^ Name of project

message(INFO:\ ${%YOURPROJECTNAME%_SOURCE_DIR})
# ^ Log message
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${%YOURPROJECTNAME%_SOURCE_DIR}/bin)
# ^ Directory where store build of project

include_directories(???/)
# ^ Directory with headers to be included (like -I option of compiler)

add_executable(%YOURPROJECTNAME% main.cpp src/???) 
# ^ Create executable with sources
```

#### ans_handler.hpp
```cpp
// Should be something included here?
// Should be added macro variable?
struct AnswerHandler {
	...;
};
```

#### ans_handler.cpp
```cpp
// Should be something included here?
```

#### my_math.hpp
```cpp
// Should be something included here?
// Should be added macro variable?
??? my_sin(double x);
```

#### my_math.cpp
```cpp
// Should be something included here?
??? my_sin(double x) {
	...;
}
```