add_library(model
    layers.cpp
)

target_link_libraries(model
    PUBLIC
        core
)

target_include_directories(model
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)