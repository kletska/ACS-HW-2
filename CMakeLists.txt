# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(task LANGUAGES CXX)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/bin")

set(BINARY_DIR "${CMAKE_BINARY_DIR}")

# Source files list
set(SOURCE_FILES
    # Headers
    ./src/rnd.h
    ./src/transport.h
    ./src/plain.h
    ./src/ship.h
    ./src/train.h
    ./src/container.h

    # Sources
    ./src/transport.cpp
    ./src/plain.cpp
    ./src/ship.cpp
    ./src/train.cpp
    ./src/container.cpp
    ./src/main.cpp
)

add_executable(task ${SOURCE_FILES})
