#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

//#include "../include/cafe_menu_core.hpp"
#include "cafe_menu_core.hpp"

using namespace cafe_menu;

//void setMenu(const std::string& filePath) {
std::vector<menu_item> set_menu(const std::string& file_path) {
 	std::fstream file(file_path);
	std::vector<menu_item> temp;
 	if (file.is_open()){
    	std::string line;
		std::string str_menu_price;
		//std::vector<menuItem> temp;
		int i {0};
    	while (getline(file, line)){
      		std::stringstream temp_struct(line);
      		menu_item item;
      		std::getline(temp_struct, item.menu_item);
      		std::getline(file, str_menu_price);
      		temp_struct >> str_menu_price;
	  		item.menu_price = stod(str_menu_price);
	  		item.item_num = ++i;
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

bool validate_choice(int choice, const std::vector<menu_item>& menu){
	auto num_items = menu.size();
	if (choice >= 1 && choice < num_items){
		return true;
	}
	else {
		return false;
	}
}

int validate_answer(const char temp) {
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

double calculate_item_total(double& item_price, int& multiple) {
	return itemPrice * multiple;
}

double calculate_sub_total(const std::vector<double>& cost_by_item) {
	double total {0};
	for (auto& item: cost_by_item){
		total += item;
	}
	return total;
}

double calculate_tax(double& total, double& tax) {
	return total * tax;
}

double calculate_total(double& sub_total, double& tax) {
	return sub_total + tax;
}
