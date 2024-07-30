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

	//bool status {true};
	std::vector<menuItem> menuList;
	std::vector<char> validResponses { 'Y', 'y', 'N', 'n', 'A', 'a', 'R', 'r' };
	std::vector<double> orderItemTotals;

	void setOrderStatus(bool status);
	void setMenu(const std::string& filePath);
	int validateResponse(const char response) const;
	//int validateAnswer(const char temp);

	double calculateItemTotal(double& itemPrice, int& multiple) const;
	double calculateSubTotal(const std::vector<double>& costByItem) const;
	double calculateTax(double& total, double& tax) const;
	double calculateTotal(double& subTotal, double& tax) const;
	
}
