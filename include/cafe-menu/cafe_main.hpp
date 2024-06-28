// Header file
#include <vector>
#include <string>

struct menuItemType{
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
		std::vector<menuItemType> menuList;
		std::vector<menuItemType> getMenu(const std::string& file);
		void showMenu(std::vector<menuItemType>& menuList);
};

class order{
	public:
		receipt new_receipt;
		void takeOrder(std::vector<menuItemType>& menuList, receipt& new_receipt, customerInput& new_customer);
		void printReceipt(receipt& new_receipt);
		double itemCost(int& choice, int& multiple, std::vector<menuItemType>& menuList, receipt& new_receipt);
		double calculateTax(receipt& new_receipt);
		double calculateFinalSum(receipt& new_receipt);
};
