#include <string>
#include <vector>
#include <iostream>

#include "../include/cafe-menu/cafe_menu_iostream.hpp"
#include "../include/cafe-menu/cafe_menu_core.hpp"

using namespace cafeMenu;

int main(){
// Initial state
	char customerInput;
	int temp {1};

	display nDisplay;
	order nOrder;

	invoice nInvoice;
	calculateBill nBill;

	nDisplay.setMenu("current_menu.txt");

	nDisplay.prompts(0);
	nDisplay.displayMenu();
	nDisplay.prompts(1);
	while (temp > 0){
		std::cin >> customerInput;
		temp = nOrder.validateAnswer(customerInput);	
		switch (temp){
			case 0:
				break;
			case 1:
				nOrder.orderedItems.push_back(nOrder.addToOrder(nDisplay));
				break;
			default:
				nDisplay.prompts(2);
				break;
		}
	};
	
// Calculation state
	for (auto& oI: nOrder.orderedItems){
		for (auto& mI: nDisplay.menuList){
			if (oI.choice == mI.itemNum){
				oI.itemTotal = nBill.calculateItemTotal(mI.menuPrice, oI.multiple);
				nOrder.orderItemTotals.push_back(oI.itemTotal);
			};
		};
	};

	nInvoice.subTotal = nBill.calculateSubTotal(nOrder.orderItemTotals);
	nInvoice.taxTotal = nBill.calculateTax(nInvoice.subTotal, nInvoice.tax);
	nInvoice.total = nBill.calculateTotal(nInvoice.subTotal, nInvoice.taxTotal);

// Final state
	nDisplay.prompts(6);
	nDisplay.displayReceipt(nInvoice.taxTotal, nInvoice.total);

  	return 0;
};
