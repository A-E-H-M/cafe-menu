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
	struct vec {
		std::vector<menuItem> menuList;
		std::vector<char> validResponses { 'Y', 'y', 'N', 'n', 'A', 'a', 'R', 'r' };
		std::vector<double> orderItemTotals;
	};

	std::vector<menuItem> setMenu(const std::string& filePath);
	//int validateResponse(const char response) const;
	bool validateChoice(int choice, const std::vector<menuItem>& menu);
	int validateAnswer(const char temp);
	//int evalState(int answer);

	double calculateItemTotal(double& itemPrice, int& multiple);
	double calculateSubTotal(const std::vector<double>& costByItem);
	double calculateTax(double& total, double& tax);
	double calculateTotal(double& subTotal, double& tax);
	
}
