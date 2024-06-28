#include <iostream> 
#include <fstream>
#include <sstream>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>

#include "cafe_main.hpp"

std::vector<menuItemType> menu::getMenu(const std::string& path){
  std::vector<menuItemType> tempMenuList;
  std::fstream file(path);
  if (file.is_open()){
    std::string line;
	std::string strMenuPrice;
	int i = 1;
    while (getline(file, line)){
      std::stringstream tempStruct(line);
      menuItemType item;
      std::getline(tempStruct, item.menuItem);
      std::getline(file, strMenuPrice);
      tempStruct >> strMenuPrice;
	  item.menuPrice = stod(strMenuPrice);
	  item.itemNum = i++;
      tempMenuList.push_back(item);
    }
    file.close();
  }
  else {
    std::cout << "Your menu file can not be found." << std::endl;
  }
  return tempMenuList;
}

void menu::showMenu(std::vector<menuItemType>& menuList){
  std::cout << "Welcome to the Basil and Thyme Cafe! Below is our current menu. \n" << std::endl;
  std::cout << std::setw(5) << std::left << "No." 
            << std::setw(15) << std::left << "Item" 
            << std::setw(15) << std::left << "Price" 
            << std::endl;
  int i = 1;
  for (auto& item : menuList){
		std::cout << std::setw(5) << std::left << i 
              << std::setw(15) << std::left << item.menuItem 
              << std::setw(15) << std::left << item.menuPrice 
              << std::endl;
    i++;
	}
  std::cout << std::endl;
}

double order::itemCost(int& choice, int& multiple, std::vector<menuItemType>& menuList, receipt& new_receipt){
	double total;
	for (auto& i: menuList){
		if (choice == i.itemNum){
			total = total + (i.menuPrice) * multiple;
			new_receipt.orderEntries.push_back(total);
		}
	}
	return total;
}

double order::calculateTax(receipt& new_receipt){
	for (auto& i: new_receipt.orderEntries){
	new_receipt.sum = new_receipt.sum + i;
	}
	new_receipt.totalTax = new_receipt.sum * new_receipt.tax; 
	return new_receipt.totalTax;
}

double order::calculateFinalSum(receipt& new_receipt){
	new_receipt.sumWithTax = new_receipt.sum + new_receipt.sum;
	return new_receipt.sumWithTax;
}

void order::takeOrder(std::vector<menuItemType>& menuList, receipt& new_receipt, customerInput& new_customer)
{
  std::cout << "Would you like to put in an order (y/Y) or (n/N)? ";
  std::cin >> new_customer.answer;
  std::cout << std::endl;

while (new_customer.answer)
{
  if (new_customer.answer == 'Y' || new_customer.answer == 'y')
    {
	  std::cout << "Enter the item number: ";
	  std::cin >> new_customer.choice;
	  std::cout << "How many would you like to order? ";
	  std::cin >> new_customer.multiple;
	itemCost(new_customer.choice, new_customer.multiple, menuList, new_receipt);
	std::cout << "Select another item ? (y/Y) or (n/N) ";
	std::cin >> new_customer.answer;
  }
  else {
    new_customer.answer = false;
  }
}
}

void order::printReceipt(receipt& new_receipt){
	std::cout << std::setw(12) << std::right << std::setprecision(2) << std::fixed
            << "Tax: " << new_receipt.totalTax << std::endl;
  std::cout << std::left 
            << "Amount Due: " << new_receipt.sumWithTax << std::endl;
}
