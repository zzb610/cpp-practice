cmake_minimum_required(VERSION 3.0.0)
project(smart_pointer VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

add_executable(shared_ptr_test shared_ptr_test.cc)
add_executable(weak_ptr_test weak_ptr_test.cc)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
