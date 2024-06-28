// By: Alex H Mann

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
		void showMenu();
};

class order{
	private:
		receipt new_receipt;
		customerInput new_customer;
		
	public:
		void takeOrder(std::vector<menuItemType>& menuList);
		void printReceipt();

		double itemCost(std::vector<menuItemType>& menuList);
		double calculateTax();
		double calculateFinalSum();
};

