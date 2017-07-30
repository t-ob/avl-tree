cmake_minimum_required(VERSION 3.7)
project(avl_tree)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest-build)

set(SOURCE_FILES src/main.cpp src/node.cpp src/AVLTree.cpp)
add_executable(avl_tree ${SOURCE_FILES})