add_executable(
  list_test
  list.cpp
)

target_link_libraries(
  list_test
  GTest::gtest_main
  list
)

target_include_directories(
  list_test
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/
)

include(GoogleTest)
gtest_discover_tests(list_test)