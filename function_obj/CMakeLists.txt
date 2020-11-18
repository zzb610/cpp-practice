cmake_minimum_required(VERSION 3.0.0)
project(function_obj VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(function_obj main.cpp less_than.cc)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
