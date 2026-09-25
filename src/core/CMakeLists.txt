add_library(core
    matrix.cpp
)

target_include_directories(core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_options(core PRIVATE -O0 -march=native)