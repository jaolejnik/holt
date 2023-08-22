cmake_minimum_required(VERSION 3.15)

project(
    Holt
    VERSION 0.1
    DESCRIPTION "A simple raytracer"
    LANGUAGES CXX)

find_package(glm REQUIRED)
find_package(Stb REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Environment variables
set (ROOT_DIR "${PROJECT_SOURCE_DIR}")

add_subdirectory ("${CMAKE_SOURCE_DIR}/src/core")

add_executable(holt src/main.cpp)

target_link_libraries(
    holt
    PRIVATE
        holt_core
)
