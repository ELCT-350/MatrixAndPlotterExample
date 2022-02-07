cmake_minimum_required(VERSION 3.10)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set(CMAKE_CXX_STANDARD 20)

project(MatrixAndPlotterTest)

add_executable(MatrixAndPlotterTest "main.cpp" "Matrix.h" "Plotter.h" )
