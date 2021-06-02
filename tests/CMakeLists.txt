file(GLOB TESTS_SOURCE source/*.cpp)
add_executable(gtest ${TESTS_SOURCE})
target_link_libraries(gtest PRIVATE quiz)
target_link_libraries(gtest PRIVATE GTest::GTest GTest::Main)
