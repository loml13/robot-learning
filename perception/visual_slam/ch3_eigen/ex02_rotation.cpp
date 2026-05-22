// ch3 练习 02:旋转向量(轴角)—— 理解 AngleAxis 与罗德里格斯公式
//
// 目标:绕 Z 轴旋转 45°,用多种方式表示并互相验证。
// 填空说明:每个 TODO 写 1~几行代码;卡住了看 ex02_rotation_solution.cpp。
// 编译运行:点 VSCode 运行按钮,或 CMake 构建 ex02_rotation。

#include <iostream>
#include <cmath>
#include <Eigen/Dense>
#include <Eigen/Geometry>

using namespace std;
using namespace Eigen;

int main() {
    // ===== 1. 构造旋转向量:绕 Z 轴转 45 度 =====
    // 提示:旋转轴用 Vector3d(0,0,1);旋转角 M_PI/4;
    //       AngleAxisd 的构造是 AngleAxisd(角度θ, 单位轴n)
    // TODO 1a: 定义旋转轴 axis 和旋转角 theta
    double theta = M_PI / 4;
    Vector3d axis(0, 0, 1);
    // TODO 1b: 用 axis 和 theta 构造 AngleAxisd rot_vec
    AngleAxisd rotation_vector(theta, axis);
    // TODO 1c: cout 打印 rot_vec.angle()、rot_vec.axis().transpose()
    //          以及旋转向量 phi = theta * n
     cout << "旋转角 theta = " << rotation_vector.angle() << " rad\n";
     cout << "旋转轴 n     = " << rotation_vector.axis().transpose() << "\n";
     cout << "旋转向量 phi = theta*n = "
          << (rotation_vector.angle() * rotation_vector.axis()).transpose() << "\n\n";

    // ===== 2. 旋转向量 -> 旋转矩阵 =====
    // 罗德里格斯公式(Eigen 的 toRotationMatrix() 内部就是这个):
    //   R = cosθ·I + (1-cosθ)·n·nᵀ + sinθ·n^
    //   n^ 是单位轴 n 的反对称矩阵(叉乘矩阵):
    //        [  0   -nz   ny ]
    //        [  nz   0   -nx ]
    //        [ -ny   nx   0  ]
    // 提示:AngleAxis 有成员函数 .toRotationMatrix()
    // TODO 2: 得到 Matrix3d R,并打印
     Matrix3d R = rotation_vector.toRotationMatrix();
     cout << "旋转矩阵 = \n" << R << endl;

    // ===== 3. 用旋转向量旋转一个点 =====
    // 提示:rot_vec 和 R 都重载了 * ,可直接乘 Vector3d
    // TODO 3: 定义 v(1,0,0),分别用 rot_vec*v 和 R*v 旋转并打印
    //         (期望结果约 0.707 0.707 0)
     Vector3d v(1, 0, 0);
     cout <<"旋转向量直接乘：" << (rotation_vector * v).transpose() << endl;
     cout <<"旋转矩阵乘：" << (R * v).transpose() <<endl;


    // ===== 4. 旋转矩阵 -> 旋转向量(反解)=====
    // 提示:AngleAxisd 有 .fromRotationMatrix(R),或直接 AngleAxisd(R) 构造
    // TODO 4: 从 R 反解出旋转向量,打印它的 angle() 和 axis()
    AngleAxisd back(R);
    cout << "从旋转矩阵反解旋转向量角度和轴：" << back.angle() << ", n = " << back.axis().transpose() << endl;

    // ===== 5. 旋转矩阵 -> 欧拉角(useGeometry 涉及,ex02 原本没有)=====
    // 提示:Matrix3d 有成员函数 .canonicalEulerAngles(轴0, 轴1, 轴2)
    //       传 (2,1,0) 表示 ZYX 顺序,即 yaw-pitch-roll
    //       (书里用的旧名 .eulerAngles() 在新版 Eigen 已弃用)
    // TODO 5: 从 R 提取欧拉角 Vector3d euler,打印 euler.transpose()
     cout << "欧拉角 yaw pitch roll = " << R.canonicalEulerAngles(2, 1, 0).transpose() << endl;

    // ===== 6. 欧氏变换矩阵 Isometry3d(useGeometry 涉及,ex02 原本没有)=====
    // 提示:Isometry3d 名为 3d,实质是 4×4 齐次矩阵(旋转 R + 平移 t)
    //       Isometry3d::Identity() 初始化;.rotate(rot_vec) 设旋转;
    //       .pretranslate(Vector3d(...)) 设平移;.matrix() 看 4×4 矩阵
    // TODO 6a: 构造 Isometry3d T,绕 rot_vec 旋转,平移设成 (1, 3, 4)
    Isometry3d T = Isometry3d::Identity();
    T.rotate(rotation_vector);
    T.pretranslate(Vector3d(1, 3, 4));
    // TODO 6b: 打印 T.matrix()
    cout << "变换矩阵 T =\n" << T.matrix() << "\n";
    // TODO 6c: 用 T 变换点 v,打印结果(等价于 R*v + t)
    cout << "T作用在点v:" << (T * v).transpose() << "  (等价 R*v + t)\n\n";


    // ===== 7. 四元数 Quaterniond(useGeometry 涉及,ex02 原本没有)=====
    // 提示:Quaterniond 可由 rot_vec 或 R 直接构造:Quaterniond(rot_vec)
    //       ⚠ q.coeffs() 顺序是 (x,y,z,w),w 实部在最后
    //       q * v 旋转向量(数学上是 q·v·q⁻¹)
    // TODO 7a: 由 rot_vec 构造四元数 q,打印 q.coeffs().transpose()
    Quaterniond q(rotation_vector);
    cout << "四元数 q.coeffs (x,y,z,w) = " << q.coeffs().transpose() << "\n";
    // TODO 7b: 用 q 旋转 v,打印结果(应与第 3 步一致)
    cout << "q 旋转 v = " << (q * v).transpose() << "与第3步一致\n";

    return 0;
}
