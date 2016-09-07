/*****************************************************************************/
/* Program 2 - Inventory Application										 */
/*****************************************************************************
    Author: Nathaniel Hoefer
    Student ID: X529U639
    Program: #2


Description of the Problem:
	You are the owner of a new store and need to keep track of your inventory.
   	Since you are a seasoned C++ programmer, you are going to write a C++
   	program to perform this function.


Class Name: Inventory

Data:		- partNum - part number that should hold int from 1 to 100
			- item - Name of item
			- quantity - quantity of how many of the part there is
			- price - price per item
			- totalCost - total cost of the inventory items

Functions:	+ ModifyItem(partNum,item,quantity,price) - Updates the info
				based on the partNum chosen
				Input Parms: int partNum - is the index of part to be changed
							string item - name of item
							quantity - number of that specific item
							price - price per item
				Output Parms: None
				> Assign arguments to values



Class Name: InvMethods

Data:		- invCount - The number of different inventory items
			- invTotal - The total value of all the items

Mutator Functions:
			+ setInvCount
			+ setInvTotal

Accessor Functions:
			+ getInvCount
			+ getInvTotal

Functions:	+ DisplayMenu() - Displays user menu
				Input Parms: None
				Output Parms: Prints the menu
				> Print title and options
				> Request and validate user selection
				> Implement method based on selection

			- DisplayParts(useTitle) - Prints current inventory
				Input Parms: bool useTitle - Whether to display title
				Output Parms: Prints all parts in inventory
				> If useTitle is true, print parts title
				> Print labels and inventory items formatted
				> Wait for user input to continue

			- NewPart() - Adds an additional item to inventory
				Input Parms: None
				Output Parms: None
				> Print title
				> Request part info
				> Print new item formatted
				> Wait for user input to continue

			- NewPart(item,quantity,price) - Overloaded to allow for
				adding a new part without user input
				Input Parms: int item
							int quantity
							float price
				Output Parms: None
				> Modify the new n+1 item using parameters

			- ModifyPart() - User selects item to be modified and updates info
				Input Parms: None
				Output Parms: None
				> Print title and current parts
				> Request part and print it
				> Request part info and modify part
				> Print modified part
				> Wait for user input to continue

			- DisplayInvTotal() - Prints the total value of inventory
				Input Parms: None
				Output Parms: None
				> Print title
				> Cycle through parts and collect inventory totals
				> Print inventory total

			- ExitProgram() - Exits the menu loop by returning true
				Input Parms: None
				Output Parms: bool to be used by menu displayed
				> Return true to confirm that exit program is accessed.

			- RequestPartInfo(itemNum) - Asks the user for item, quantity,
				and cost.
				Input Parms: Part to be changed. Lists negative number to
					specify new part
				Output Parms: None
				> Request Item, Quantity, and Price from user
				> Modify part based on argument passed

			- ParseLine(line) - Parses string passed using comma delimiters
				and adds info to inventory.
				Input Parms: a single line from inventory.txt
				Output Parms: None
				Returns: 1 for successful parse, 0 for error
				> Tries to parse line into item, quantity, and price.
				> If successful, create new part
				> If unsuccessful, print error message

			- CalcTotalCost(partNum) - Returns the total cost of parts in
				inventory
				Input Parms: Part number between 0-Max count
				Output Parms: None
				Return: The float total cost of part in inventory
				> Price of Part * Quantity of Part

			- FormatItemDisplay(partNum,displayLabels) - Formats the items to
				display correctly within a table.
				Input Parms: int partNum - part to be formatted
							bool displayLabels - true to display labels
				Output Parms: Prints part info with or without labels
				> Display part if displayLabels == true
				> Display formatted part info.

*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <sstream>

using namespace std;



/*****************************************************************************/
// Constants
/*****************************************************************************/


// The number of windows displayed in the menu.
const int MENU_ITMES_COUNT = 5;

