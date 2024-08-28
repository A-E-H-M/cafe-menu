# Copyright (c) 2024 Alex Hernandez Mann
#
# Distributed under the Boost Software License, Version 1.0
# (See accompanying file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

cmake_minimum_required ( VERSION 3.14 FATAL_ERROR )

project ( cafe_menu
		  LANGUAGES CXX
  		  DESCRIPTION "A simple point of sale system" )

# Optional flags
option ( CAFE_MENU_BUILD_TESTS "Build unit tests" OFF)
option ( CAFE_MENU_BUILD_EXAMPLE "Build example" OFF)

# Add library targets
add_library( cafe_menu src/cafe_menu_core.cpp src/cafe_menu_iostream.cpp )
target_include_directories( cafe_menu PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/cafe_menu )
target_compile_features( cafe_menu PRIVATE cxx_std_20 )

# Check to build unit tests
if ( ${CAFE_MENU_BUILD_TESTS} )
	enable_testing ()
	add_subdirectory ( test )
endif()

# Check to build example code
if ( ${CAFE_MENU_BUILD_EXAMPLE} )
	add_subdirectory ( example )
endif()

# Check to install
if ( ${CAFE_MENU_INSTALL} )
	set ( CPACK_RESOURCE_FILE_LICENSE ${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.txt )
	include ( Cpack )
endif()

#end of file
