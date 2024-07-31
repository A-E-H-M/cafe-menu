#include <string>

#include "cafe_menu_example.hpp"

using namespace cafeMenu;

int main (){
	CM nCafeMenu("current_menu.txt");
	nCafeMenu.sRun();
	
	return 0;
}
