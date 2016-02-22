cmake_minimum_required(VERSION 2.8)
project(qlnet-tests)

set(SRC_PATH "../src")

set(SRC_LIST
#    ${CMAKE_CURRENT_SOURCE_DIR}/catch.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test_main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test_pattern.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test_patternset.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/${SRC_PATH}/nodeoutput.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test_node.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test_layer.cpp
)

add_executable(${PROJECT_NAME} ${SRC_LIST})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${PROJECT_NAME} APPEND_STRING PROPERTY COMPILE_FLAGS -Wno-undefined-inline)
