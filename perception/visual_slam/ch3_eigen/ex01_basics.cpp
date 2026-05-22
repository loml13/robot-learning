// ch3 练习 01:Eigen 基础 —— 矩阵运算、线性方程、旋转表示
#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Geometry>


using namespace Eigen;

int main(int argc, char** argv) {
    Matrix<float, 2, 3>matrix_23;
    Vector3d v_3d;
    Matrix<float, 3, 1> vd_3d;
    Matrix3d matrix_33 = Matrix3d::Zero();
    Matrix<double, Dynamic, Dynamic> matrix_dynamic;

    matrix_23 << 1, 2, 3,
                 4, 5, 6;
    v_3d << 7, 8, 9;
    std::cout << "matrix 2x3 from 1 to 6: \n" << matrix_23 << std::endl;
    std::cout << "vector 3d: \n" << v_3d << std::endl;

    Matrix<double, 2, 1> result = matrix_23.cast<double>() * v_3d;
    std::cout << "matrix 2x3 * vector 3d: \n" << result << std::endl;
    std::cout<< matrix_23.trace() << std::endl;
    std::cout<<matrix_23.transpose() << std::endl; 
    return 0;

}