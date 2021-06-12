cmake_minimum_required(VERSION 3.16.3)

project(proi_project_quiz LANGUAGES CXX)

# set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

add_subdirectory(quiz)
add_subdirectory(tests)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(proi_project_quiz
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    adduserdialog.cpp
    adduserdialog.h
    adduserdialog.ui
    addcategorydialog.cpp
    addcategorydialog.h
    addcategorydialog.ui
    addquestiondialog.cpp
    addquestiondialog.h
    addquestiondialog.ui
)

target_link_libraries(proi_project_quiz PRIVATE Qt5::Widgets)
target_link_libraries(proi_project_quiz PRIVATE quiz)
