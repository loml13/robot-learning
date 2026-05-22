// ch3 练习 03:万向锁 —— 欧拉角在 pitch=90° 时丢失一个自由度
#include <iostream>
#include <cmath>
#include <Eigen/Dense>
#include <Eigen/Geometry>

using namespace std;
using namespace Eigen;

// ZYX 顺序(yaw-pitch-roll)欧拉角 -> 旋转矩阵
Matrix3d euler2R(double yaw, double pitch, double roll) {
    return (AngleAxisd(yaw,   Vector3d::UnitZ())
          * AngleAxisd(pitch, Vector3d::UnitY())
          * AngleAxisd(roll,  Vector3d::UnitX())).toRotationMatrix();
}

int main() {
    const double D = M_PI / 180.0;   // 角度 -> 弧度

    // ===== 正常情况:pitch = 30°,三个角各自独立 =====
    cout << "=== 正常:pitch = 30° ===\n";
    Matrix3d Ra = euler2R(10 * D, 30 * D, 40 * D);
    Matrix3d Rb = euler2R(50 * D, 30 * D, 80 * D);
    cout << "(yaw=10,roll=40) vs (yaw=50,roll=80) 旋转矩阵差 = "
         << (Ra - Rb).norm() << "\n";
    cout << "-> 不为 0,两组角是两个不同的旋转,正常\n\n";

    // ===== 万向锁:pitch = 90° =====
    cout << "=== 万向锁:pitch = 90° ===\n";
    Matrix3d Rc = euler2R(10 * D, 90 * D, 40 * D);   // roll - yaw = 30
    Matrix3d Rd = euler2R(50 * D, 90 * D, 80 * D);   // roll - yaw = 30
    cout << "(yaw=10,roll=40) vs (yaw=50,roll=80) 旋转矩阵差 = "
         << (Rc - Rd).norm() << "\n";
    cout << "-> 接近 0!两组完全不同的欧拉角,却是同一个旋转\n";
    cout << "   说明 yaw 和 roll 合体了,只剩 (roll-yaw) 这一个自由度\n\n";

    // ===== 反解的不唯一 =====
    cout << "=== 从锁住的 R 反解欧拉角 ===\n";
    Vector3d e = Rc.canonicalEulerAngles(2, 1, 0) / D;
    cout << "本来用 (yaw=10, pitch=90, roll=40) 生成的 R,\n";
    cout << "eulerAngles 反解回来却得到: " << e.transpose() << "\n";
    cout << "-> 反解结果未必等于原始输入,因为解有无穷多组\n";

    return 0;
}
