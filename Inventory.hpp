/*****************************************************************************/
/* Program 2 - Inventory Application										 */
/*****************************************************************************
    Author: Nathaniel Hoefer
    Student ID: X529U639
    Program: #2


Class Name: Inventory
	The inventory class contains only the members associated with the inventory
	which are part number, item, quantity, price, and total cost.

Data:		- partNum - part number that should hold int from 1 to 100
			- item - Name of item
			- quantity - quantity of how many of the part there is
			- price - price per item
			- totalCost - total cost of the inventory items

Cnstrctrs:	+ Inventory() - Sets the values to default
			+ Inventory(item,quantity,price) - Sets the values and calculates
				the partNum and totalCost.

Mutator Functions:
			+ setPartNum
			+ setItem
			+ setQuantity
			+ setPrice
			+ setTotalCost

Accessor Functions:
			+ getPartNum
			+ getItem
			+ getQuantity
			+ getPrice
			+ getTotalCost

Functions:	+ ModifyItem(partNum,item,quantity,price) - Updates the info
				based on the partNum chosen
				Input Parms: int partNum - is the index of part to be changed
							string item - name of item
							quantity - number of that specific item
							price - price per item
				Output Parms: None
				> Assign arguments to values
*/
#include <string>

using namespace std;

#ifndef _INVENTORY_
#define _INVENTORY_

/* The inventory class contains only the members associated with the inventory
 * which are part number, item, quantity, price, and total cost.
 */
class Inventory
{

	private:

// Member Variables

	// part number that should hold int from 1 to 100
	int m_partNum;

	// Name of item
	string m_item;

	// quantity of how many of the part there is
	int m_quantity;

	// price per item
	float m_price;

	// total cost of the inventory items
	float m_totalCost;



	public:

// Constructor

	Inventory();
	Inventory(string item, int quantity, float price);


// Mutators and Accessors

	void setPartNum(int partNum) { m_partNum = partNum; };
	void setItem(string item) { m_item = item; };
	void setQuantity(int quantity) { m_quantity = quantity; };
	void setPrice(float price) { m_price = price; };
	void setTotalCost(float totalCost) { m_totalCost = totalCost; };

	int getPartNum() { return m_partNum; };
	string getItem() { return m_item; };
	int getQuantity() { return m_quantity; };
	float getPrice() { return m_price; };
	float getTotalCost() { return m_totalCost; };


// Methods

	// Updates the part info based on the partNum chosen
	void ModifyItem(int partNum, string item, int quantity, float price);

};

#endif // Inventory
