cmake_minimum_required (VERSION 3.13)

#
# BTD Mod loader & Tools GUI for windows.
#

#
# GUI should be made with WPF and C++
# This can be achieved with C++/CLI
# Example: https://www.codeguru.com/cpp/cpp/cpp_managed/general/article.php/c16355/Using-WPF-with-Managed-C.htm
#

set(PROJECT_NAME BTDGUI)

set(${PROJECT_NAME}_VERSION_MAJOR 1)
set(${PROJECT_NAME}_VERSION_MINOR 0)

if(${SOLUTION_NAME}_VERBOSE)
	message(STATUS "Configuring ${PROJECT_NAME} ${${PROJECT_NAME}_VERSION_MAJOR}.${${PROJECT_NAME}_VERSION_MINOR}")
endif()

add_executable(WIN32 ${PROJECT_NAME} "")

set_target_properties(${PROJECT_NAME} PROPERTIES
VERSION ${${PROJECT_NAME}_VERSION_MAJOR}.${${PROJECT_NAME}_VERSION_MINOR}
)

target_sources(${PROJECT_NAME}
	# List .cpp and .hpp files here.
	PRIVATE



)

target_include_directories(${PROJECT_NAME}
PUBLIC include/${PROJECT_NAME}
PRIVATE src
)

target_link_libraries(${PROJECT_NAME}
Common
)

