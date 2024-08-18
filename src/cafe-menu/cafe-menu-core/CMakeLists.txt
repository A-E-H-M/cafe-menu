# core library

add_library ( cafe_menu_core cafe_menu_core.cpp )
target_include_directories ( cafe_menu_core PUBLIC 
							 ${CMAKE_CURRENT_SOURCE_DIR}/../../../include )
