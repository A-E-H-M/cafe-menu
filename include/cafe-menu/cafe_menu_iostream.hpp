#pragma once

#include <string>
#include <vector>

namespace cafeMenu
{
	struct menuItem {
		std::string menuItem;
		double menuPrice;
		int itemNum;
	};

	struct customerInput {
		int choice; 
		int multiple;
		double itemTotal {0.0};
	};

	struct invoice {
		double tax {0.05};
		double subTotal {0.0};
		double taxTotal {0.0};
		double total {0.0};
	};

	class display {
		public:
			std::vector<menuItem> menuList;
			
			void setMenu(const std::string& filePath);
			void displayMenu() const;
			void prompts(const int p) const;
			void displayReceipt(const double&, const double&);
	};

	class order {
		public:
			std::vector<customerInput> orderedItems;
			std::vector<double> orderItemTotals;

			int validateAnswer(const char temp);
			customerInput addToOrder(const display& ndisplay);
	};

};
