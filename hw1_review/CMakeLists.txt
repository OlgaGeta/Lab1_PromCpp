cmake_minimum_required(VERSION 3.20)

project("hw1_RAII_project")

set(
    CXX_STANDARD 20
)
add_compile_options(-Wall -Wpedantic -Werror)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(libsrc/RAII)
add_subdirectory(projects/main_RAII)
add_subdirectory(testsuite/libsrc/RAII)
