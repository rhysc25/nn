add_executable(matrix)

target_sources(matrix
    PRIVATE
        matrix.cpp
)

target_compile_options(matrix PRIVATE -O0 -march=native)