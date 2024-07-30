#include <string>
#include <vector>
#include <iostream>

//#include "cafe-menu/cafe_menu_iostream.hpp"
//#include "cafe-menu/cafe_menu_core.hpp"
#include "../include/cafe-menu/cafe_menu_iostream.hpp"
#include "../include/cafe-menu/cafe_menu_core.hpp"
//#include "cafe_menu_example.hpp"

using namespace cafeMenu;

void sStartUp();
void sModifyOrder();
void sUpdateOrder();
void sUpdateTotals();
void sUpdateStatus();
void sFinalizeOrder();

int main(){
	bool running {true};
	customerInput cInput;
	invoice nInvoice;
	validResponses cResponses;

	sStartUp();
	while (running){
		if (sUpdateStatus());
		sModifyOrder();
		sUpdateOrder();
		sUpdateTotals();
		sUpdateStatus();
	}
	sFinalizeOrder();

		
		
		
		
		
/*
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
*/
  	return 0;
};

void sStartUp(){
	setMenu("current_menu.txt");
	displayMenu(menuList);
	prompts(1);
	std::cin >> cInput.answer;
};

void sModifyOrder(){
		validateResponse(std::cin >> response);

};

void sUpdateOrder() {
	std::cin >> cInput.answer;
	switch (validateResponse(cInput.answer)){
		case 0:
			setOrderStatus(false);
			break;
		case 1:
			break;
		default:
			prompts(2);
			break;
	}
};

void sUpdateTotals() {

};

void sUpdateStatus() {
};

void sFinalizeOrder(){
if (error == 1){
	std::cout << "Could be start order.\n";
}
};	
