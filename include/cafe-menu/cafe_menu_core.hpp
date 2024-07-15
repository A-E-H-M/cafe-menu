#pragma once

#include <string>
#include <vector>

#include "cafe-menu/cafe_menu_iostream.hpp"

namespace cafeMenu
{
	class receipt {
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

};
