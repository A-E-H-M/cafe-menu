# Copyright (c) 2024 by Alexandria Hernandez Mann
#
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.txt or copy at https://www.boost.org/LICENSE_1_0.txt)

cmake_minimum_required ( VERSION 3.14 FATAL_ERROR )

# create project
project ( cafe_menu_test LANGUAGES CXX )

# add executable
add_executable ( cafe_menu_test cafe_menu_test.cpp )
target_compile_features ( cafe_menu_test PRIVATE cxx_std20 )

# add dependencies
include ( ../cmake/download_cpm.cmake )

CPMAddPackage ( "gh:catchorg/Catch2@3.6.0" )

#link dependencies
target_link_libraries ( cafe_menu_test PRIVATE cafe_menu Catch2::Catch2WithMain )

enable_testing()

add_test ( NAME run_cafe_menu COMMAND cafe_menu_test )
set_tests_properties ( run_cafe_menu_test PROPERTIES PASS_REGULAR_EXPRESSION "All tests passed" ) 
