file(GLOB QUIZ_SOURCE source/*.cpp)
add_library(quiz STATIC ${QUIZ_SOURCE})
target_include_directories(quiz PUBLIC include)
