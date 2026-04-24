cmake_minimum_required(VERSION 4.1.0)

project(voxel-engine)

find_package(glad  CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

add_executable(voxel-engine src/main.cpp)
target_link_libraries(voxel-engine PRIVATE glad::glad glfw)