#include <iostream> 
#include <fstream>
#include <sstream>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
 
struct menuItemType
{
  std::string menuItem;
  double menuPrice;
  int itemNum;
};

std::vector<menuItemType> getMenu(const std::string& file);
void showMenu(std::vector<menuItemType>& menuList);
void printCheck(std::vector<menuItemType>& menuList);
double itemCost(double& choice, double& multiple, std::vector<menuItemType>& menuList);
double totalSum(double& item_Cost, double& total);

int main()
{
  std::vector<menuItemType> menuList;
  std::string inputFile = "current_menu.txt";

  menuList = getMenu(inputFile);
  showMenu(menuList);	
  printCheck(menuList);
  return 0;
}

std::vector<menuItemType> getMenu(const std::string& path){
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

void showMenu(std::vector<menuItemType>& menuList){
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

double itemCost(double& choice, double& multiple, std::vector<menuItemType>& menuList){
	double total;
	for (auto& i: menuList){
		if (choice == i.itemNum){
			total = total + (i.menuPrice) * multiple;
		}
	}
	return total;
}

double totalSum(double& item_Cost, double& total){
	total = total + item_Cost;
	return total;
}

void printCheck(std::vector<menuItemType>& menuList)
{
  char answer;
  double sum = 0.0;
  double tax = 0.05;
  double multiple;
  double choice;

  std::cout << "Would you like to put in an order (y/Y) or (n/N)? ";
  std::cin >> answer;
  std::cout << std::endl;

while (answer)
{
  if (answer == 'Y' || answer == 'y')
    {
	  std::cout << "Enter the item number: ";
	  std::cin >> choice;
	  std::cout << "How many would you like to order? ";
	  std::cin >> multiple;
	  double perItemCost = itemCost(choice, multiple, menuList);
	  sum = totalSum(perItemCost, sum);

	std::cout << "Select another item ? (y/Y) or (n/N) ";
	std::cin >> answer;
  }
  else {
    answer = false;
  }
}

  tax = tax * sum;
  std::cout << std::setw(12) << std::right << std::setprecision(2) << std::fixed
            << "Tax: " << tax << std::endl;
  std::cout << std::left 
            << "Amount Due: " << sum + tax << std::endl;
}
