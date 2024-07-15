// By: Alex H Mann
#pragma once

#include <string>
#include <vector>

struct menuItem{
	std::string menuItem;
	double menuPrice;
	int itemNum;
};

class menu{
	public:
		std::vector<menuItem> menuList;
		
		std::vector<menuItem> getMenu(const std::string& file);
};

struct customerInput{
	char answer;
	int choice; 
	int multiple;
};

class order{
	private:
		customerInput newCustomer;
		int tempInput;

	public:
		std::vector<customerInput> orderedItems;
		receipt newReceipt;

		bool orderInProgress();	
		void validateAnswer();
		const customerInput addToOrder();
};

class displayOrder{
	public:
		void displayMenu() const;
		void startOrder();
		void continueOrder();
		void printReceipt() const;
}
