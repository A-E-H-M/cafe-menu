#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

//#include "cafe-menu/cafe_menu_core.hpp"
#include "../include/cafe-menu/cafe_menu_core.hpp"

using namespace cafeMenu;

void setOrderStatus(bool status){
	running = status;
}

void setMenu(const std::string& filePath) {
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
		setOrderStatus(false);
		int error = 1;
  	}
}

int validateResponse(const char response) const {
	for (auto& choice: validResponses){
		if (response == choice)
			return 1;
	}
	return 0;
}

/*
int validateAnswer(const char temp) {
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
*/

double calculateItemTotal(double& itemPrice, int& multiple) const {
	return itemPrice * multiple;
}

double calculateSubTotal(const std::vector<double>& costByItem) const {
	double total {0};
	for (auto& item: costByItem){
		total += item;
	}
	return total;
}

double calculateTax(double& total, double& tax) const {
	return total * tax;
}

double calculateTotal(double& subTotal, double& tax) const {
	return subTotal + tax;
}
