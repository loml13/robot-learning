# 第 3 章:Eigen 几何模块

《视觉SLAM十四讲》第 3 章练习 —— 三维空间的旋转与变换表示。

## 练习代码

| 文件 | 内容 |
|---|---|
| [ex01_basics.cpp](ex01_basics.cpp) | Eigen 基础:矩阵运算、类型转换 |
| [ex02_rotation.cpp](ex02_rotation.cpp) | 旋转表示:轴角、旋转矩阵、欧拉角、变换矩阵、四元数 |
| [ex02_rotation_solution.cpp](ex02_rotation_solution.cpp) | ex02 参考答案 |
| [ex03_gimbal_lock.cpp](ex03_gimbal_lock.cpp) | 欧拉角的万向锁现象 |
| [ex04_exercises.cpp](ex04_exercises.cpp) | 课后习题 1/3/5/6(正交矩阵、四元数旋转、块操作、解方程) |

## 笔记

| 文件 | 内容 |
|---|---|
| [notes_coordinate_transform.md](notes_coordinate_transform.md) | 坐标系之间的点变换(变换链、下标接龙法) |
| [notes_ch3_exercises.md](notes_ch3_exercises.md) | 课后习题笔记:罗德里格斯推导、四种表示转换关系、代码题要点 |

## 构建运行

```bash
# CMake(在 practice/ 下)
cd .. && cmake -B build && cmake --build build
./build/ex01_basics

# 或单文件编译
c++ -std=c++17 -I/opt/homebrew/include/eigen3 ex01_basics.cpp -o ex01_basics
```

VSCode 中也可直接用「运行」按钮编译当前文件。

## 知识要点

- 五种旋转表示:旋转矩阵、轴角(`AngleAxis`)、欧拉角、变换矩阵(`Isometry3d`)、四元数(`Quaternion`)
- 罗德里格斯公式:轴角 → 旋转矩阵
- 欧拉角的万向锁问题
- 坐标变换:`Isometry3d` 同时表示旋转 + 平移
