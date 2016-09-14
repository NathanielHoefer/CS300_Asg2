/*****************************************************************************/
/* Program 2 - Inventory Application										 */
/*****************************************************************************
    Author: Nathaniel Hoefer
    Student ID: X529U639
    Program: #2


Class Name: InvMethods
	This inventory class is used to contain all of the methods
	pertaining to the Inventory process. There are some things that
	are not as efficient as they could be, but I decided to encapsulate
	as much as I could leaving very few steps within the main method.

Data:		- invArray[] (inventory) - Holds all of the inventory objects.
			- invCount (int, static) - The number of different inventory items
			- invTotal (float, static) - The total value of all the items

Cnstrctrs:	+ InvMethods() - Creates Inventory array and

Mutator Functions:
			+ incrementInvCount (static) - Increases count by 1.
			+ setInvTotal (static)

Accessor Functions:
			+ getInvCount (static)
			+ getInvTotal (static)

Functions:	+ DisplayMenu() - Displays user menu
				Input Parms: None
				Output Parms: None
				> Print title and options
				> Request and validate user selection
				> Implement method based on selection

			- DisplayParts(useTitle) - Prints current inventory
				Input Parms: bool useTitle - Whether to display title
				Output Parms: None
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

			- RequestPartInfo(partIndex) - Asks the user for item, quantity,
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

			- CalcTotalCost(partIndex) - Returns the total cost of parts in
				inventory
				Input Parms: Part number between 0-Max count
				Output Parms: None
				Return: The float total cost of part in inventory
				> Price of Part * Quantity of Part

			- FormatItemDisplay(partIndex,displayLabels) - Formats the items to
				display correctly within a table.
				Input Parms: int partNum - part to be formatted
							bool displayLabels - true to display labels
				Output Parms: Prints part info with or without labels
				> Display part if displayLabels == true
				> Display formatted part info.

			- ReadFile() - Reads the file to inventory array
				Input Parms: inventory.txt file
				Output Parms: None
				> Open file stream
				> Read and Parse each line
				> Print error message if there is an error

			- SaveFile() - Saves file to inventory.txt.
				Input Parms: None
				Output Parms: inventory.txt file
				> Open stream
				> Save each part as a line with comma delimiters
				> Close stream

*/
#include "Inventory.hpp"
#include <string>



/*****************************************************************************/
// Constants
/*****************************************************************************/


// The number of windows displayed in the menu.
const int MENU_ITMES_COUNT = 5;

// Used in case there is an issue with going between Windows and Linux
const char NEW_LINE = '\n';

// Maximum number of items in inventory
const int MAX_INVENTORY = 100;

// Name of file where inventory is saved
const string INV_FILE_NAME = "inventory.txt";



/* This inventory class is used to contain all of the methods
 * pertaining to the Inventory process. There are some things that
 * are not as efficient as they could be, but I decided to encapsulate
 * as much as I could leaving very few steps within the main method.
 */
class InvMethods
{

	private:

// Member Variables

	// Holds all of the inventory objects.
	Inventory invArray[MAX_INVENTORY];
	//inventoryItem inventory[MAX_INVENTORY];

	// The number of different inventory items
	static int m_invCount;

	// The total value of all the items
	static float m_invTotal;



	public:

// Constructor

	InvMethods();


// Methods

	// Displays user menu
	void DisplayMenu();


// Mutators and Accessors

	// Accesses the member variables of the class
	static int getInvCount() { return m_invCount; };
	static float getInvTotal() { return m_invTotal; };

	// Modifies the member variables of the class
	static void incrementInvCount() { m_invCount += 1; };
	static void setInvTotal(float invTotal) { m_invTotal = invTotal; };



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
	void RequestPartInfo(int partIndex);

	// Formats the items to display correctly
	void formatItemDisplay(int partIndex, bool displayLabels);

	// Parses the line and adds info to inventory
	int ParseLine(string line);

	// Returns the total cost of inventoried item
	float CalcTotalCost(int item);

	// Reads and saves from file.
	void ReadFile();
	void SaveFile();

};
