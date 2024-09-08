#pragma once

#include <vector>
#include <iostream>

namespace cafe_menu
{
	struct menu_item {
		double price {0.0};
		int num {0};
		std::string name;
		std::string description;
		std::string category;
		std::string ingredients;
	};

	struct menu {
		std::vector<menu_item> all_menu_items;
	};

	struct ordered_item {
		int item_num {0};
		int num_of_item {0};
		bool multiple_item {false};
	};

	struct discounts {
		bool active_discounts {false};
		std::string name;
		std::string type;
		double discount_rate {0.0};
	};

	struct invoice {
		double sales_tax_rate {0.0};
		double discounts_total {0.0};
		double sub_total {0.0};
		double sub_total_tax {0.0};
		double total {0.0};
	};

	struct order {
		std::vector<ordered_item> customer_order;
		invoice customer_invoice;

	};

	std::vector<menu_item> create_menu(const std::string& file_path);

	double calc_sub_total(const std::vector<ordered_item>& customer_order, const std::vector<menu_item>& full_menu, const discounts& order_discounts);
	double calc_discounts(double sub_total, double discount_rate);
	double calc_sub_total_tax(double sub_total, double sales_tax_rate);
	double calc_total(double sub_total, double sub_total_tax);
	
}
