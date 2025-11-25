cmake_minimum_required(VERSION 3.10)

project(student_grades)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(src)

add_executable(student-grades
    src/main.cpp
    src/Student.cpp
    src/Processor.cpp
    src/FileGenerator.cpp
    src/Timer.cpp
)
