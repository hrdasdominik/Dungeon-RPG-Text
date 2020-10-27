#pragma once
#include "Item.h"

class Inventory
{
public:
	Inventory();
	virtual ~Inventory();

	//Accessors


	//Modifiers


	//Functions
	void fAddItem(const Item& item);
	void fDropItem(int index);
	void fListItems();

private:
	//Containter
	std::vector<Item> bag;

	//Pointer & objects
	Item* item;
};

