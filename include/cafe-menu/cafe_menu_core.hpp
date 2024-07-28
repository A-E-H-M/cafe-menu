#pragma once

#include <vector>
#include <iostream>

namespace cafeMenu
{
	struct menuItem {
		std::string menuItem;
		double menuPrice;
		int itemNum;
	};
	
	struct invoice {
		double tax {0.05};
		double subTotal {0.0};
		double taxTotal {0.0};
		double total {0.0};
	};

std::vector<menuItem> menuList;


	void setMenu(const std::string& filePath);

	int validateAnswer(const char temp);

	std::vector<double> orderItemTotals;

	double calculateItemTotal(const double& itemPrice, const int& multiple) const;
	double calculateSubTotal(const std::vector<double>& costByItem) const;
	double calculateTax(const double& total, const double& tax) const;
	double calculateTotal(const double& subTotal, const double& tax) const;
	
}
