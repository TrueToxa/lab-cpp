// Should be something included here?
// Should be added macro variable?
#pragma once
class IVec {
    // [public/private]:  // Choose
    //     ???;
    public:  // Choose  
        virtual double operator[](int i) const = 0;      // return i-th element of vector
        virtual double& operator[](int i) = 0;           // return i-th element of vector

        //virtual  IVec& operator+=(const IVec& v) = 0;
        //virtual  IVec& operator*=(double t) = 0;
        //virtual  IVec& operator/=(double t) = 0;

        virtual double length() const = 0;               // return length of vector in Euclidean metric
        virtual double length_squared() const = 0;       // return length of vector in Euclidean metricvirtual 

     ~IVec() = default;
};

