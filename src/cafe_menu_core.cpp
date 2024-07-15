// By: Alex H Mann

#include <string>
#include <vector>

#include "cafe-menu/cafe_menu_core.hpp"
#include "cafe-menu/cafe_menu_iostream.hpp"

using namespace cafeMenu;

//class receipt
double receipt::calculateFinalSum(const std::vector<menuItem>& menuList, const std::vector<customerInput>& orderedItems) {
	for (const auto& selectedItem: orderedItems){
		sum += calculateLineItem(selectedItem, menuList);
	}
	totalTax = calculateTax();
	sumWithTax = sum + totalTax;
	return sumWithTax;
	}

double receipt::calculateLineItem(const customerInput& selectedItem, const std::vector<menuItem>& menuList) const {
	double tempItemTotal = 0.0;
	for (const auto& item: menuList){
		if (selectedItem.choice == item.itemNum){
			tempItemTotal = item.menuPrice * selectedItem.multiple;
		}
	}
	return tempItemTotal;
}

double receipt::calculateTax() const {
	return sum * tax;
}
