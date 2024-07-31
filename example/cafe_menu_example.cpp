#include <string>
#include <vector>
#include <iostream>

//#include "cafe-menu/cafe_menu_iostream.hpp"
//#include "cafe-menu/cafe_menu_core.hpp"
//#include "../include/cafe-menu/cafe_menu_iostream.hpp"
//#include "../include/cafe-menu/cafe_menu_core.hpp"
#include "cafe_menu_example.hpp"

using namespace cafeMenu;

CM::CM(const std::string& textMenu){
	init(textMenu);
}

void CM::init(const std::string& path){
	lists.menuList = setMenu(path);
}

void CM::sRun(){
	sStartUp();
	while (running){
		switch (state){
			case 2:
				sUpdateOrder();
				break;
			case 3:
				sModifyOrder();
				sUpdateTotals();
				break;
			default:
				sUpdateState();
		};
		sUpdateDisplay();
	};
	sFinalizeOrder();
}

void CM::sStartUp(){
	displayMenu(lists.menuList);
	prompts(0);
	prompts(1);
	cInput.answer = setAnswer();
};

void CM::sUpdateOrder() {
	cInput.answer = setAnswer();
};

void CM::sModifyOrder(){
	cInput.choice = setChoice();
	if (validateChoice(cInput.choice, lists.menuList)){
		cInput.multiple = setChoice();
	}

};

void CM::sUpdateTotals(){
	
};

void CM::sUpdateState(){
	state = evalState(validateAnswer(cInput.answer));
	switch (state){
		case 2:
			break;
		case 3:
			state = 2;
		case 4:
			running = false;

	}
};

void CM::sUpdateDisplay(){
	switch (state){
		case 1:
			prompts(3);
			break;
		case 2:
			prompts(2);
		default:
			prompts(2);
	}
};

void CM::sFinalizeOrder(){
	
};

		
		
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

/*
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
*/

