#pragma once

#include <string>
#include <vector>

#include "cafe_menu_core.hpp"

namespace cafe_menu
{
	struct customer_input {
		char answer;
		int choice; 
		int multiple;
		double item_total {0.0};
	};

	char set_answer();
	int set_choice();

	void display_menu(const std::vector<menu_item>& menu_list);
	void prompts(int p);
	void display_receipt(double& tax_total, double& total);

	//customerInput addToOrder(const display& ndisplay);
}
