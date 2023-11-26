set(target_name app)

add_executable(${target_name})

target_sources(
    ${target_name}
    PRIVATE
        app/main.cpp
)

target_link_libraries(
    ${target_name}
    PRIVATE
        trie
)