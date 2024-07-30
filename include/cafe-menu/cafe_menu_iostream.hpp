#pragma once

#include <string>
#include <vector>

#include "cafe_menu_core.hpp"

namespace cafeMenu
{
	struct customerInput {
		char answer;
		int choice; 
		int multiple;
		double itemTotal {0.0};
	};

	std::vector<customerInput> orderedItems;

	void displayMenu(const std::vector<menuItem>& menuList) const;
	void prompts(int p) const;
	void displayReceipt(double& taxTotal, double& total);

	customerInput addToOrder(const display& ndisplay);
}
