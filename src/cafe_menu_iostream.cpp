#include <iostream> 
#include <string>
#include <iomanip>
#include <vector>

//#include "cafe-menu/cafe_menu_iostream.hpp"
#include "../include/cafe-menu/cafe_menu_iostream.hpp"

using namespace cafeMenu;

char setAnswer(){
	char answer;
	std::cin >> answer;
	std::cin.sync();
	return answer;
}

int setChoice(){
	int choice;
	std::cin >> choice;
	std::cin.sync();
	return choice;
}

void prompts(int p) {
	switch (p){
		case 0:
			std::cout << "\nWelcome to the Basil and Thyme Cafe! Below is our current menu.\n" << std::endl;
			break;
		case 1:
			std::cout << "\nWould you like to start an order? For 'Yes' enter (Y or y). For 'No' enter (n or N).\n";
			break;
		case 2:
			std::cout << "Would you like to continue your order? ";
			break;
		case 3:
			std::cout << "Enter the item number: ";
			break;
		case 4:
			std::cout << "How many of the item would you like to order? ";
			break;
		case 5:
			std::cout << "Would you like to order another item? ";
			break;
		case 6:
			std::cout << "\nThank you for choosing Basil & Thyme Cafe to satisfy your hunger!\n";
			break;
		default:
			break;
	}
}

void displayMenu(const std::vector<menuItem>& menuList) const {
	std::cout << std::setw(5) << std::left << "No." 
              << std::setw(15) << std::left << "Item" 
              << std::setw(15) << std::left << "Price" 
              << std::endl;
	for (auto& item: menuList){
		std::cout << std::setw(5) << std::left << item.itemNum
				  << std::setw(15) << std::left << item.menuItem 
				  << std::setw(15) << std::left << item.menuPrice 
				  << std::endl;
	}
}

void displayReceipt(double& taxtotal, double& total) {
	std::cout << std::setw(12) << std::right << std::setprecision(2) << std::fixed
			  << "Tax: " << taxtotal << std::endl;
  	std::cout << std::left 
              << "Amount Due: " << total << "\n";
	std::cout << std::endl;
}

customerInput addToOrder(const display& nDisplay) {
	customerInput tempCustomerOrder;
	nDisplay.prompts(3);
	std::cin >> tempCustomerOrder.choice;
	nDisplay.prompts(4);
	std::cin >> tempCustomerOrder.multiple;
	nDisplay.prompts(5);
	return tempCustomerOrder;
}
