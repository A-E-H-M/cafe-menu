#pragma once

#include <vector>
#include <iostream>

namespace cafeMenu
{
	class calculateBill {
		public:
			double calculateItemTotal(const double& itemPrice, const int& multiple) const;
			double calculateSubTotal(const std::vector<double>& costByItem) const;
			double calculateTax(const double& total, const double& tax) const;
			double calculateTotal(const double& subTotal, const double& tax) const;
	};
};
