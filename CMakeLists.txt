# Copyright (c) 2024 Alex Hernandez Mann
#
# Distributed under the Boost Software License, Version 1.0
# (See accompanying file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

cmake_minimum_required ( VERSION 3.14 FATAL_ERROR )

project ( cafe_menu
		  LANGUAGES CXX
  		  DESCRIPTION "A simple ordering system" )

option ( CAFE_MENU_BUILD_TESTS "Build unit tests" OFF)
option ( CAFE_MENU_BUILD_EXAMPLES "Build examples" OFF)
#option ( CAFE_MENU_INSTALL "Install header only library" OFF)

# add library
add_library ( cafe_menu INTERFACE )
add_library ( cafe_menu_core INTERFACE src/cafe_menu_core.cpp)
add_library ( cafe_menu_iostream INTERFACE src/cafe_menu_iostream.cpp)

# configure library target
target_include_directories ( cafe_menu_core INTERFACE
							 $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
					 		 $<INSTALL_INTERFACE:include/> )
target_include_directories ( cafe_menu_iostream INTERFACE
							 $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
					 		 $<INSTALL_INTERFACE:include/> )

target_compile_features ( cafe_menu INTERFACE cxx_std_20 )

# check to build unit tests
if ( ${CAFE_MENU_BUILD_TESTS} )
	enable_testing()
	add_subdirectory ( test )
endif()

# check to build example code
if ( ${CAFE_MENU_BUILD_EXAMPLES} )
	add_subdirectory ( example )
endif()

# check to install
if ( ${CAFE_MENU_INSTALL} )
	set ( CPACK_RESOURCE_FILE_LICENSE ${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.txt )
	include ( Cpack )
endif()

#end of file