// Used in case there is an issue with going between Windows and Linux
const char NEW_LINE = '\n';

// Maximum number of items in inventory
const int MAX_INVENTORY = 100;




/*****************************************************************************/
// Structures
/*****************************************************************************/


// Establishes the items to be in the inventory structure
struct inventoryItem
{
	int partNum; 		// part number that should hold int from 1 to 100
	string item;		// Name of item
	int quantity; 		// quantity of how many of the part there is
	float price; 		// price per item
	float totalCost;	// total cost of the inventory items
};




/*****************************************************************************/
// Class Headers
/*****************************************************************************/



/* This inventory class is used to contain all of the methods and member
 * variables pertaining to the Inventory process. There are some things that
 * are not as efficient as they could be, but I decided to experiment with
 * implementing the class within this one file.
 */
class Inventory
{

	private:

// Member Variables

	int m_partNum;
	string m_item;
	int m_quantity;
	float m_price;
	float m_totalCost;


	public:

// Constructor

	Inventory();
	Inventory(string item, int quantity, float price);


// Methods

	// Updates the part info based on the partNum chosen
	void ModifyItem(int partNum, string item, int quantity, float price);

};


/* This inventory class is used to contain all of the methods and member
 * variables pertaining to the Inventory process. There are some things that
 * are not as efficient as they could be, but I decided to experiment with
 * implementing the class within this one file.
 */
class InvMethods
{

	private:

// Member Variables

	// Holds all of the inventory objects.
	Inventory invArray[MAX_INVENTORY];
	//inventoryItem inventory[MAX_INVENTORY];

	// The number of different inventory items
	int m_invCount;

	// The total value of all the items
	float m_invTotal;



	public:

// Constructor

	InvMethods();


// Methods

	// Displays user menu
	void DisplayMenu();

	// Parses the line and adds info to inventory
	int ParseLine(string line);



// Mutators and Accessors

	// Accesses the member variables of the class
	int getInvCount() { return invCount; };
	float getInvTotal() { return invTotal; };

	// Modifies the member variables of the class
	void incrementInvCount() { m_invCount++; };
	void setInvTotal(float invTotal) { m_invTotal = invTotal; };



	private:

// Menu Variables

	// Prints current inventory
	void DisplayParts(bool useTitle);

	// Adds an additional item to inventory
	void NewPart();
	void NewPart(string item, int quantity, float cost);

	// User selects item to be modified and updates info
	void ModifyPart();

	// Prints the total value of inventory
	void DisplayInvTotal();

	// Exits the menu
	bool ExitProgram();

	// Asks the user for item, quantity, and cost
	void RequestPartInfo(int itemNum);

	// Formats the items to display correctly
	void formatItemDisplay(int itemNum, bool displayLabels);

	// Returns the total cost of inventoried item
	float CalcTotalCost(int item);

};



/*****************************************************************************/
// Main Method
/*****************************************************************************/


int main(void)
{

	// Instantiated inventory object used for inventory procedures
	Inventory inventory;
	string inventoryFileName = "inventory.txt";


	// Opens text file and reads the values into the inventory.
	ifstream readFile(inventoryFileName.c_str());
	string fileLine;

	// if 0, then error has occurred.
	int no_error = 1;
	if (readFile.is_open())
	{
		// Reads each line and uses parse function to store data
		// ParseLine will return 0 if an there is an issue with opening
		// the file.
		while (getline(readFile, fileLine) && no_error > 0)
		{
			// Checks to see if the count is greater than 100
			if (inventory.getInvCount() < MAX_INVENTORY)
			{
				no_error = inventory.ParseLine(fileLine);
			}
			else
			{
				no_error = 0;
			}
		}

		// Tells user if there was an error reading the file
		if (no_error == 0)
		{
			cout << "Error Reading File" << endl;
		}
		readFile.close();
	}


	// Displays the menu and enters loop until user is finished.
	inventory.DisplayMenu();


	// Opens Text file and saves each part until inventory is complete.
	ofstream saveFile(inventoryFileName.c_str());
	int inventoryCount = inventory.getInvCount();
	if (saveFile.is_open())
	{
		// Writes every item to its own line using commas as delimiters
		for (int i = 1; i <= inventoryCount; i++)
		{
			string item = inventory.getItem(i);
			int quantity = inventory.getQuantity(i);
			float price = inventory.getPrice(i);
			saveFile << item << "," << quantity << "," << price << endl;
		}
		saveFile.close();

		cout << NEW_LINE << "File Saved" << endl;
	}

	cout << "Program Ended" << endl;
}



