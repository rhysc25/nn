add_executable(mlp
    mlp.cpp
)

target_link_libraries(mlp
    PRIVATE
        matrix
)