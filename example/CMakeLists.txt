# Copyright (c) 2024 by Alexandria Hernandez Mann
#
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.txt or copy at https://www.boost.org/LICENSE_1_0.txt)

cmake_minimum_required ( VERSION 3.14 FATAL_ERROR )

# create project
project ( cafe_menu_test 
		  LANGUAGES CXX )

# add executable
add_executable ( cafe_menu_example cafe_menu_example.cpp )
target_compile_features ( cafe_menu_example PRIVATE cxx_std_20 )

#link dependencies
target_link_libraries ( cafe_menu_example PRIVATE cafe_menu )
