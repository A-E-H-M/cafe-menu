#pragma once

#include <string>
#include <vector>

#include "cafe_menu_core.hpp"

namespace cafe_menu
{
	struct customer_input {
		char answer {''};
		int choice = 0; 
		int multiple = 1;
		double item_total = 0.0;
	};

	//char set_answer();
	//int set_choice();

	//bool validate_choice(int choice, const std::vector<menu_item>& menu);
	//int validate_answer(const char temp);

	void prompts(int p);
	void display_menu(const std::vector<menu_item>& all_menu_items);
	void display_receipt(double& sales_tax_rate, double& total);
}
