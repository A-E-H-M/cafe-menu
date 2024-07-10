// By: Alex H Mann
#pragma once

#include <string>
#include <vector>

struct menuItem{
	std::string menuItem;
	double menuPrice;
	int itemNum;
};

struct customerInput{
	char answer;
	int choice; 
	int multiple;
};

class menu{
	public:
		int numOfItems;
		std::vector<menuItem> menuList;
		
		std::vector<menuItem> getMenu(const std::string& file);
		void displayMenu() const;
};

class receipt{
	private:
		double sum {0.0};
		const double tax {0.05};

	public:
		double sumWithTax {0.0};
		double totalTax {0.0};

		double calculateFinalSum(const std::vector<menuItem>& menuList, const std::vector<customerInput>& orderedItems);
		double calculateLineItem(const customerInput& selectedItem, const std::vector<menuItem>& menuList) const;
		double calculateTax() const;
};

class order{
	private:
		customerInput newCustomer;
		int tempInput;

	public:
		std::vector<customerInput> orderedItems;
		receipt newReceipt;

		void startOrder();
		bool orderInProgress();	
		void validateAnswer();
		const customerInput addToOrder();
		void continueOrder();
		void printReceipt() const;
};

