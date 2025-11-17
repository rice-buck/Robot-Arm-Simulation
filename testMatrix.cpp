#include "matrix.hpp"
#include <cmath>
#include <iostream>

int main(){
float arr1[3][3] = {{1 ,2 ,3 }, {4, 5, 6}, {7, 8, 9}};
Matrix3x3 matrix(arr1);
float p0 = cos(735* (M_PI / 180.0));
std::cout << p0;
std::cout << -sin(735* (M_PI / 180.0)) << "\n";
std::cout << (3 * cos(120 * (M_PI / 180.0))) +(2 * cos(435 * (M_PI / 180.0))) << "\n";


matrix.print();

return 0;
}