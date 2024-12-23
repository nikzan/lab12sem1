cmake_minimum_required(VERSION 3.30)
project(lab12sem1)

set(CMAKE_CXX_STANDARD 20)

include_directories(headers)

add_executable(lab12sem1 main.cpp
        src/sorting.cpp
        headers/sorting.h
        src/searching.cpp
        headers/searching.h
        src/fitness_center.cpp
        headers/fitness_center.h
        src/exam_results.cpp
        headers/exam_results.h
)
