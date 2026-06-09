cmake_minimum_required(VERSION 3.16)

project(bf_compiler)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(qt_test main.cpp bf-compiler.cpp)

target_link_libraries(qt_test Qt6::Widgets)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)