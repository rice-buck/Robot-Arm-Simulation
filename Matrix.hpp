#include <cmath>
#include <iostream>
#include "Vector.hpp"

#pragma once

class Matrix3x3{
private:
    float data[3][3];

public:
    //constructors
    Matrix3x3();
    Matrix3x3(float val);
    Matrix3x3(float d[3][3]);

    Vector3 operator*(const Vector3& v) const;

    Matrix3x3 operator*(const Matrix3x3& other) const;


    friend std::ostream& operator<<(std::ostream& os, const Matrix3x3& m);

};

