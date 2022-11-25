project(cpp_practice)

cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

add_executable(constexpr_test constexpr/constexpr_test.cc)
add_executable(hash_table_with_cache mutable/hash_table_with_cache_test.cc)
add_executable(pimpl_test smart_pointer/pimpl_test.cc smart_pointer/widget.cc)
