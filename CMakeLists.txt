cmake_minimum_required(VERSION 3.10)
project(ArbolSegmentos2D)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(heatmap_demo src/heatmap_demo.cpp ${SOURCES})
add_executable(main_demo main.cpp ${SOURCES})
