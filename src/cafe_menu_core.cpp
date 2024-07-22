#include <vector>
#include <iostream>

#include "../include/cafe-menu/cafe_menu_core.hpp"

using namespace cafeMenu;

double calculateBill::calculateItemTotal(const double& itemPrice, const int& multiple) const {
	return itemPrice * multiple;
}

double calculateBill::calculateSubTotal(const std::vector<double>& costByItem) const {
	double total {0};
	for (auto& item: costByItem){
		total += item;
	}
	return total;
}

double calculateBill::calculateTax(const double& total, const double& tax) const {
	return total * tax;
}

double calculateBill::calculateTotal(const double& subTotal, const double& tax) const {
	return subTotal + tax;
}
