cmake_minimum_required(VERSION 3.16.3)
project(quiz)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic")
set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)

add_executable(main source/main.cpp source/question.cpp)
target_include_directories(main PRIVATE include)

add_executable(gtest tests/main.cpp tests/answer.cpp tests/question.cpp source/question.cpp)
target_include_directories(gtest PRIVATE include)
target_link_libraries(gtest GTest::GTest GTest::Main)
