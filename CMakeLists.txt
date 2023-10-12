cmake_minimum_required(VERSION 3.19)

project(
    Holt
    VERSION 0.1
    DESCRIPTION "A simple raytracer"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Environment variables
set (ROOT_DIR "${PROJECT_SOURCE_DIR}")

find_package(glm REQUIRED)
find_package(Stb REQUIRED)
find_package (Threads REQUIRED)

add_subdirectory ("${CMAKE_SOURCE_DIR}/src/core")

add_executable(holt src/main.cpp)

target_link_libraries(
    holt
    PRIVATE
        Threads::Threads
        holt_core
)
