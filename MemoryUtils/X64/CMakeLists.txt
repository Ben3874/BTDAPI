cmake_minimum_required (VERSION 3.13)

#
# BTD Command Line 
#
set(PROJECT_NAME MEMX64)

set(${PROJECT_NAME}_VERSION_MAJOR 1)
set(${PROJECT_NAME}_VERSION_MINOR 0)

if(${SOLUTION_NAME}_VERBOSE)
	message(STATUS "Configuring ${PROJECT_NAME} ${${PROJECT_NAME}_VERSION_MAJOR}.${${PROJECT_NAME}_VERSION_MINOR}")
endif()

add_library(${PROJECT_NAME} STATIC "")

set_target_properties(${PROJECT_NAME} PROPERTIES
VERSION ${${PROJECT_NAME}_VERSION_MAJOR}.${${PROJECT_NAME}_VERSION_MINOR}
)

target_sources(${PROJECT_NAME}
	# List .cpp and .hpp files here.
	PUBLIC
	include/${PROJECT_NAME}/LoadMemory.hpp
)

target_include_directories(${PROJECT_NAME}
PUBLIC include
PRIVATE src
)

target_link_libraries(${PROJECT_NAME}
Common
MemCommon
)

