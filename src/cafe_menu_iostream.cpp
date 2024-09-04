#include <iostream> 
#include <string>
#include <iomanip>
#include <vector>

#include "cafe_menu_iostream.hpp"
#include "cafe_menu_core.hpp"

namespace cafe_menu {
/*
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
*/

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

void display_menu(const std::vector<menu_item>& all_menu_items) {
	std::cout << std::setw(5) << std::left << "No." 
              << std::setw(15) << std::left << "Item" 
              << std::setw(15) << std::left << "Price" 
              << "\n";
	for (auto& item: all_menu_items){
		std::cout << std::setw(5) << std::left << item.num
				  << std::setw(15) << std::left << item.name 
				  << std::setw(15) << std::left << item.price 
				  << std::endl;
	}
}

void display_receipt(double& sales_tax_rate, double& total) {
	std::cout << std::setw(12) << std::right << std::setprecision(2) << std::fixed
			  << "Tax: " << sales_tax_rate << "\n";
  	std::cout << std::left 
              << "Amount Due: " << total << "\n";
	std::cout << std::endl;
}

}
