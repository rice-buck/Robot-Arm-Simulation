#include "Matrix.hpp"
#include <iostream>
//default;
Matrix3x3::Matrix3x3() : data{
    {0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0}
} {}


Matrix3x3::Matrix3x3(float val) : data{
    {val, val, val},
    {val, val, val},
    {val, val, val}
} {}

Matrix3x3::Matrix3x3(float d[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            data[i][j] = d[i][j];
        }
    }
}

Vector3 Matrix3x3::operator*(const Vector3& v)const {
    Vector3 result;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; j++) {
            result.data[i] += data[i][j] * v.data[j];
        }
    }
    return result;
}

Matrix3x3 Matrix3x3::operator*(const Matrix3x3& other) const {
    float result[3][3] = {0};

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                result[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }

    return Matrix3x3(result);
}


std::ostream& operator<<(std::ostream& os, const Matrix3x3& m) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            os << m.data[i][j] << "\t";
        }
        os << std::endl;
    }
    return os;
}

