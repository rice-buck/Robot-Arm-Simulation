#include <cmath>
#include <iostream>


using FormulaFunc = std::function<double()>;

class Matrix3x3{
private:
    float data[3][3];

public:
    //constructors
    Matrix3x3();
    Matrix3x3(float val);
    Matrix3x3(float d[3][3]);

    Vector3 operator*(const Vector3& v) const;

    friend std::ostream& operator<<(std::ostream& os, const Matrix3x3& m);

};

class Vector3{
    public:
    double data[3];

    //constructors
    Vector3();
    Vector3(float x, float y, float z);

    friend std::ostream& operator<<(std::ostream& os, const Vector3& v);
    
};