function(set_compile_options taget_name)
    if(MSVC)
        target_compile_options(${target_name} PRIVATE /W4 /WX)
    else()
        target_compile_options(${target_name} PRIVATE -Wall -Wextra -Werror -pedantic)
    endif()

    set_target_properties(
        ${target_name}
            PROPERTIES
            CXX_STANDARD 17
            CXX_STANDARD_REQUIRED ON
            CXX_EXTENSIONS OFF
    )
endfunction()

function(set_compile_options_wtype target_name link_type)
    if(MSVC)
        target_compile_options(${target_name} ${link_type} /W4 /WX /EHsc)
    else()
        target_compile_options(${target_name} ${link_type} -Wall -Wextra -Werror -pedantic)
    endif()

    set_target_properties(
        ${target_name}
        PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
    )

    if(CLANG_TIDY_EXE)
        set_target_properties(
            ${target_name}
            PROPERTIES
            CXX_CLANG_TIDY ${CLANG_TIDY_EXE}
        )
    endif()
endfunction()