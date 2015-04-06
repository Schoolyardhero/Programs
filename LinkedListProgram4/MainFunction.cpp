#include <iostream>
#include "LinkedList.h"


using namespace std;


void RemoveOrFind(AuctionList::ItemInfo &item)
{

	cout << "Enter Item Name:" << endl;
	cin.getline(item.itemName, 6);
	cout << endl;

}

//----------------------------------------------------
//This function creates the struct for our linked list
//----------------------------------------------------
void dataInput(AuctionList::ItemInfo &item)
{

	cout << "Enter item name: " << endl;
	cin.getline(item.itemName, 6);
	cout << "Enter seller name: " << endl;
	cin.getline(item.sellerName, 10);
	cout << "Enter buyer name: " << endl;
	cin.getline(item.buyerName, 10);
	cout << "Enter Price: " << endl;
	cin >> item.price;
	cin.ignore();
	cout << endl;

}

int main()
{

	AuctionList list;
	AuctionList::ItemInfo item;
	int choice = 0;

	while (choice >= 0)
	{
		//Let's allow the user to choose what action they would like to take
		cout << "Choose an option: \n1. Insert\n2. Remove\n3. Display\n4. Find\n0. Abort" << endl;
		cin >> choice;
		cin.ignore();

		switch (choice)
		{

		case 1: //Inserting
			dataInput(item);
			list.insertNode(item);
			break;

		case 2: //Deleting
			RemoveOrFind(item);
			list.deleteNode(item);
			break;

		case 3: //Displaying
			list.displayList();
			break;

		case 4: //Searching
			RemoveOrFind(item);
			list.findNode(item);
			break;

		case 0: //Exiting the program when user is finished
			return 0;
			break;

		}
	}
	

	
	return 0;

}
