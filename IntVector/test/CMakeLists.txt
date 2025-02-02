set(target_name test)

add_executable(${target_name} test/test.cpp)

include(CompileOptions)
set_compile_options(${target_name})

target_sources(
    ${target_name}
    PRIVATE
        test/test.cpp
)

include_directories(${GTEST_INCLUDE_DIRS})

target_link_libraries(
    ${target_name}
    GTest::gtest_main
    IntVector
)
include(GoogleTest)
gtest_discover_tests(${target_name})