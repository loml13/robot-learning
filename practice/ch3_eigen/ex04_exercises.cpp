// ch3 课后习题:旋转表示 与 Eigen 矩阵操作
//
// 本文件做需要写代码的 4 道题(第 1、3、5、6 题)。
//   第 2 题(罗德里格斯公式推导)、第 4 题(转换关系总结表)是理论题,
//   建议写进 notes_*.md 笔记,不在此文件。
// 编译运行:点 VSCode 运行按钮,或 CMake 构建 ex04_exercises。

#include <iostream>
#include <cmath>
#include <Eigen/Dense>
#include <Eigen/Geometry>

using namespace std;
using namespace Eigen;

int main() {
    // ============================================================
    // 习题 1:验证旋转矩阵是正交矩阵
    //   正交矩阵定义:R * Rᵀ = I,且 det(R) = 1
    // ------------------------------------------------------------
    // 提示:先随便构造一个旋转矩阵 R(用 AngleAxisd 转);
    //       矩阵转置 .transpose();单位阵 Matrix3d::Identity();
    //       行列式 .determinant();判断接近 0 可用 .norm() 或 isApprox()
    // TODO 1a: 构造一个旋转矩阵 R
    AngleAxisd rv(M_PI / 4, Vector3d(1, 0, 0));
    Matrix3d R = rv.toRotationMatrix();
    // TODO 1b: 计算 R * R.transpose(),打印,看是否为单位阵
    cout << R * R.transpose() << "\n";
    // TODO 1c: 打印 R.determinant(),看是否为 1
    cout << "R 的行列式 = " << R.determinant() << "\n\n";

    // ============================================================
    // 习题 3:验证四元数旋转点后,结果是虚四元数(实部为 0)
    //   把点 p 看成虚四元数 p_quat = (0, x, y, z)
    //   旋转:p' = q * p_quat * q⁻¹,验证 p' 的实部 w ≈ 0
    // ------------------------------------------------------------
    // 提示:点变四元数用 Quaterniond(0, x, y, z)(w=0 实部);
    //       四元数乘法直接用 * ;取共轭/逆用 .conjugate() 或 .inverse();
    //       结果四元数的实部用 .w() 取
    // TODO 3a: 构造旋转四元数 q(可由 AngleAxisd 来),并归一化
    Quaterniond q(0, 1, 1, 1);
    q.normalize();
    // TODO 3b: 把点 p(1,0,0) 表示成虚四元数 p_quat
    Quaterniond p_quat(0, 1, 0, 0);
    // TODO 3c: 计算 p_rotated = q * p_quat * q.inverse()
    Quaterniond p_rotated = q * p_quat * q.inverse();
    // TODO 3d: 打印 p_rotated.w()(应 ≈ 0)和虚部(x,y,z)
    cout << "p' 的实部 = " << p_rotated.w() << "\n";
    cout << "p' 的虚部 = " << p_rotated.vec().transpose() << "\n\n";


    // ============================================================
    // 习题 5:取大矩阵左上角 3×3 块,赋值为单位阵 I
    // ------------------------------------------------------------
    // 提示:动态矩阵 MatrixXd::Random(行, 列);
    //       取块 .block<行,列>(起始行, 起始列) 或 .block(i,j,p,q);
    //       .topLeftCorner<3,3>() 是取左上角的专用写法
    // TODO 5a: 构造一个大矩阵,例如 MatrixXd big = MatrixXd::Random(5,5)
    MatrixXd big = MatrixXd::Random(8, 8);
    // TODO 5b: 把它左上角 3×3 块赋值为 Matrix3d::Identity()
    big.block<3, 3>(0, 0) = Matrix3d::Identity();
    // TODO 5c: 打印整个 big,确认左上角变成了单位阵
    cout << big << "\n\n";

    // ============================================================
    // 习题 6:求解线性方程 A x = b 的几种做法
    //   A 为方阵时常用:① 直接求逆 ② QR 分解 ③ Cholesky(A 正定时)
    // ------------------------------------------------------------
    // 提示:构造可逆方阵,如 MatrixXd A = MatrixXd::Random(n,n);
    //       为保证正定可用 A = A * A.transpose();
    //       ① x = A.inverse() * b;
    //       ② x = A.colPivHouseholderQr().solve(b);
    //       ③ x = A.ldlt().solve(b);(A 对称正定)
    //       对比三种解,差值应接近 0
    // TODO 6a: 构造 A、b
    MatrixXd A = MatrixXd::Random(3, 3);
    A = A * A.transpose();
    VectorXd b = VectorXd::Random(3);
    // TODO 6b: 用直接求逆解一次
    cout << A.inverse() * b << "\n";
    // TODO 6c: 用 QR 分解解一次
    cout << A.colPivHouseholderQr().solve(b) << "\n";
    // TODO 6d: 用 Cholesky(ldlt)解一次,并对比三者结果
    cout << A.ldlt().solve(b) << "\n";


    return 0;
}
