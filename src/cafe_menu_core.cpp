#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "cafe_menu_core.hpp"

namespace cafe_menu {

std::vector<menu_item> create_menu(const std::string& file_path) {
 	std::fstream file(file_path);
	std::vector<menu_item> temp;
 	if (file.is_open()){
    	std::string line;
		std::string str_price;
		int i {0};
    	while (getline(file, line)){
      		std::stringstream temp_struct(line);
      		menu_item item;
      		std::getline(temp_struct, item.name);
      		std::getline(file, str_price);
      		temp_struct >> str_price;
	  		item.price = stod(str_price);
	  		item.num = ++i;
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

double calc_sub_total(const std::vector<ordered_item>& customer_order, const std::vector<menu_item> full_menu, const discounts& order_discounts) {
	double sub_total {0};
	for (auto& order_item: customer_order) {
		for (auto& m_item: full_menu) {
			if (order_item.item_num == m_item.num)
				sub_total += m_item.price * order_item.num_of_item;
		}
	}
	
	if (order_discounts.active_discounts == true) {
		sub_total -= calc_discounts(sub_total, order_discounts.discount_rate);
	}

	return sub_total;
}

double calc_discounts(double sub_total, double discount_rate) {
	return sub_total * discount_rate;
}

double calc_sub_total_tax(double sub_total, double sales_tax_rate) {
	return sub_total * sales_tax_rate;
}

double calc_total(double sub_total, double sub_total_tax) {
	return sub_total + sub_total_tax;
}

}
