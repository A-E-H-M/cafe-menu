#include <string>
#include <vector>

#include "cafe-menu/cafe_menu.hpp"

int main(){
	menu newMenu;
  	const std::string inputFile = "current_menu.txt";
  	order newOrder;

  	newMenu.menuList = newMenu.getMenu(inputFile);
	newMenu.displayMenu();

	newOrder.orderInProgress();
	newOrder.newReceipt.calculateFinalSum(newMenu.menuList, newOrder.orderedItems);
	newOrder.printReceipt();

  	return 0;
};