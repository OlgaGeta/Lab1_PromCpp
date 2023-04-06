project(RAII_SRC_test)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(RAII_TEST_SRC_FILES
    src/test.cpp
)

add_executable(RAII_SRC_test ${RAII_TEST_SRC_FILES})
target_link_libraries(RAII_SRC_test PRIVATE RAII_lib)


target_include_directories(RAII_SRC_test PRIVATE ${CMAKE_SOURCE_DIR}/third-party/googletest/googletest/include)
set_target_properties(RAII_SRC_test PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
