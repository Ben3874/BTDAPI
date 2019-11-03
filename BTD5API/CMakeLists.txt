cmake_minimum_required (VERSION 3.13)

#
# Project for BTD5's API
#
set(PROJECT_NAME BTD5API)

set(${PROJECT_NAME}_VERSION_MAJOR 1)
set(${PROJECT_NAME}_VERSION_MINOR 0)

if(${SOLUTION_NAME}_VERBOSE)
	message(STATUS "Configuring ${PROJECT_NAME} ${${PROJECT_NAME}_VERSION_MAJOR}.${${PROJECT_NAME}_VERSION_MINOR}")
endif()

add_library(${PROJECT_NAME} SHARED "")

set_target_properties(${PROJECT_NAME} PROPERTIES
VERSION ${${PROJECT_NAME}_VERSION_MAJOR}.${${PROJECT_NAME}_VERSION_MINOR}
)

target_sources(${PROJECT_NAME}
	# List .cpp and .hpp files here.
	PUBLIC
	include/${PROJECT_NAME}/api.hpp
	include/${PROJECT_NAME}/base.hpp
	include/${PROJECT_NAME}/bloons.hpp

	PRIVATE
	src/dummy.cpp
	src/bloons.cpp
	src/base.cpp
)

target_include_directories(${PROJECT_NAME}
PUBLIC include/
PRIVATE src
)

target_link_libraries(${PROJECT_NAME}
Common
)

