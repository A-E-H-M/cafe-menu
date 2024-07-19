#include <string>
#include <vector>
#include <iostream>

#include "cafe-menu/cafe_menu_iostream.hpp"
#include "cafe-menu/cafe_menu_core.hpp"

using namespace cafeMenu;

int main(){
	char customerInput;
	int temp {1};

	menuCatalog menu;
	displayOrder display;
	order nOrder;
	billItemization billItems;
	calculateBill nBill;

	menu.setMenu("current.txt");
	display.prompts(0);
	while (temp >= -1){
		std::cin >> customerInput;
		temp = nOrder.validateAnswer(customerInput);	
		switch (temp){
			case 0:
				break;
			case 1:
				nOrder.orderedItems.push_back(nOrder.addToOrder(display));
				break;
			default:
				display.prompts(2);
				break;
		}
	};
	
// Final state starts
	
	for (auto& oI: nOrder.orderedItems){
		for (auto& mI: menu.menuList){
			if (oI.choice == mI.itemNum){
				oI.itemTotal = nBill.calculateItemTotal(mI.menuPrice, oI.multiple);
				nOrder.orderItemTotals.push_back(oI.itemTotal);
			};
		};
	};

	billItems.subTotal = nBill.calculateSubTotal(nOrder.orderItemTotals);
	billItems.taxTotal = nBill.calculateTax(billItems.subTotal, billItems.tax);
	billItems.total = nBill.calculateTotal(billItems.subTotal, billItems.taxTotal);

  	return 0;
};
