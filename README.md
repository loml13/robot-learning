# robot-learning

机器人技术学习与练习仓库 —— 覆盖**感知、多模态融合、导航规划**三大方向。
个人学习用途,跟随经典教材与开源项目动手实践。

## 目录结构

```
robot-learning/
├── perception/        机器人感知
│   └── visual_slam/   视觉 SLAM(《视觉SLAM十四讲》练习)
├── fusion/            多模态融合(IMU/视觉/激光融合、滤波、标定)
├── planning/          导航规划(路径规划、避障、Nav2)
└── reference/         参考资料与第三方代码
    └── slambook2/     《视觉SLAM十四讲》官方配套代码
```

## 三大方向

| 方向 | 内容 | 状态 |
|---|---|---|
| **perception** 感知 | 视觉/激光 SLAM、特征提取、传感器模型 | 进行中(ch3) |
| **fusion** 融合 | 多传感器融合、卡尔曼/粒子滤波、外参标定 | 待开始 |
| **planning** 规划 | 全局/局部路径规划、避障、运动控制 | 待开始 |

## 环境

- macOS (Apple Silicon) / Homebrew
- C++17,Eigen3;Python 3.10+
- 构建:CMake;编辑器:VSCode + clangd

各子方向的构建方式见其各自的 README。

## 致谢

`reference/slambook2/` 为《视觉SLAM十四讲》(高翔)配套开源代码,
版权归原作者所有,原仓库:<https://github.com/gaoxiang12/slambook2>。
本仓库仅作个人学习用途。
