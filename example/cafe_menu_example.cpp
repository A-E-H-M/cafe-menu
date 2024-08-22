#include <iostream>
#include <string>

#include "cafe_menu_core.hpp"
#include "cafe_menu_iostream.hpp"

using namespace cafe_menu;

int main(int argc, char* argv[]) {

	std::string user_menu {"current_menu.txt"};

	display_menu(set_menu(user_menu));

	return 0;

}
