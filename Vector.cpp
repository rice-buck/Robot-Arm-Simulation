#include "Vector.hpp"
#include <iostream>

Vector3::Vector3() : data{0.0, 0.0, 0.0} {}

Vector3::Vector3(float x, float y, float z) : data{x, y, z} {}

std::ostream& operator<<(std::ostream& os, const Vector3& v) {
    os << "[" << v.data[0] << ", " << v.data[1] << ", " << v.data[2] << "]";
    return os;
}