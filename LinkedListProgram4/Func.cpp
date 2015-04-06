#include "LinkedList.h"
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;


//-----------------------------------------
//This function displays our list as it is
//-----------------------------------------
void AuctionList::displayList() const
{

	ListNode *nodePtr = nullptr;

	nodePtr = head;

	//Our header output
	if (nodePtr)
	{

		cout << "Item ID";
		cout << setw(10) << "Seller";
		cout << setw(10) << "Buyer";
		cout << setw(15) << "Price" << endl;

	}
	else
		cout << "No List." << endl; //If there are no items in the list this displays

	while (nodePtr)
	{

		//Display node data
		cout << left << setw(10) << nodePtr->item.itemName;
		cout << left << setw(12) << nodePtr->item.sellerName;
		cout << left << setw(10) << nodePtr->item.buyerName;
		cout << right << fixed << setprecision(2) << nodePtr->item.price << endl;


		//Move to next node
		nodePtr = nodePtr->next;
	}


}

//--------------------------------------------------------
//This function takes input from the user and enters it
//into the list
//--------------------------------------------------------
void AuctionList::insertNode(ItemInfo auction)
{

	ListNode *newNode;
	ListNode *nodePtr;
	ListNode *previousNode = nullptr;

	newNode = new ListNode;
	newNode->item = auction;
	
	//Successful insertion
	cout << auction.itemName << " was inserted into the list\n";

	if (!head)
	{

		head = newNode;
		newNode->next = nullptr;
		cout << endl;
	}

	else
	{

		nodePtr = head;

		previousNode = nullptr;

		while (nodePtr != nullptr && (strcmp((*nodePtr).item.itemName, auction.itemName) < 0))
		{

			previousNode = nodePtr;
			nodePtr = nodePtr->next;

		}

		if (previousNode == nullptr)
		{

			head = newNode;
			newNode->next = nodePtr;

		}

		else
		{

			previousNode->next = newNode;
			newNode->next = nodePtr;

		}
	}
}
//--------------------------------------------------------
//This function deletes a node after getting input from
//the user
//----------------------------------------------------------
void AuctionList::deleteNode(ItemInfo auction)
{

	ListNode *nodePtr;
	ListNode *previousNode = nullptr;

	if (!head)
	{
		cout << "No list." << endl; //Displays if there are no items in the list
		
		return;
	}
	if (strcmp(head->item.itemName, auction.itemName) == 0)
	{
		//finds our node and deletes the data input from the user
		nodePtr = head->next;
		delete head;
		head = nodePtr;
		cout << auction.itemName << " was removed from the list." << endl;

	}

	else
	{

		nodePtr = head;

		while (nodePtr != nullptr && (strcmp((*nodePtr).item.itemName, auction.itemName) != 0))
		{

			previousNode = nodePtr;
			nodePtr = nodePtr->next;

		}

		if (nodePtr)
		{

			previousNode->next = nodePtr->next;
			delete nodePtr;
			cout << auction.itemName << " was removed from the list." << endl;

		}
	}
}

//-----------------------------------------------------------
//This function takes input from the user and goes to find it
//-----------------------------------------------------------
void AuctionList::findNode(ItemInfo auction)
{

	ListNode *nodePtr = 0;
	ListNode *previousNode = nullptr;

	if (!head)
	{
		cout << "Empty list." << endl; //Displays if there are no items in the list

		return;
	}

	else
		nodePtr = head;



		while (nodePtr != nullptr && (strcmp((*nodePtr).item.itemName, auction.itemName) != 0))
		{

			previousNode = nodePtr;
			nodePtr = nodePtr->next;

		}

		if (nodePtr)
		{
			cout << "Found." << endl; //Displays if item is found
		}

		else
			cout << "Not found." << endl; //Displays if item is not found
	}

//Deconstructer
AuctionList::~AuctionList()
{

	ListNode *nodePtr;
	ListNode *nextNode;

	nodePtr = head;

	while (nodePtr != nullptr)
	{

		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;

	}

}


