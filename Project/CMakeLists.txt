cmake_minimum_required(VERSION 3.12)
project(Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(Project solution/solution.cpp solution/unit_tests.cpp main_tests.cpp solution/solution.hpp)
