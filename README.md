# slam_train

视觉 SLAM 学习仓库 —— 跟随《视觉SLAM十四讲》(高翔)的练习代码与笔记。

## 目录结构

```
slam_train/
├── practice/          自己写的练习代码与笔记
│   └── ch3_eigen/     第3章:Eigen 几何模块练习
│       ├── ex01_basics.cpp           Eigen 基础
│       ├── ex02_rotation.cpp         旋转向量(轴角)
│       ├── ex03_gimbal_lock.cpp      万向锁
│       ├── ex04_exercises.cpp        课后习题(1/3/5/6)
│       ├── notes_coordinate_transform.md   坐标变换笔记
│       └── notes_ch3_exercises.md          课后习题笔记
└── slambook2/         《视觉SLAM十四讲》官方示例代码(参考)
```

## 构建

练习代码用 CMake 管理(`practice/CMakeLists.txt`),依赖 Eigen3:

```bash
cd practice
cmake -B build
cmake --build build
```

也可在 VSCode 中直接用「运行」按钮编译单个文件。

## 环境

- macOS (Apple Silicon) / Homebrew
- C++17,Eigen3
- VSCode + clangd

## 致谢

`slambook2/` 为《视觉SLAM十四讲》配套开源代码,版权归原作者高翔所有,
原仓库:<https://github.com/gaoxiang12/slambook2>(随仓库附 LICENSE)。
本仓库仅作个人学习用途。
