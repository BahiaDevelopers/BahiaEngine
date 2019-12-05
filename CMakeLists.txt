cmake_minimum_required(VERSION 3.0)

project(BeyondEngine LANGUAGES CXX)
include(cmake/Beyond.cmake)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(modules)
add_subdirectory(applications)