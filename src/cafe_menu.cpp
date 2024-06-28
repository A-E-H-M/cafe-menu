// By: Alex H Mann

#include <iostream> 
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>

#include "cafe_main.hpp"

// class menu
std::vector<menuItemType> menu::getMenu(const std::string& path){
	std::vector<menuItemType> tempMenuList;
 	std::fstream file(path);
 	if (file.is_open()){
    	std::string line;
		std::string strMenuPrice;
		int i = 1;
    	while (getline(file, line)){
      		std::stringstream tempStruct(line);
      		menuItemType item;
      		std::getline(tempStruct, item.menuItem);
      		std::getline(file, strMenuPrice);
      		tempStruct >> strMenuPrice;
	  		item.menuPrice = stod(strMenuPrice);
	  		item.itemNum = i++;
      		tempMenuList.push_back(item);
    	}
    file.close();
  	}
  	else {
    	std::cout << "Your menu file can not be found." << std::endl;
  	}
	return tempMenuList;
}

void menu::showMenu(){
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

// class order
void order::takeOrder(std::vector<menuItemType>& menuList){
  	std::cout << "Would you like to put in an order (y/Y) or (n/N)? ";
  	std::cin >> new_customer.answer;

	while (new_customer.answer){
		if (new_customer.answer == 'Y' || new_customer.answer == 'y'){
			std::cout << "Enter the item number: ";
			std::cin >> new_customer.choice;
			std::cout << "How many would you like to order? ";
			std::cin >> new_customer.multiple;
			itemCost(menuList);
			std::cout << "Select another item ? (y/Y) or (n/N) ";
			std::cin >> new_customer.answer;
			std::cout << std::endl;
  		}
  		else {
    		new_customer.answer = false;
  		}
	}
}

void order::printReceipt(){
	std::cout << "Thank you for choosing Basil & Thyme Cafe to satisfy your hunger!\n"
			  << std::setw(12) << std::right << std::setprecision(2) << std::fixed
			  << "Tax: " << new_receipt.totalTax << std::endl;
  	std::cout << std::left 
              << "Amount Due: " << new_receipt.sumWithTax << std::endl;
}

double order::itemCost(std::vector<menuItemType>& menuList){
	double total;
	for (auto& i: menuList){
		if (new_customer.choice == i.itemNum){
			total = total + (i.menuPrice) * new_customer.multiple;
			new_receipt.orderEntries.push_back(total);
		}
	}
	return total;
}

double order::calculateTax(){
	for (auto& i: new_receipt.orderEntries){
		new_receipt.sum = new_receipt.sum + i;
	}
	new_receipt.totalTax = new_receipt.sum * new_receipt.tax; 
	return new_receipt.totalTax;
}

double order::calculateFinalSum(){
	new_receipt.sumWithTax = new_receipt.sum + new_receipt.totalTax;
	return new_receipt.sumWithTax;
}

