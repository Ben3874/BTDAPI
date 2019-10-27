cmake_minimum_required (VERSION 3.13)

#
# BTD Mod loader & Tools GUI for windows.
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
VS_WINRT_EXTENSIONS TRUE
)

target_sources(${PROJECT_NAME}
	# List .cpp and .hpp files here.
	PRIVATE
	src/WinMain.cpp

	src/GUI/App.xaml
	src/GUI/MainWindows.xaml

	src/module.g.cpp
	
	src/pch.cpp
	src/pch.hpp


)

target_include_directories(${PROJECT_NAME}
PUBLIC include/${PROJECT_NAME}
PRIVATE src
)

target_link_libraries(${PROJECT_NAME}
Common
)

