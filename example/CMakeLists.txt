# Copyright (c) 2024 by Alexandria Hernandez Mann
#
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.txt or copy at https://www.boost.org/LICENSE_1_0.txt)

cmake_minimum_required ( VERSION 3.14 FATAL_ERROR )

# create project
project ( cafe_menu_example 
		  LANGUAGES CXX )

# add executable
add_executable ( cafe_menu_example cafe_menu_example.cpp )

#link dependencies
target_link_libraries ( cafe_menu_example PUBLIC cafe_menu_core_lib cafe_menu_iostream_lib )
