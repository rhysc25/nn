add_executable(nn
    mlp.cpp
)

target_link_libraries(nn
    PRIVATE
        model
)