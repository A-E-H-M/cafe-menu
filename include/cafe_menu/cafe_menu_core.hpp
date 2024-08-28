#pragma once

#include <vector>
#include <iostream>

namespace cafe_menu
{
	struct menu_item {
		std::string item_name {""};
		double item_price = 0.0;
		int item_num = 0;
	};
	
	struct invoice {
		double tax = 0.0;
		double sub_total = 0.0;
		double tax_total = 0.0;
		double total = 0.0;
	};

	struct vec {
		std::vector<menu_item> menu_list;
		std::vector<char> valid_responses { 'Y', 'y', 'N', 'n', 'A', 'a', 'R', 'r' };
		std::vector<double> order_item_totals;
	};

	std::vector<menu_item> set_menu(const std::string& file_path);
	bool validate_choice(int choice, const std::vector<menu_item>& menu);
	int validate_answer(const char temp);

	double calculate_item_total(double item_price, int multiple);
	double calculate_sub_total(const std::vector<double>& costByItem);
	double calculate_tax(double total, double tax);
	double calculate_total(double sub_total, double tax);
	
}