/*****************************************************************************/
// Class Source Functions
/*****************************************************************************/


// CONSTRUCTORS ***************************************************************


Inventory::Inventory()
{
	InvMethods::IncrementInvCount();

	m_partNum = 1;
	m_item = "Default";
	m_quantity = 1;
	m_price = 1.00;
	m_totalCost = 1.00;
}


Inventory::Inventory(string item, int quantity, float price)
{
	// Increased the inventory count by 1
	InvMethods::incrementInvCount;

	// Sets the members to the entered values
	m_partNum = InvMethods::getInvCount;
	m_item = item;
	m_quantity = quantity;
	m_price = price;
	m_totalCost = quantity * price;
}


InvMethods::InvMethods()
{

	Inventory invArray[MAX_INVENTORY];
	//TODO Continue from here

}

// METHODS ********************************************************************


// Displays user menu
void Inventory::DisplayMenu()
{

	// Loops until user enters menu 5 to exit program.
	bool isExit = false;
	while (!isExit)
	{
		// Menu option chosen by user
		int option = 0;

		// Requests user input for menu selection
		bool isValid = false;
		while (!isValid)
		{
			// Application title
			cout << NEW_LINE << NEW_LINE << "------------------ Inventory "
					"Program - Assignment 1 -----------------" << endl;
			cout << "         This application records the inventory of "
					"your shop         " << endl;
			cout << "----------------------------------------------------"
					"-----------------" << NEW_LINE << endl;

			// Menu options
			cout << "1. Display Parts" << endl;
			cout << "2. Enter a New Part" << endl;
			cout << "3. Modify a Part" << endl;
			cout << "4. Display Inventory Total" << endl;
			cout << "5. Save and Exit Program" << NEW_LINE << endl;

			// Receives user input and places it in option
			cout << "Please select a menu by entering a number: ";
			cin >> option;


			// Checks to see if input is between 1 and 5, and max
			// inventory has been reached
			if ((option >= 1) && (option <= MENU_ITMES_COUNT))
			{
				if ((invCount >= MAX_INVENTORY) && (option == 2))
				{
					cout << NEW_LINE << "********************** Max Inventory "
							"Reached ************************" << endl;
				}
				else 
				{
					isValid = true;
					
					// Enters page depending on chosen option
					switch (option)
					{
					case 1 :
						// Marked to to display page title
						DisplayParts(true);
						break;

					case 2 :
						NewPart();
						break;

					case 3 :
						ModifyPart();
						break;

					case 4 :
						DisplayInvTotal();
						break;

					case 5 :
						// Returns true once fuction is completed
						isExit = ExitProgram();
						break;
					}
				}
			}
			else
			{
				cout << NEW_LINE << "************************** Invalid "
						"option ***************************" << endl;
			}

			// Clears any data in the cin buffer
			cin.clear();
			cin.ignore(10000,'\n');
		}
	}
}


/*****************************************************************************/


