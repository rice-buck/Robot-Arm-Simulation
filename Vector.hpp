#include <iostream>

#pragma once

class Vector3{
    public:
    float data[3];

    //constructors
    Vector3();
    Vector3(float x, float y, float z);

    friend std::ostream& operator<<(std::ostream& os, const Vector3& v);
    
};