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

*/

#include "Inventory.hpp"
#include "InvMethods.hpp"


/*****************************************************************************/
// Main Method
/*****************************************************************************/


// Initializing the static member variables of the InvMethods class
int InvMethods::m_invCount = 0;
float InvMethods::m_invTotal = 0;

int main(void)
{

	// Instantiated inventory object used for inventory procedures
	InvMethods inventory;

	// Displays the menu and enters loop until user is finished.
	inventory.DisplayMenu();

}


