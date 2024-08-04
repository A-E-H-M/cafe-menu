# core library

add_library ( cafe_menu_core_lib STATIC src/cafe_menu_core.cpp )
target_include_directories ( cafe_menu_core_lib STATIC ${CMAKE_CURRENT_SOURCE_DIR}/include )
