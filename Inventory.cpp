/*****************************************************************************/
/* Program 2 - Inventory Application										 */
/*****************************************************************************
    Author: Nathaniel Hoefer
    Student ID: X529U639
    Program: #2
*/

#include "Inventory.hpp"
#include "InvMethods.hpp"


/*****************************************************************************/
// Class Source Functions
/*****************************************************************************/


// CONSTRUCTORS ***************************************************************


Inventory::Inventory()
{
	// Default values so that there is no garbage
	m_partNum = 1;
	m_item = "Default";
	m_quantity = 1;
	m_price = 1.00;
	m_totalCost = 1.00;
}


Inventory::Inventory(string item, int quantity, float price)
{
	// Increased the inventory count by 1
	InvMethods::incrementInvCount();

	// Sets the members to the entered values
	m_partNum = InvMethods::getInvCount();
	m_item = item;
	m_quantity = quantity;
	m_price = price;
	m_totalCost = quantity * price;
}



// METHODS ********************************************************************


void Inventory::ModifyItem(int partNum, string item, int quantity, float price)
{
	m_partNum = partNum;
	m_item = item;
	m_quantity = quantity;
	m_price = price;
	m_totalCost = quantity * price;

}
