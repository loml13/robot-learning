// ch3 练习 02【参考答案】:旋转向量(轴角)—— 理解 AngleAxis 与罗德里格斯公式
// 卡住时再看这里;先尝试自己写 ex02_rotation.cpp
#include <iostream>
#include <cmath>
#include <Eigen/Dense>
#include <Eigen/Geometry>

using namespace std;
using namespace Eigen;

int main() {
    // ===== 1. 构造旋转向量:绕 Z 轴转 45 度 =====
    // AngleAxisd(角度θ, 单位轴n) —— 注意 θ 和 n 是分开传的两个参数
    Vector3d axis(0, 0, 1);            // 旋转轴 n,必须是单位向量
    double theta = M_PI / 4;           // 旋转角 θ = 45°
    AngleAxisd rot_vec(theta, axis);

    cout << "旋转角 theta = " << rot_vec.angle() << " rad\n";
    cout << "旋转轴 n     = " << rot_vec.axis().transpose() << "\n";
    cout << "旋转向量 phi = theta*n = "
         << (rot_vec.angle() * rot_vec.axis()).transpose() << "\n\n";

    // ===== 2. 旋转向量 -> 旋转矩阵 =====
    // 罗德里格斯公式(Eigen 的 toRotationMatrix() 内部就是这个):
    //   R = cosθ·I + (1-cosθ)·n·nᵀ + sinθ·n^
    //   n^ 是单位轴 n 的反对称矩阵(叉乘矩阵)
    Matrix3d R = rot_vec.toRotationMatrix();
    cout << "转成旋转矩阵 R =\n" << R << "\n\n";

    // ===== 3. 用旋转向量旋转一个点 =====
    Vector3d v(1, 0, 0);
    cout << "(1,0,0) 绕Z转45度:\n";
    cout << "  旋转向量直接乘: " << (rot_vec * v).transpose() << "\n";
    cout << "  旋转矩阵乘:     " << (R * v).transpose() << "\n";
    cout << "  期望值约:       0.707 0.707 0\n\n";

    // ===== 4. 旋转矩阵 -> 旋转向量(反解)=====
    AngleAxisd back;
    back.fromRotationMatrix(R);
    cout << "从 R 反解回旋转向量: theta = " << back.angle()
         << ", n = " << back.axis().transpose() << "\n\n";

    // ===== 5. 旋转矩阵 -> 欧拉角 =====
    // 新版 Eigen 把 eulerAngles() 弃用了,改用 canonicalEulerAngles()
    Vector3d euler = R.canonicalEulerAngles(2, 1, 0);   // ZYX = yaw-pitch-roll
    cout << "yaw pitch roll = " << euler.transpose() << "\n\n";

    // ===== 6. 欧氏变换矩阵 Isometry3d =====
    Isometry3d T = Isometry3d::Identity();     // 实质是 4×4 齐次矩阵
    T.rotate(rot_vec);                         // 设旋转
    T.pretranslate(Vector3d(1, 3, 4));         // 设平移
    cout << "变换矩阵 T =\n" << T.matrix() << "\n";
    cout << "T 变换点 v = " << (T * v).transpose() << "  (等价 R*v + t)\n\n";

    // ===== 7. 四元数 Quaterniond =====
    Quaterniond q(rot_vec);                    // 由轴角构造
    cout << "四元数 q.coeffs (x,y,z,w) = " << q.coeffs().transpose() << "\n";
    cout << "q 旋转 v = " << (q * v).transpose() << "  (应与第3步一致)\n";

    return 0;
}
