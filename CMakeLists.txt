cmake_minimum_required(VERSION 2.8)
project(qlnet)

set(SRC_LIST
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/node.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/node.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/patternset.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/patternset.cpp
)

add_executable(${PROJECT_NAME} ${SRC_LIST})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

set(PROJECT_INCLUDE_DIR include)
include_directories("${PROJECT_INCLUDE_DIR}")

add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_SOURCE_DIR}/sets ${CMAKE_CURRENT_BINARY_DIR}/sets)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)