// Prints current inventory
void Inventory::DisplayParts(bool useTitle)
{

	// The title will print if true
	if (useTitle)
	{
		cout << NEW_LINE << "----------------------------------------"
				"-----------------------------" << endl;
		cout << "Part List";
		cout << NEW_LINE << "----------------------------------------"
				"-----------------------------" << endl;

		// Clears any data in the cin buffer
		cin.clear();
		cin.ignore(10000,'\n');
	}


	// This is the formatting of the labels above the items
	cout << endl;
	cout << left;
	cout << setw(5) << "#";
	cout << setw(20) << "Part Name";
	cout << right;
	cout << setw(12) << "Qty";
	cout << setw(16) << "Price";
	cout << setw(16) << "Total Value" << endl << endl;


	// Loops through all inventory items stored and prints them
	// to the screen.
	for (int i = 0; i < invCount; i++)
	{
		formatItemDisplay(i, false);
	}


	// Menu is displayed until user enters a key.
	cout << NEW_LINE << "Press Enter key to continue: ";


}


/*****************************************************************************/


// Adds an additional item to inventory
void Inventory::NewPart()
{

	// Prints title
	cout << NEW_LINE << "--------------------------------------------"
			"-------------------------" << endl;
	cout << "New Part";
	cout << NEW_LINE << "--------------------------------------------"
			"-------------------------" << NEW_LINE << endl;


	// Requests the needed info from user to create new item.
	RequestPartInfo(-1);


	// Displays the newly created item formatted.
	formatItemDisplay(invCount - 1, true);


	// Menu is displayed until user enters a key.
	cout << NEW_LINE << "Press Enter key to continue: ";
	

//	// Credit goes to: Computergeek01 -
//	// http://www.cplusplus.com/forum/windows/55426/#msg299186
//	cin.sync(); // Flush The Input Buffer Just In Case
//	cin.ignore(); // There's No Need To Actually Store The Users Input
}


/*****************************************************************************/


// Overloaded to allow for adding a new part without user input
void Inventory::NewPart(string item, int quantity, float price)
{

	// Adds the entered information to the inventory list
	inventory[invCount].partNum = invCount + 1;
	inventory[invCount].item = item;
	inventory[invCount].quantity = quantity;
	inventory[invCount].price = price;
	inventory[invCount].totalCost = CalcTotalCost(invCount);

	invCount += 1;
}


/*****************************************************************************/


// User selects item to be modified and updates info
void Inventory::ModifyPart()
{

	// Item chosen by user to modify
	int chosenItem;

	// Prints title
	cout << NEW_LINE << "--------------------------------------------"
			"-------------------------" << endl;
	cout << "Modify a Part";
	cout << NEW_LINE << "--------------------------------------------"
			"-------------------------" << endl;

	// Requests the user to select a specific item
	cin.clear();
	cin.ignore(10000,'\n');


	// Displays the current items
	DisplayParts(false);



	cout << NEW_LINE << "Please select part number between 1 and "
			<< invCount << ": " << endl;
	cin >> chosenItem;

	// Reduces number to make the index accurate
	chosenItem -= 1;


	// Shows the current item selected
	formatItemDisplay(chosenItem, true);
	cout << endl;


	// Requests the needed info from user to create new item.
	RequestPartInfo(chosenItem);


	// Shows the modified item
	formatItemDisplay(chosenItem, true);


	// Menu is displayed until user enters a key.
	cout << NEW_LINE << "Press Enter key to continue: ";
	

//	// Credit goes to: Computergeek01 -
//	// http://www.cplusplus.com/forum/windows/55426/#msg299186
//	cin.sync(); // Flush The Input Buffer Just In Case
//	cin.ignore(); // There's No Need To Actually Store The Users Input
}


/*****************************************************************************/


// Prints the total value of inventory
void Inventory::DisplayInvTotal()
{

	// Prints title
	cout << NEW_LINE << "--------------------------------------------"
			"-------------------------" << endl;
	cout << "Inventory Total";
	cout << NEW_LINE << "--------------------------------------------"
			"-------------------------" << NEW_LINE << endl;


	// Inventory total value
	float invTotal = 0;

	// Extracts every items total cost and adds it to invTotal
	for (int i = 0; i < invCount; i++)
	{
		invTotal += inventory[i].totalCost;
	}


	// Displays the total cost of inventory
	cout << "Total cost of inventory: $" << fixed << setprecision(2)
			<< invTotal << endl;

}


