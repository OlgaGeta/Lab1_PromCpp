project(main_RAII)

set(RAII_SRC_FILES
    src/main.cpp
)

add_executable(main_RAII ${RAII_SRC_FILES})
target_link_libraries(main_RAII PRIVATE RAII_lib)

set_target_properties(main_RAII PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)