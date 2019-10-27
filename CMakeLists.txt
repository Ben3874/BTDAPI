# CMakeList.txt : CMake project for Common, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.

set(SOLUTION_NAME "BTDAPI")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

option(BTDAPI_LOG_METHODS "Displays lots of debugging messages..." ON)
option(BTDAPI_LOG_LOADING "Displays lots of debugging messages..." ON)
option(BTDAPI_LOG_DEBUG "Displays lots of debugging messages..." ON)
option(BTDAPI_LOG_WARNING "Displays lots of debugging messages..." ON)
option(BTDAPI_LOG_INFO "Displays lots of debugging messages..." ON)
option(BTDAPI_LOG_VERBOSE "Displays lots of debugging messages..." ON)

project(${SOLUTION_NAME} LANGUAGES CXX VERSION 1.0)

option(${SOLUTION_NAME}_VERBOSE ON)

add_subdirectory("Common")
add_subdirectory("BTDBAPI")
add_subdirectory("BTD5API")
add_subdirectory("BTD6API")
add_subdirectory("BTDCL")
add_subdirectory("MemoryUtils")

# TODO: Add tests and install targets if needed.
