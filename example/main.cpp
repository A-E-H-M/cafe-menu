#include <string>
#include <vector>

#include "cafe_main.hpp"

int main()
{
  //std::vector<menuItemType> menuList;
  menu new_menu;
  std::string inputFile = "current_menu.txt";
  order new_order;
  customerInput new_customer;

  //menuList = getMenu(inputFile);
  new_menu.getMenu(inputFile);
  new_menu.showMenu(new_menu.menuList);
  new_order.takeOrder(new_menu.menuList, new_order.new_receipt, new_customer);
  new_order.calculateTax(new_order);
  new_order.printReceipt(new_order);

  return 0;
}
