set(target_name IntVector)

add_library(${target_name} INTERFACE
    IntVector.hpp
)

include(CompileOptions)
set_compile_options_wtype(${target_name} INTERFACE)

target_include_directories(
    ${target_name}
    INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}
)