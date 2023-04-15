project(RAII)

set(RAII_SRC_FILES
    src/File.cpp
)

add_library(RAII_lib STATIC ${RAII_SRC_FILES})
