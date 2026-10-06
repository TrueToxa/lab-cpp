# Задание, неделя 3

## Цели

- Написать простой класс
- Реализовать несколько методов класса в разных модификаторов доступа
- Написать еще один проект с разделенным кодом

## Сборка проектов

Сборка проектов на С++ осуществляется с помощь утилиты [CMake](https://github.com/Kitware/CMake/releases/tag/v3.26.4).
CMake не лучший инструмент для сборки проектов, но самый распространенный.

## Задача

Требуется создать библиотеку для работы с трехмерными векторами, которые представляют `(r, g, b)` тройку.

Структура проекта следующая:
```
week01/
 ├─project/
 ├───include/
 ├─────ivec.hpp               <- Contains definition of IVec class (NOTE: extra points)
 ├─────vec3.hpp               <- Contains definition of Vec3 class
 ├───src/
 ├─────ivec.cpp               <- Contains realization of IVec (...) (NOTE: extra points)
 ├─────vec3.cpp               <- Contains realization of Vec3 (constructor, methods)
 ├───CMakeLists.txt             
 └───main.cpp                 <- includes "vec3.hpp", "transformations.hpp" and uses functions
```

**Внимание**: в базовой версии задание **не** требуется реализация интерфейса.

**Дополнительное задание**: создайте `IVec`, который будет задавать интерфейс для векторов.
Унаследуйте свои реализации от указанного интерфейса.
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

#### ivec.hpp

```cpp
// Should be something included here?
// Should be added macro variable?
class IVec {
    [public/private]:  // Choose
        ???;
    [public/private]:  // Choose  
        ??? virtual operator[](int i) const = 0;      // return i-th element of vector
        ???& virtual operator[](int i) = 0;           // return i-th element of vector

        vec3& virtual operator+=(const vec3& v) = 0;
        vec3& virtual operator*=(double t) = 0;
        vec3& virtual operator/=(double t) = 0;

        ??? virtual length() const = 0;               // return length of vector in Euclidean metric
        ??? virtual length_squared() const = 0;       // return length of vector in Euclidean metric
};

```

#### ivec.cpp

```cpp
// Should be something included here?
// Should be added macro variable?
```


#### vec3.hpp
```cpp
// Should be something included here?
// Should be added macro variable?
class Vec3 {
    [public/private]:  // Choose
        ???;
    [public/private]:  // Choose  
        Vec3(double x, double y, double z);
        Vec3();                     // must be based on Vec3(int x, int y, int z)

        ??? operator[](int i) const;      // return i-th element of vector
        ???& operator[](int i);           // return i-th element of vector

        vec3& operator+=(const vec3& v);
        vec3& operator*=(double t);
        vec3& operator/=(double t);

        ??? length() const;               // return length of vector in Euclidean metric
        ??? length_squared() const;       // return length of vector in Euclidean metric
};

inline std::ostream& operator<<(std::ostream& out, const vec3& v);
```

#### vec3.cpp
```cpp
// Should be something included here?

Vec3::Vec3(double x, double y, double z) {
    // ...
}

Vec3::Vec3() /*smth here*/ {
    // ...
}

??? Vec3::operator[](int i) const {
    // ...
}
???& Vec3::operator[](int i) {
    // ...
}

vec3& Vec3::operator+=(const vec3& v) {
    // ...
}

vec3& Vec3::operator*=(double t) {
    // ...
}

vec3& Vec3::operator/=(double t) {
    // ...
}

??? Vec3::length() const {
    // ...
}

??? Vec3::length_squared() const {
    // ...
}
```
