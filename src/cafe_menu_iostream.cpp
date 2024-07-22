#include <iostream> 
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>

#include "../include/cafe-menu/cafe_menu_iostream.hpp"

using namespace cafeMenu;

// class displayOrder
void display::setMenu(const std::string& filePath) {
 	std::fstream file(filePath);
 	if (file.is_open()){
    	std::string line;
		std::string strMenuPrice;
		int i {0};
    	while (getline(file, line)){
      		std::stringstream tempStruct(line);
      		menuItem item;
      		std::getline(tempStruct, item.menuItem);
      		std::getline(file, strMenuPrice);
      		tempStruct >> strMenuPrice;
	  		item.menuPrice = stod(strMenuPrice);
	  		item.itemNum = ++i;
			menuList.push_back(item);
    	}
    file.close();
  	}
  	else {
    	std::cout << "Your menu file can not be found." << std::endl;
  	}
}

void display::prompts(const int p) const {
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

void display::displayMenu() const {
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

void display::displayReceipt(const double& taxtotal, const double& total) {
	std::cout << std::setw(12) << std::right << std::setprecision(2) << std::fixed
			  << "Tax: " << taxtotal << std::endl;
  	std::cout << std::left 
              << "Amount Due: " << total << "\n";
	std::cout << std::endl;
}

// class order
int order::validateAnswer(const char temp) {
	switch (temp){
		case 'Y':
		case 'y':
			return 1;			
		case 'N':
		case 'n':
			return 0;
		default:
			return 2;
	}
}

customerInput order::addToOrder(const display& nDisplay) {
	customerInput tempCustomerOrder;
	nDisplay.prompts(3);
	std::cin >> tempCustomerOrder.choice;
	nDisplay.prompts(4);
	std::cin >> tempCustomerOrder.multiple;
	nDisplay.prompts(5);
	return tempCustomerOrder;
}
