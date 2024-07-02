// By: Alex H Mann
#pragma once

#include <string>
#include <vector>

struct menuItem{
	std::string menuItem;
	double menuPrice;
	int itemNum;
};

struct receipt{
	std::vector<double> orderEntries;
	double sum = 0.0;
	double tax = 0.05;
	double totalTax = 0.0;
	double sumWithTax = 0.0;
};

struct customerInput{
	char answer;
	int choice, multiple;
};

class menu{
	public:
		int numOfItems;
		std::vector<menuItem> menuList;
		
		std::vector<menuItem> getMenu(const std::string& file);
		void displayMenu();
		menu();
		~menu();
};

class order{
	private:
		receipt new_receipt;
		customerInput new_customer;
		int tempInput;

	public:
		std::vector<customerInput> orderedItems;
		
		void startOrder();
		void printReceipt();
		bool orderInProgress();	
		void validateAnswer();
		struct customerInput addToOrder();
		void continueOrder();

		double calculateFinalSum(std::vector<menuItem>& menuList);
		double calculateLineItem(customerInput& selectedItem, std::vector<menuItem>& menuList);
		double calculateTax();
		order();
		~order();
};

