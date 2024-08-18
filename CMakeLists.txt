# Copyright (c) 2024 Alex Hernandez Mann
#
# Distributed under the Boost Software License, Version 1.0
# (See accompanying file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

cmake_minimum_required ( VERSION 3.14 FATAL_ERROR )

project ( cafe_menu
		  LANGUAGES CXX
  		  DESCRIPTION "A simple ordering system" )

# Optional flags
option ( CAFE_MENU_BUILD_TESTS "Build unit tests" OFF)
option ( CAFE_MENU_BUILD_EXAMPLES "Build examples" OFF)

# Add library targets
add_library( cafe_menu INTERFACE )
#add_library( cafe_menu INTERFACE src/cafe-menu/cafe-menu-core/cafe_menu_core.cpp src/cafe-menu/cafe-menu-iostream/cafe_menu_iostream.cpp )
add_library ( cafe_menu_core src/cafe-menu/cafe-menu-core/cafe_menu_core.cpp )
#target_include_directories( cafe-menu-core PUBLIC)
add_library ( cafe_menu_iostream src/cafe-menu/cafe-menu-iostream/cafe_menu_iostream.cpp )

# target_include_directories( cafe_menu INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries( cafe_menu 
		 				INTERFACE cafe-menu-core 
						INTERFACE cafe-menu-iostream )

target_include_directories( cafe_menu INTERFACE	
							$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
							$<INSTALL_INTERFACE:include/> )


# target_link_libraries( cafe_menu 
#					   INTERFACE cafe_menu_core 
#					   INTERFACE cafe_menu_iostream )

# Check to build unit tests
if ( ${CAFE_MENU_BUILD_TESTS} )
	enable_testing ()
	add_subdirectory ( test )
endif()

# Check to build example code
if ( ${CAFE_MENU_BUILD_EXAMPLES} )
	add_subdirectory ( example )
endif()

# Check to install
if ( ${CAFE_MENU_INSTALL} )
	set ( CPACK_RESOURCE_FILE_LICENSE ${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.txt )
	include ( Cpack )
endif()

#end of file
