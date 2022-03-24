cmake_minimum_required(VERSION 3.16.3)

project(proi_project_quiz LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_subdirectory(quiz)
add_subdirectory(tests)
add_subdirectory(qt)
