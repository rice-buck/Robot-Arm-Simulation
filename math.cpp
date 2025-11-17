#include "math.hpp"
#include <cmath>
#include <iostream>

Matrix3x3::Matrix3x3() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            data[i][j] = []() { return 0.0; };
        }
    }
}

Matrix3x3::Matrix3x3(FormulaFunc arr[3][3]){
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j){
            elements[i][j] = arr[i][j];
        }
    }
}

void Matrix3x3::print() const {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << elements[i][j] << " ";
        }
        std::cout << std::endl;
    }
}