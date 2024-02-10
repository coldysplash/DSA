set(target_name test)

add_executable(${target_name})

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
)