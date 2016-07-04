cmake_minimum_required(VERSION 3.5)
project(PolynomialArithmeticRedux)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Polynomial.cpp Polynomial.h)
add_executable(PolynomialArithmeticRedux ${SOURCE_FILES})