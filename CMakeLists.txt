# CMakeList.txt : CMake project for Common, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.

set(SOLUTION_NAME "BTDAPI")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

option(BTDAPI_LOG_METHODS "Displays messages at the start and end of desired methods" ON)
option(BTDAPI_LOG_METHODS_VERBOSE "Displays even more log messages at the start and end of desired methods." OFF)
option(BTDAPI_LOG_LOADING "Displays messages loading external components." ON)
option(BTDAPI_LOG_DEBUG "An equivilent use of print based debugging. "ON)
option(BTDAPI_LOG_WARNING "Displays warnings, these likely lead to unexpected behaviour" ON)
option(BTDAPI_LOG_INFO "Displays miscellaneous messages, EG: Version of API" ON)
option(BTDAPI_LOG_VERBOSE "Any debug messages that dont fit other categories go here." ON)

project(${SOLUTION_NAME} LANGUAGES CXX VERSION 1.0)

option(${SOLUTION_NAME}_VERBOSE ON)

add_subdirectory("Common")
add_subdirectory("BTDBAPI")
add_subdirectory("BTD5API")
add_subdirectory("BTD6API")
add_subdirectory("BTDCL")

# TODO: Add tests and install targets if needed.