/*****************************************************************************/


// Exits the menu loop by returning true
bool Inventory::ExitProgram()
{
	return true;
}


/*****************************************************************************/


// Asks the user for item, quantity, and cost
// Lists negative number to specify new part
void Inventory::RequestPartInfo(int itemNum)
{

	// Used to hold temporary string until it is parsed into value
	string temp;
	string item;
	int quantity;
	float price;


	// Clears any data in the cin buffer
	cin.clear();
	cin.ignore(10000,'\n');


	// Receives input from user
	cout << "Enter Item: ";
	getline(cin, item);

	// Removes the new line character
	item = item.substr(0, item.length());
	cout << "Enter Quantity: ";
	getline(cin, temp);

	 // Parses the string into integer
	stringstream(temp) >> quantity;
	cout << "Enter Price: ";
	getline(cin,temp);

	// Parses the string into float
	stringstream(temp) >> price;



	// Determines if new item or modifying an existing item
	if (itemNum < 0)
	{
		NewPart(item, quantity, price);
	}
	else
	{
		inventory[itemNum].item = item;
		inventory[itemNum].quantity = quantity;
		inventory[itemNum].price = price;
		inventory[itemNum].totalCost = CalcTotalCost(itemNum);
	}

}


/*****************************************************************************/


// Parses string passed using comma delimiters and adds info to inventory
int Inventory::ParseLine(string line)
{

	// First value of substring
	int sub1 = 0;

	// Second value of substring
	int sub2 = line.find(',');

	string item;
	string temp;
	int quantity;
	float price;


	// Tries to parse the information into the correct fields
	// Exception is thrown if error occurs.
	try
	{
		// Parses the item
		item = line.substr(sub1, (sub2-sub1));

		// Removes item from line
		sub1 = item.length() + 1;
		sub2 = line.length();
		line = line.substr(sub1, (sub2 - sub1));

		// Parses the quantity
		sub1 = 0;
		sub2 = line.find(',');
		temp = line.substr(sub1, (sub2-sub1));

		// Parses the string into integer
		stringstream(temp) >> quantity;

		// Parses the price
		sub1 = temp.length() + 1;
		sub2 = line.length();
		temp = line.substr(sub1, (sub2 - sub1));

		// Parses the string into float
		stringstream(temp) >> price;



		// Creates new part from the parsed info
		NewPart(item, quantity, price);

		return 1;
	}
	catch (int i)
	{
		cout << "ERROR: Unable to open file" << endl;
		return 0;
	}

}


/*****************************************************************************/


// Returns the total cost of inventoried item
float Inventory::CalcTotalCost(int item)
{

	// Multiplies the items price by quantity
	float totalCost = inventory[item].price * float(inventory[item].quantity);
	return totalCost;
}


/*****************************************************************************/


// Formats the items to display correctly within a table
void Inventory::formatItemDisplay(int itemNum, bool displayLabels)
{

	// This is the formatting of the labels above the items
	if (displayLabels) {
		cout << endl;
		cout << left;
		cout << setw(5) << "#";
		cout << setw(20) << "Part Name";
		cout << right;
		cout << setw(12) << "Qty";
		cout << setw(16) << "Price";
		cout << setw(16) << "Total Value" << endl << endl;
	}


	// Displays the item passed into this function
	cout << left;
	cout << setw(5) << inventory[itemNum].partNum;
	cout << setw(20) << inventory[itemNum].item;
	cout << right;
	cout << setw(12) << inventory[itemNum].quantity;
	cout << setw(7) << "$";
	cout << setw(9) << fixed << setprecision(2) << inventory[itemNum].price;
	cout << setw(7) << "$";
	cout << setw(9) << fixed << setprecision(2)
			<< inventory[itemNum].totalCost << endl;
}

