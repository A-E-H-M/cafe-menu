// By: Alex H Mann

#include <iostream> 
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>

#include "cafe-menu/cafe-menu.hpp"

// class menu
menu::menu(){};

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

void menu::displayMenu(){
  	std::cout << "Welcome to the Basil and Thyme Cafe! Below is our current menu. \n" << std::endl;
  	std::cout << std::setw(5) << std::left << "No." 
              << std::setw(15) << std::left << "Item" 
              << std::setw(15) << std::left << "Price" 
              << std::endl;
  	int i = 1;
  	for (auto& item : menuList){
		std::cout << std::setw(5) << std::left << i 
              	  << std::setw(15) << std::left << item.menuItem 
              	  << std::setw(15) << std::left << item.menuPrice 
              	  << std::endl;
    	i++;
	}
  	std::cout << std::endl;
}

menu::~menu(){};

// class order
order::order(){};

bool order::orderInProgress(){
	startOrder();
	validateAnswer();
	while (tempInput >= -1){
		switch(tempInput){
			case 0:
				return true;
			case 1:
				orderedItems.push_back(addToOrder());
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
	std::cin >> new_customer.answer;
}

void order::validateAnswer(){
	switch (new_customer.answer){
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

struct customerInput order::addToOrder(){
	customerInput tempCustomerOrder;
	std::cout << "Enter the item number: ";
	std::cin >> tempCustomerOrder.choice;
	std::cout << "How many of the item would you like to order? ";
	std::cin >> tempCustomerOrder.multiple;
	std::cout << "Would you like to order another item? ";
	std::cin >> tempCustomerOrder.answer;
	new_customer.answer = tempCustomerOrder.answer;
	return tempCustomerOrder;
}

void order::continueOrder(){
	std::cout << "Would you like to continue your order? ";
	std::cin >> new_customer.answer;
}

void order::printReceipt(){
	std::cout << "\nThank you for choosing Basil & Thyme Cafe to satisfy your hunger!\n"
			  << std::setw(12) << std::right << std::setprecision(2) << std::fixed
			  << "Tax: " << new_receipt.totalTax << std::endl;
  	std::cout << std::left 
              << "Amount Due: " << new_receipt.sumWithTax << "\n";
}

double order::calculateFinalSum(std::vector<menuItem>& menuList){
	for (auto& selectedItem: orderedItems){
		new_receipt.sum = new_receipt.sum + calculateLineItem(selectedItem, menuList);
	}
	new_receipt.totalTax = calculateTax();
	new_receipt.sumWithTax = new_receipt.sum + new_receipt.totalTax;
	return new_receipt.sumWithTax;
	}

double order::calculateLineItem(customerInput& selectedItem, std::vector<menuItem>& menuList){
	double tempItemTotal = 0.0;
	for (auto& item: menuList){
		if (selectedItem.choice == item.itemNum){
			tempItemTotal = item.menuPrice * selectedItem.multiple;
		}
	}
	return tempItemTotal;
}

double order::calculateTax(){
	return new_receipt.sum * new_receipt.tax;
}

order::~order(){};
