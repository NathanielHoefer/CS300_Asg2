/*****************************************************************************/
/* Program 2 - Inventory Application										 */
/*****************************************************************************
    Author: Nathaniel Hoefer
    Student ID: X529U639
    Program: #2
*/
#include "InvMethods.hpp"
#include "Inventory.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <sstream>

using namespace std;



/*****************************************************************************/
// Class Source Functions
/*****************************************************************************/


// CONSTRUCTORS ***************************************************************


InvMethods::InvMethods()
{

	// Currently no settings for this constructor

}



// METHODS ********************************************************************


// Displays user menu
void InvMethods::DisplayMenu()
{

	ReadFile();

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
					"Program - Assignment 2 -----------------" << endl;
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
				if ((getInvCount() >= MAX_INVENTORY) && (option == 2))
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

	SaveFile();
}


/*****************************************************************************/


// Prints current inventory
void InvMethods::DisplayParts(bool useTitle)
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
	for (int i = 0; i < getInvCount(); i++)
	{
		formatItemDisplay(i, false);
	}


	// Menu is displayed until user enters a key.
	cout << NEW_LINE << "Press Enter key to continue: ";


}


/*****************************************************************************/


// Adds an additional item to inventory
void InvMethods::NewPart()
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
	int partIndex = getInvCount() - 1;
	formatItemDisplay(partIndex, true);


	// Menu is displayed until user enters a key.
	cout << NEW_LINE << "Press Enter key to continue: ";

}


/*****************************************************************************/


// Overloaded to allow for adding a new part without user input
void InvMethods::NewPart(string item, int quantity, float price)
{
	int partIndex = getInvCount();
	int partNum = partIndex + 1;

	// Adds the entered information to the inventory list
	invArray[partIndex].ModifyItem(partNum, item, quantity, price);

	InvMethods::incrementInvCount();
}


/*****************************************************************************/


// User selects item to be modified and updates info
void InvMethods::ModifyPart()
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
			<< getInvCount() << ": " << endl;
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

}


/*****************************************************************************/


// Prints the total value of inventory
void InvMethods::DisplayInvTotal()
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
	for (int i = 0; i < getInvCount(); i++)
	{
		invTotal += invArray[i].getTotalCost();
	}


	// Displays the total cost of inventory
	cout << "Total cost of inventory: $" << fixed << setprecision(2)
			<< invTotal << endl;

}


/*****************************************************************************/


// Exits the menu loop by returning true
bool InvMethods::ExitProgram()
{
	return true;
}


/*****************************************************************************/


// Asks the user for item, quantity, and cost
// Lists negative number to specify new part
void InvMethods::RequestPartInfo(int partIndex)
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
	if (partIndex < 0)
	{
		NewPart(item, quantity, price);
	}
	else
	{
		invArray[partIndex].ModifyItem(partIndex + 1, item, quantity, price);
	}

}


/*****************************************************************************/


// Parses string passed using comma delimiters and adds info to inventory
int InvMethods::ParseLine(string line)
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
float InvMethods::CalcTotalCost(int partIndex)
{

	// Multiplies the items price by quantity
	float totalCost = invArray[partIndex].getPrice() * float(invArray[partIndex].getQuantity());
	return totalCost;
}


/*****************************************************************************/


// Formats the items to display correctly within a table
void InvMethods::formatItemDisplay(int partIndex, bool displayLabels)
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
	cout << setw(5) << invArray[partIndex].getPartNum();
	cout << setw(20) << invArray[partIndex].getItem();
	cout << right;
	cout << setw(12) << invArray[partIndex].getQuantity();
	cout << setw(7) << "$";
	cout << setw(9) << fixed << setprecision(2) << invArray[partIndex].getPrice();
	cout << setw(7) << "$";
	cout << setw(9) << fixed << setprecision(2)
			<< invArray[partIndex].getTotalCost() << endl;
}


/*****************************************************************************/


// Reads the file to inventory array
void InvMethods::ReadFile()
{


	// Opens text file and reads the values into the inventory.
	ifstream readFile(INV_FILE_NAME.c_str());
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
			if (getInvCount() < MAX_INVENTORY)
			{
				no_error = ParseLine(fileLine);
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
}


/*****************************************************************************/


// Reads the file to inventory array
void InvMethods::SaveFile()
{
	// Opens Text file and saves each part until inventory is complete.
	ofstream saveFile(INV_FILE_NAME.c_str());
	int inventoryCount = getInvCount();
	if (saveFile.is_open())
	{
		// Writes every item to its own line using commas as delimiters
		for (int i = 0; i < inventoryCount; i++)
		{

			string item = invArray[i].getItem();
			int quantity = invArray[i].getQuantity();
			float price = invArray[i].getPrice();
			saveFile << item << "," << quantity << "," << price << endl;
		}
		saveFile.close();

		cout << NEW_LINE << "File Saved" << endl;
	}

	cout << "Program Ended" << endl;
}
