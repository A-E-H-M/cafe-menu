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

	class menuCatalog {
		public:
			std::vector<menuItem> menuList;
		
			std::vector<menuItem> getMenu(const std::string& file);
	};

	struct customerInput {
		char answer;
		int choice; 
		int multiple;
	};
	
	class displayOrder {
		private:
			menuCatalog menu;
		
		public:
			void displayMenu() const;
			void startOrder();
			void continueOrder();
			void printReceipt(const receipt& newReceipt) const;
	};

	class order {
		private:
			int tempInput;

		public:
			std::vector<customerInput> orderedItems;
			customerInput newCustomer;
			receipt newReceipt;
			displayOrder newOrder;

			bool orderInProgress();	
			void validateAnswer();
			const customerInput addToOrder();
	};

};
