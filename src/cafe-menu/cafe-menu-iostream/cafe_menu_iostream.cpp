#include <iostream> 
#include <string>
#include <iomanip>
#include <vector>

//#include "../include/cafe_menu_iostream.hpp"
#include "cafe_menu_iostream.hpp"
#include "cafe_menu_core.hpp"

using namespace cafe_menu;

char set_answer(){
	char answer;
	std::cin >> answer;
	std::cin.sync();
	return answer;
}

int set_choice(){
	int choice;
	std::cin >> choice;
	std::cin.sync();
	return choice;
}

void prompts(int p) {
	switch (p){
		case 0:
			std::cout << "\nWelcome to the Basil and Thyme Cafe! Below is our current menu.\n";
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

void display_menu(const std::vector<menu_item>& menu_list) {
	std::cout << std::setw(5) << std::left << "No." 
              << std::setw(15) << std::left << "Item" 
              << std::setw(15) << std::left << "Price" 
              << "\n";
	for (auto& item: menu_list){
		std::cout << std::setw(5) << std::left << item.item_num
				  << std::setw(15) << std::left << item.menu_item 
				  << std::setw(15) << std::left << item.menu_price 
				  << std::endl;
	}
}

void display_receipt(double& tax_total, double& total) {
	std::cout << std::setw(12) << std::right << std::setprecision(2) << std::fixed
			  << "Tax: " << tax_total << "\n";
  	std::cout << std::left 
              << "Amount Due: " << total << "\n";
	std::cout << std::endl;
}

/*
customerInput addToOrder(const display& nDisplay) {
	customerInput tempCustomerOrder;
	nDisplay.prompts(3);
	std::cin >> tempCustomerOrder.choice;
	nDisplay.prompts(4);
	std::cin >> tempCustomerOrder.multiple;
	nDisplay.prompts(5);
	return tempCustomerOrder;
}
*/
