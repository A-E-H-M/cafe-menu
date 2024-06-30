#include <string>
#include <vector>

#include "cafe_main.hpp"

int main(){
	menu new_menu;
  	std::string inputFile = "current_menu.txt";
  	order new_order;

  	new_menu.menuList = new_menu.getMenu(inputFile);
  	new_menu.showMenu();
  	new_order.takeOrder(new_menu.menuList);
  	new_order.calculateTax();
  	new_order.calculateFinalSum();
  	new_order.printReceipt();

  	return 0;
};
