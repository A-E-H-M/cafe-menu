#pragma once

#include <string>
#include <vector>

#include "../include/cafe-menu/cafe_menu_iostream.hpp"
#include "../include/cafe-menu/cafe_menu_core.hpp"

using namespace cafeMenu;

class CM
{
	
	bool running {true};
	int state {0};

	customerInput cInput;
	invoice nInvoice;
	vec lists;
	
	void init(const std::string& path);
	void sStartUp();
	void sModifyOrder();
	void sUpdateOrder();
	void sUpdateTotals();
	void sUpdateState();
	void sFinalizeOrder();



public:
	CM(const std::string& textMenu);
	void sRun();

};

