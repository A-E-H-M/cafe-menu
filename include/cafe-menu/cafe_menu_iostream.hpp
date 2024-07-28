#pragma once

#include <string>
#include <vector>

namespace cafeMenu
{
	struct customerInput {
		int choice; 
		int multiple;
		double itemTotal {0.0};
	};

	class display {
		public:
			std::vector<customerInput> orderedItems;

			void displayMenu() const;
			void prompts(const int p) const;
			void displayReceipt(const double&, const double&);

			customerInput addToOrder(const display& ndisplay);
	};
};
