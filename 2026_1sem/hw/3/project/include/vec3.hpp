// Should be something included here?
#pragma once
#include <iostream>
#include "ivec.hpp"
// Should be added macro variable?
class Vec3 : public IVec {
    private:  // Choose
        double r;
        double g;
        double b;
    public:  // Choose  
        Vec3(double r, double g, double b);
        Vec3();                     // must be based on Vec3(int x, int y, int z)

        double operator[](int i) const override;      // return i-th element of vector
        double& operator[](int i) override;           // return i-th element of vector

        Vec3& operator+=(const Vec3& v);
        Vec3& operator*=(double t);
        Vec3& operator/=(double t);

        double length() const override;               // return length of vector in Euclidean metric
        double length_squared() const override;       // return length of vector in Euclidean metric

        // friend std::ostream& operator<<(std::ostream& out, const Vec3& v);
};

inline std::ostream& operator<<(std::ostream& out, const Vec3& v) {
    
    out << "class Vec3(" << v[0] << ", " << v[1] << ", " << v[2] << ")";
    return out;
}
