// Should be something included here?
#include <cmath>
#include <stdexcept>
#include "vec3.hpp"

Vec3::Vec3(double r, double g, double b) : r(r), g(g), b(b){
}

Vec3::Vec3() : Vec3(0, 0, 0) {
    // ... тк делигирующий конструктор
}

double Vec3::operator[](int i) const {
    if (i==0) {return r;}
    else if (i==1) {return g;}
    else if (i==2) {return b;}
    throw std::out_of_range("Vec3"); //warning: control reaches end of non-void function [-Wreturn-type исправлено помощи открытых источников
}
double& Vec3::operator[](int i) {
    if (i==0) {return r;}
    else if (i==1) {return g;}
    else if (i==2) {return b;}
    throw std::out_of_range("Vec3");
}

Vec3& Vec3::operator+=(const Vec3& v) {
    r+=v.r;
    g+=v.g;
    b+=v.b;
    return *this;
}

Vec3& Vec3::operator*=(double t) {
    r*=t;
    g*=t;
    b*=t;
    return *this;
}

Vec3& Vec3::operator/=(double t) {
    r/=t;
    g/=t;
    b/=t;
    return *this;
}

//сначала определяем оператор /= а потом можем использовать его в операторе /; 

double Vec3::length() const {
    return std::sqrt(this->length_squared());
}

double Vec3::length_squared() const {
    return (r*r + g*g + b*b);
}

// inline std::ostream& operator<<(std::ostream& out, const Vec3& v){
//     // out << "class Vec3(r, g, b) = (" << v.r << ", " << v.g << ", " << v.b << ")";
//     // out << "class Vec3(" << v.r << ", " << v.g << ", " << v.b << ")";
//     out << "class Vec3(" << v[0] << ", " << v[1] << ", " << v[2] << ")";
//     return out;
// }