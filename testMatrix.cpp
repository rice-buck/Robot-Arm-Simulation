#include <iostream>
#include <cmath>
#include "Matrix.hpp"
#include "Vector.hpp"

int main() {

    // --- Robot Params ---
    float L1 = 100;
    float L2 = 75;
    float L3 = 50;

    float theta1 = 30 * M_PI / 180.0f;
    float theta2 = -20 * M_PI / 180.0f;
    float theta3 = 45 * M_PI / 180.0f;

    // Base point
    Vector3 p0(0, 0, 1);


    // --- Build T01 ---
    float c1 = std::cos(theta1);
    float s1 = std::sin(theta1);

    float T01data[3][3] = {
        { c1, -s1, L1 * c1 },
        { s1,  c1, L1 * s1 },
        { 0,   0,  1 }
    };
    Matrix3x3 T01(T01data);


    // --- Build T12 ---
    float c2 = std::cos(theta2);
    float s2 = std::sin(theta2);

    float T12data[3][3] = {
        { c2, -s2, L2 * c2 },
        { s2,  c2, L2 * s2 },
        { 0,   0,  1 }
    };
    Matrix3x3 T12(T12data);


    // --- Build T23 ---
    float c3 = std::cos(theta3);
    float s3 = std::sin(theta3);

    float T23data[3][3] = {
        { c3, -s3, L3 * c3 },
        { s3,  c3, L3 * s3 },
        { 0,   0,  1 }
    };
    Matrix3x3 T23(T23data);


    // --- Compute cumulative transforms ---
    Matrix3x3 T02 = T01 * T12;
    Matrix3x3 T03 = T02 * T23;


    // --- Compute joint positions ---
    Vector3 p1 = T01 * p0;
    Vector3 p2 = T02 * p0;
    Vector3 p3 = T03 * p0;


    // --- Print results ---
    std::cout << "p1 = " << p1 << std::endl;
    std::cout << "p2 = " << p2 << std::endl;
    std::cout << "p3 = " << p3 << std::endl;

    std::cout << p1.data[0] << std::endl;
    std::cout << p2.data[0] << std::endl;
    std::cout << p2.data[0] << std::endl;

    std::cout << p1.data[1] << std::endl;
    std::cout << p2.data[1] << std::endl;
    std::cout << p2.data[1] << std::endl;

    return 0;
}
