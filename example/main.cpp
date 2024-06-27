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
  std::string menuPrice;
};

std::vector<menuItemType> getData(const std::string& file);
void showMenu(std::vector<menuItemType>& menuList);
void printCheck();

int main()
{
  std::vector<menuItemType> menuList;
  std::string inputFile = "current_menu.txt";

  menuList = getData(inputFile);
  showMenu(menuList);	
  printCheck();
  return 0;
}

std::vector<menuItemType> getData(const std::string& path){
  std::vector<menuItemType> tempMenuList;
  std::fstream file(path);
  if (file.is_open()){
    std::string line;
    while (getline(file, line)){
      std::stringstream tempStruct(line);
      menuItemType item;
      std::getline(tempStruct, item.menuItem);
      std::getline(file, item.menuPrice);
      tempStruct >> item.menuPrice;
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

void printCheck()
{
  char answer;
  double sum = 0.0;
  double tax = 0.05;
  int choice, multiple;
  int yum1, yum2, yum3, yum4, yum5, yum6, yum7, yum8 = 0;

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

      switch (choice)
        {
        case 1:
          sum = sum + (8.45 * multiple);
          yum1++;
          break;
        case 2:
          sum = sum + (12.45 * multiple);
          yum2++;
          break;
        case 3:
          sum = sum + (1.99 * multiple);
          yum3++;
          break;
        case 4:
          sum = sum + (10.99 * multiple);
          yum4++;
          break;
        case 5:
          sum = sum + (6.49 * multiple);
          yum5++;
          break;
        case 6:
          sum = sum + (3.69 * multiple);
          yum6++;
          break;
        case 7:
          sum = sum + (4.50 * multiple);
          yum7++;
          break;
        case 8:
          sum = sum + (3.75 * multiple);
          yum8++;
          break;
        }

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
