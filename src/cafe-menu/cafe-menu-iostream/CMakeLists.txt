# iostream library

add_library ( cafe_menu_iostream cafe_menu_iostream.cpp )
target_include_directories ( cafe_menu_iostream PUBLIC 
							 ${CMAKE_CURRENT_SOURCE_DIR}/../../../include )
#target_link_libraries ( cafe_menu_iostream_lib PRIVATE cafe_menu_core_lib )
