#pragma once
#include <vector>
#include<iostream>
// Add all other required methods and fields of the class.

class Vector4D {

public:
    Vector4D();
    Vector4D(double, double, double, double);

    void printf();
    double& operator[](const int idx);
    Vector4D operator+(const Vector4D&)const;
    Vector4D& operator+=(const Vector4D&);
    Vector4D operator-(const Vector4D&)const;
    Vector4D& operator-=(const Vector4D&);
    Vector4D operator*(const Vector4D&)const;
    Vector4D operator*(const double&)const;
    Vector4D& operator*=(const Vector4D&);
    Vector4D& operator*=(const double&);
    Vector4D operator/(const Vector4D&)const;
    Vector4D& operator/=(const Vector4D&);
    bool operator ==(const Vector4D&)const;
    bool operator !=(const Vector4D&)const;
    bool operator <(const Vector4D&)const;
    bool operator <=(const Vector4D&)const;
    bool operator >(const Vector4D&)const;
    bool operator >=(const Vector4D&)const;
    bool operator!()const;
    Vector4D operator-()const;
private:
    std::vector<double> Vec;
};