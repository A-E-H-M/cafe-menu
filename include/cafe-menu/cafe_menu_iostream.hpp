// By: Alex H Mann
#pragma once

#include <string>
#include <vector>

#include "cafe-menu/cafe_menu_core.hpp"

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
	
	struct billItemization {
		double tax {0.0};
		double subTotal {0.0};
		double taxTotal {0.0};
		double total {0.0};
	};

	class menuCatalog {
		public:
			std::vector<menuItem> menuList;
		
			void setMenu(const std::string& filePath);
	};

	class displayOrder {
		public:
			void displayMenu(const int&, const std::string&, const double&) const;
			void prompts(const int p) const;
			void displayReceipt(const double&, const double&);
	};

	class order {
		public:
			std::vector<customerInput> orderedItems;
			std::vector<double> orderItemTotals;

			int validateAnswer(const char temp);
			customerInput addToOrder(const displayOrder& display);
	};

};
