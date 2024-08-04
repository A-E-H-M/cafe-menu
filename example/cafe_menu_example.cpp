#include <iostream>
#include <string>

//#include "../cafe-menu-core/include/cafe_menu_core.hpp"
//#include "../cafe-menu-iostream/include/cafe_menu_iostream.hpp"
#include "cafe_menu_core.hpp"
#include "cafe_menu_iostream.hpp"

using namespace cafeMenu;

int main (){
	
	displayMenu(setMenu("current_menu.txt"));

	return 0;

}
