set(target_name list)

add_library(${target_name} INTERFACE
    list.hpp
)

include(CompileOptions)
set_compile_options(${target_name} INTERFACE)

target_include_directories(
    ${target_name}
    INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}
)