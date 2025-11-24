cmake_minimum_required(VERSION 3.10)
project(ArbolSegmentos2D)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(heatmap_demo src/heatmap_demo.cpp src/TwoDim_Segment_Tree.cpp)
