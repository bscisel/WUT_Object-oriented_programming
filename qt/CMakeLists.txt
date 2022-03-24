set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

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
