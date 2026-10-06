#include "vec3.hpp"
#include <iostream>
#include <cmath>

int main() {
    IVec* v1 = new Vec3(3, 4, 5);
    // (*v1) /= std::sqrt(2);
    std::cout << (*v1)[0] << " " << (*v1)[1] << " " << (*v1)[2] << std::endl;
    std::cout << v1->length_squared() << " " << v1->length() << std::endl;;
    Vec3 v2 = {-1, -2, -3};
    std::cout << v2 << std::endl;
    v2+=Vec3(2, 4, 6);
    std::cout << v2 << std::endl;
    v2*=3;
    std::cout << v2 << std::endl;
    v2/=2;
    std::cout << v2 << std::endl;
    return 0;
}

/*
\project\bin>.\VEC3.exe  
***********************
3 4 5
50 7.07107
class Vec3(-1, -2, -3)
class Vec3(1, 2, 3)
class Vec3(3, 6, 9)
class Vec3(1.5, 3, 4.5)
*/