cmake_minimum_required (VERSION 3.13)

#
# Project for all the lib like code that's game agnostic
#
set(PROJECT_NAME Common)

set(${PROJECT_NAME}_VERSION_MAJOR 1)
set(${PROJECT_NAME}_VERSION_MINOR 0)

if(${SOLUTION_NAME}_VERBOSE)
	message(STATUS "Configuring ${PROJECT_NAME} ${${PROJECT_NAME}_VERSION_MAJOR}.${${PROJECT_NAME}_VERSION_MINOR}")
endif()

add_library(${PROJECT_NAME} SHARED "")

set_target_properties(${PROJECT_NAME} PROPERTIES
VERSION ${${PROJECT_NAME}_VERSION_MAJOR}.${${PROJECT_NAME}_VERSION_MINOR}
)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}/Core/log.hpp.in ${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}/Core/log.hpp)

target_sources(${PROJECT_NAME}
	# List .cpp and .hpp files here.
	PUBLIC
	include/${PROJECT_NAME}/Core/platform.hpp
	include/${PROJECT_NAME}/Core/stdn.hpp
	include/${PROJECT_NAME}/Core/log.hpp
	include/${PROJECT_NAME}/Core/core.hpp

	include/${PROJECT_NAME}/Steam/steamUtils.hpp

	include/${PROJECT_NAME}/Memory/LoadMemory.hpp
	include/${PROJECT_NAME}/Memory/MemoryUtils.hpp
	include/${PROJECT_NAME}/Memory/memory.hpp
	include/${PROJECT_NAME}/Memory/MappedVector.hpp

	PRIVATE
	
	src/Steam/steamUtils.cpp

	src/Memory/LoadMemory.cpp
	src/Memory/MemoryUtils.cpp
)

target_include_directories(${PROJECT_NAME}
PUBLIC include/${PROJECT_NAME}
PRIVATE src
)


