cmake_minimum_required(VERSION 3.10)
project(slam_practice)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# 生成 compile_commands.json,让 VSCode + clangd 不再飘红
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Eigen3 REQUIRED)

# ---- ch3 Eigen 练习 ----
# 现代 CMake:直接 link imported target,自动带上头文件路径
add_executable(ex01_basics ch3_eigen/ex01_basics.cpp)
target_link_libraries(ex01_basics Eigen3::Eigen)

add_executable(ex02_rotation ch3_eigen/ex02_rotation.cpp)
target_link_libraries(ex02_rotation Eigen3::Eigen)

add_executable(ex03_gimbal_lock ch3_eigen/ex03_gimbal_lock.cpp)
target_link_libraries(ex03_gimbal_lock Eigen3::Eigen)

add_executable(ex04_exercises ch3_eigen/ex04_exercises.cpp)
target_link_libraries(ex04_exercises Eigen3::Eigen)
