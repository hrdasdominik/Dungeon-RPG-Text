#pragma once
#include "Weapon.h"

class Inventory
{
public:
	Inventory();
	virtual ~Inventory();

	//Functions
	void fAddItem(const Item& item);
	void fDropItem();
	void fListItems();
	
private:
	
	//Containter
	std::vector<Item> bag;

	//Pointer & objects
	Item* item;
};

