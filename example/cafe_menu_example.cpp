#include <iostream>
#include <string>

#include "cafe_menu_core.hpp"
#include "cafe_menu_iostream.hpp"

using namespace cafe_menu;

int main(){
	
	display_menu(set_menu("current_menu.txt"));

	return 0;

}
