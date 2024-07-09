#include <string>
#include <vector>

#include "../include/cafe-menu/cafe-menu.hpp"

int main(){
	menu new_menu;
  	std::string inputFile = "current-menu.txt";
  	order new_order;

  	new_menu.menuList = new_menu.getMenu(inputFile);
  	new_menu.displayMenu();

	new_order.orderInProgress();
	new_order.calculateFinalSum(new_menu.menuList);
	new_order.printReceipt();

  	return 0;
};
