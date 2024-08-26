#pragma once

#include <vector>
#include <iostream>

/* cafe-menu is a library built to include functionality to capture customer orders, including the ability to calculate totals for completed orders. It also has the capability to validate customer input and display some common ordering prompts/text. cafe-menu consists of two parts, cafe-menu-core and cafe-menu-iostream. cafe-menu-core consists containers that relate to an essential order element, such as each information about each menu item and the final totals per order.
*/

namespace cafe_menu
{
/* menuItem is created to serve as single unit for each menu item. It is meant to ensure that each item has the space reserved to store relvant information, even if that peice of information is not recorded at the time. Both the menuItem and menuPrice have defaults to ensure that calculations can still be preformed even if the information was not entered at the time.
*/
	// Maintains the name, price, and number of each item.
	struct menu_item {
		// Record the name of the item. The default string is set to an empty string.
		std::string item_name {""};
		// Record the price of the item. The default is set to 0.0.
		double item_price = 0.0;
		// Assigns a number to the menuItem related to the chronological order to its addition to the vector of menu items.
		int item_num = 0;
	};
	
	// Maintains the tax, subtotal, taxtotal, and total to encapsulate separate orders.
	struct invoice {
		// Maintains a tax as decimal to represent at a percentage. The default is set to 0.0.
		double tax = 0.0;
		// Maintains the total without tax. The default is set to 0.0.
		double sub_total = 0.0;
		// Maintains the total amount of tax calculated from the subtotal and tax. It does not include the addition of the subtotal and the total amount of the calculated tax. The default is set to 0.0.
		double tax_total = 0.0;
		// Maintains the total amount of the final bill. This includes the addition of the subtotal and the total tax. The default is set to 0.0.
		double total = 0.0;
	};

	// Maintains the full menuList, a list of valid user inputs, and the list of items a customer has selected to add to their order.
	struct vec {
		// Maintains the list of all menu items accessible to the customer, and that have been provided to setMenu().
		std::vector<menu_item> menu_list;
		// Maintains a list of valid character inputs that are compared to the user input.
		std::vector<char> valid_responses { 'Y', 'y', 'N', 'n', 'A', 'a', 'R', 'r' };
		// Maintains the full list of items the customer has selected to add to their order.
		std::vector<double> order_item_totals;
	};

	// Parses a text file of menu items and stores each item in a menuItem. While the text file is being parsed, each menuItem is stored in a vector. When the end of the file is reached, the vector is then returned. If no text file can be found, execution is terminated and an error message is output. A file path is in the form of a string is a required parameter.
	std::vector<menu_item> set_menu(const std::string& file_path);
	// Validates customer's choice of item by comparing it to the full list of menu items in menuList. Returns true if an the customer's choice input exists within the menuList. Returns false if does not match a valid number in the menuList. Requires a integer representing the customer's choice, as well as the full list of menu items in menuList, as parameters.
	bool validate_choice(int choice, const std::vector<menu_item>& menu);
	// Validates customer's character input by comparing it to the accepted characters listed in the validResponses vector. Returns true if the customer's input matches one of the characters within in validResponses. Returns false if not. Requires a character value as a parameter.
	int validate_answer(const char temp);

	// Calculates the cost per item based on its value and how many of the item the customer would like to order. It requires a reference to an menuList member variable itemPrice and an the customer's integer input value reflective of the amount of that item would like to be ordered, both as parameters.
	double calculate_item_total(double item_price, int multiple);
	// Calculates the subtotal, without tax, of all the items in orderItemTotals vector. Requires reference to an orderItemTotals vector.
	double calculate_sub_total(const std::vector<double>& costByItem);
	// Calculates the total tax based on the subtotal. It does not add the final tax amount to the subtotal. It returns only the total tax amount. Requires a total amount and a tax rate in the form of a decimal as parameters.
	double calculate_tax(double total, double tax);
	//Calculates the total amount for the final bill by adding the total tax amount with the subtotal. Requires a subtotal and total tax amount to be billed to the customer as parameters.
	double calculate_total(double sub_total, double tax);
	
}
