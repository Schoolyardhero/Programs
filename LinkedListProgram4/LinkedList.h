#ifndef LINKEDLIST_H
#define LINKEDLIST_H


//This is the class of our linked list
class AuctionList
{

public:
	//Struct for our linked list info
	struct ItemInfo
	{

		char itemName[6];
		char sellerName[10];
		char buyerName[6];
		double price;


	};

private:

	struct ListNode
	{

		ItemInfo item;
		struct ListNode *next;

	};

	ListNode *head;

public:


	AuctionList()
	{
		head = nullptr;
	}

	~AuctionList();

	void insertNode(ItemInfo item);
	void deleteNode(ItemInfo item);
	void displayList() const;
	void findNode(ItemInfo item);
	void dataInput(ItemInfo item);

};

#endif
