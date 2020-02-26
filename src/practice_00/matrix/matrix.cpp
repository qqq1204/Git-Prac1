#include "practice_00/matrix/matrix.h"
#include <iostream>



int main(int argc, char *argv[])
{
    using namespace practice_00::matrix;
    Matrix<double, 3, 3> m1({1,2,1,2,1,2,1,2,1});
    Matrix<double, 3, 3> m2({2,1,2,1,2,1,2,1,2});
    std::cout << std::string(m1+m2) << std::endl;
    m1.SetIdentity();
    m2.SetZero();
    std::cout << std::string(m1+m2) << std::endl;
    return 0;
}