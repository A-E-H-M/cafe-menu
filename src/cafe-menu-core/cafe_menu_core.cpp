#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

//#include "../include/cafe_menu_core.hpp"
#include "cafe_menu_core.hpp"

using namespace cafeMenu;

//void setMenu(const std::string& filePath) {
std::vector<menuItem> setMenu(const std::string& filePath) {
 	std::fstream file(filePath);
	std::vector<menuItem> temp;
 	if (file.is_open()){
    	std::string line;
		std::string strMenuPrice;
		//std::vector<menuItem> temp;
		int i {0};
    	while (getline(file, line)){
      		std::stringstream tempStruct(line);
      		menuItem item;
      		std::getline(tempStruct, item.menuItem);
      		std::getline(file, strMenuPrice);
      		tempStruct >> strMenuPrice;
	  		item.menuPrice = stod(strMenuPrice);
	  		item.itemNum = ++i;
			temp.push_back(item);
    	}
    file.close();
  	}
  	else {
    	std::cout << "Your menu file can not be found." << std::endl;
		exit (-1);
  	}
	return temp;
}

/*
int validateResponse(const char response) const {
	for (auto& choice: validResponses){
		if (response == choice)
			return 1;
	}
	return 0;
}
*/

bool validateChoice(int choice, const std::vector<menuItem>& menu){
	auto numItems = menu.size();
	if (choice >= 1 && choice < numItems){
		return true;
	}
	else {
		return false;
	}
}

int validateAnswer(const char temp) {
	switch (temp){
		case 'Y':
		case 'y':
			return 1;			
		case 'N':
		case 'n':
			return 2;
		default:
			return 3;
	}
}

/*int evalState(int answer){
	switch (answer){
		case 1:
			return 2;
		case 2:
			return 3;
		case 3:
			return 4;
	};
}
*/

double calculateItemTotal(double& itemPrice, int& multiple) {
	return itemPrice * multiple;
}

double calculateSubTotal(const std::vector<double>& costByItem) {
	double total {0};
	for (auto& item: costByItem){
		total += item;
	}
	return total;
}

double calculateTax(double& total, double& tax) {
	return total * tax;
}

double calculateTotal(double& subTotal, double& tax) {
	return subTotal + tax;
}
