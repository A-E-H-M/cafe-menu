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
		std::string str_menu_price;
		int i {0};
    	while (getline(file, line)){
      		std::stringstream temp_struct(line);
      		menu_item item;
      		std::getline(temp_struct, item.item_name);
      		std::getline(file, str_menu_price);
      		temp_struct >> str_menu_price;
	  		item.item_price = stod(str_menu_price);
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

double calc_item_sub_total(double& price, int& multiple) {
	return price * multiple;
}

double calc_sub_total(const std::vector<ordered_item>& customer_order, const discounts& apply_discounts) {
	double sub_total {0};
	for (auto& item: cost_by_item){
		total += item;
	}
	return sub_total;
}

double calc_sub_total_tax(double& sub_total, double& sales_tax_rate) {
	return sub_total * sales_tax_rate;
}

double calc_total(double& sub_total, double& sub_total_tax) {
	return sub_total + sub_total_tax;
}

}
