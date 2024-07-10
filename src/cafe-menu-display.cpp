// By: Alex H Mann

#include <iostream> 
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>

#include "cafe-menu/cafe-menu.hpp"

// class menu
std::vector<menuItem> menu::getMenu(const std::string& path){
	std::vector<menuItem> tempMenuList;
 	std::fstream file(path);
 	if (file.is_open()){
    	std::string line;
		std::string strMenuPrice;
		int i = 1;
    	while (getline(file, line)){
      		std::stringstream tempStruct(line);
      		menuItem item;
      		std::getline(tempStruct, item.menuItem);
      		std::getline(file, strMenuPrice);
      		tempStruct >> strMenuPrice;
	  		item.menuPrice = stod(strMenuPrice);
	  		item.itemNum = i++;
      		tempMenuList.push_back(item);
    	}
		numOfItems = i;
    file.close();
  	}
  	else {
    	std::cout << "Your menu file can not be found." << std::endl;
  	}
	return tempMenuList;
}

void menu::displayMenu() const {
  	std::cout << "Welcome to the Basil and Thyme Cafe! Below is our current menu.\n" << std::endl;
  	std::cout << std::setw(5) << std::left << "No." 
              << std::setw(15) << std::left << "Item" 
              << std::setw(15) << std::left << "Price" 
              << std::endl;
  	int i = 1;
  	for (const auto& item : menuList){
		std::cout << std::setw(5) << std::left << i 
              	  << std::setw(15) << std::left << item.menuItem 
              	  << std::setw(15) << std::left << item.menuPrice 
              	  << std::endl;
    	i++;
	}
  	std::cout << std::endl;
}

// class order
bool order::orderInProgress(){
	startOrder();
	validateAnswer();
	while (tempInput >= -1){
		switch(tempInput){
			case 0:
				return true;
			case 1:
				orderedItems.push_back(addToOrder());
				newCustomer.answer = orderedItems.back().answer;
				break;
			default:
				continueOrder();
				break;
		}
		validateAnswer();
	}
	return false;
}

void order::startOrder(){
	std::cout << "Would you like to start an order? For 'Yes' enter (Y or y). For 'No' enter (n or N).\n";
	std::cin >> newCustomer.answer;
}

void order::validateAnswer(){
	switch (newCustomer.answer){
		case 'Y':
		case 'y':
			tempInput = 1;
			break;
		case 'N':
		case 'n':
			tempInput = 0;
			break;
		default:
			tempInput = -1;
			break;
	}
}

const customerInput order::addToOrder(){
	customerInput tempCustomerOrder;
	std::cout << "Enter the item number: ";
	std::cin >> tempCustomerOrder.choice;
	std::cout << "How many of the item would you like to order? ";
	std::cin >> tempCustomerOrder.multiple;
	std::cout << "Would you like to order another item? ";
	std::cin >> tempCustomerOrder.answer;
	return tempCustomerOrder;
}

void order::continueOrder(){
	std::cout << "Would you like to continue your order? ";
	std::cin >> newCustomer.answer;
}

void order::printReceipt() const {
	std::cout << "\nThank you for choosing Basil & Thyme Cafe to satisfy your hunger!\n"
			  << std::setw(12) << std::right << std::setprecision(2) << std::fixed
			  << "Tax: " << newReceipt.totalTax << std::endl;
  	std::cout << std::left 
              << "Amount Due: " << newReceipt.sumWithTax << "\n";
}

