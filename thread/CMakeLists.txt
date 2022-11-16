project(thread)

cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 17)

find_package(Threads REQUIRED)
add_executable(pthread_test pthread_test.cc)
add_executable(thread_test thread_test.cc)

target_link_libraries(pthread_test Threads::Threads)
target_link_libraries(thread_test Threads::Threads)
