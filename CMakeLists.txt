cmake_minimum_required(VERSION 3.30)
project(advent_of_code_2024)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(.)
include_directories(util)
include_directories("day 1")

add_executable(advent_of_code_2024
    "day 1/locations.cpp"
        util/util.cpp
)
