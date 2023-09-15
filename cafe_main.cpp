#include <iostream> 
#include <fstream>
#include <cmath>
#include <string>
#include <limits>
#include <iomanip>
 
using namespace std;

struct menuItemType			// Move to own new file
{					// If I make it into a class, I can create a constructor and destructor to allow for removing items as well.
    string menuItem;
    double menuPrice;
};

void getData(ifstream& infile, menuItemType menuList[], int listSize);
void showMenu(menuItemType menuList[], int listSize);
void printCheck(menuItemType menuList[], int listSize);

int main()
{
  int listSize = 8;			// Run count on menu for we know how big to make the array for items
  menuItemType menuList[listSize];	// Create the array of item for the menulist

  ifstream infile;
  string inputFile;

  inputFile = "current_menu.txt";	// Change file to new name
  infile.open(inputFile);

  getData(infile, menuList, listSize);	// Getter function
  cout << endl;
  showMenu(menuList, listSize);		// Print function
  printCheck(menuList, listSize);	// Print function (overload it?)

  infile.close();

  return 0;
}

void getData(ifstream& infile, menuItemType menuList[], int listSize) 
{
  for (int counter = 0; counter < listSize; counter++)
  {
    getline(infile, menuList[counter].menuItem);
    infile >> menuList[counter].menuPrice;
    infile.ignore(numeric_limits<streamsize>::max(), '\n');
  }
}

void showMenu(menuItemType menuList[], int listSize)
{
  cout << fixed << showpoint << setprecision(2);
  for (int counter = 0; counter < listSize; counter++)
  {
    cout << menuList[counter].menuItem << " " << setw(10)
         << menuList[counter].menuPrice << " " << endl;
  }
}

void printCheck(menuItemType menuList[], int listSize)	// Print check should be seperate from automated menu
{
  char answer;
  double sum = 0.0;			// Should be private
  double tax = 0.05;			// Const and private
  int choice, multiple;			// Probably can be public
  int yum1, yum2, yum3, yum4, yum5, yum6, yum7, yum8 = 0;

  cout << "You can make 8 selections. Do you want to make one (y/Y) or (n/N)?";
  cin >> answer;
  cout << endl;

while (answer)
{
  if (answer == 'Y' || answer == 'y')
    {
      cout << "Enter the item number: ";
      cin >> choice;
      cout << "How many would you like to order? ";
      cin >> multiple;

      switch (choice)
        {
        case 1:
          sum = sum + (1.45 * multiple);
          yum1++;
          break;
        case 2:
          sum = sum + (2.45 * multiple);
          yum2++;
          break;
        case 3:
          sum = sum + (0.99 * multiple);
          yum3++;
          break;
        case 4:
          sum = sum + (1.99 * multiple);
          yum4++;
          break;
        case 5:
          sum = sum + (2.49 * multiple);
          yum5++;
          break;
        case 6:
          sum = sum + (0.69 * multiple);
          yum6++;
          break;
        case 7:
          sum = sum + (0.50 * multiple);
          yum7++;
          break;
        case 8:
          sum = sum + (0.75 * multiple);
          yum8++;
          break;
        }
    cout << "Select another item ? Y or N ";
    cin >> answer;
  }
  else
    answer = false;
  }

  tax = tax * sum;
  cout << "Tax: " << tax << endl;
  cout << "Amount Due: " << sum + tax << endl;
}
