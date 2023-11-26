set(target_name trie)

add_library(${target_name} STATIC 
    trie/trie.cpp
    trie/trie.hpp)

target_include_directories(
    ${target_name}
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)