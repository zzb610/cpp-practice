cmake_minimum_required(VERSION 3.0.0)
project(triangular VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(triangular main.cpp triangular.cc triangular_iterator.cc)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
