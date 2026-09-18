add_library(matrix
    matrix.cpp
)

target_include_directories(matrix
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_options(matrix PRIVATE -O0 -march=native)