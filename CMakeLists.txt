cmake_minimum_required(VERSION 2.8)
project(qlnet)

set(SRC_LIST
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/nodeoutput.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/nodeoutput.inc
    ${CMAKE_CURRENT_SOURCE_DIR}/include/transferfunc.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/node.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/node.inc
    ${CMAKE_CURRENT_SOURCE_DIR}/include/layer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/layer.inc
    ${CMAKE_CURRENT_SOURCE_DIR}/include/net.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/net.inc
    ${CMAKE_CURRENT_SOURCE_DIR}/include/pattern.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/pattern.inc
    ${CMAKE_CURRENT_SOURCE_DIR}/include/patternset.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/patternset.inc
)

add_executable(${PROJECT_NAME} ${SRC_LIST})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${PROJECT_NAME} APPEND_STRING PROPERTY COMPILE_FLAGS " -ggdb")
set_property(TARGET ${PROJECT_NAME} APPEND_STRING PROPERTY COMPILE_FLAGS " -O1")

set(PROJECT_INCLUDE_DIR include)
include_directories("${PROJECT_INCLUDE_DIR}")

add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_SOURCE_DIR}/sets ${CMAKE_CURRENT_BINARY_DIR}/sets)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)
