#pragma once
#include "Weapon.h"

class Inventory
{
public:
	Inventory();
	virtual ~Inventory();

	//Accessors
	//const std::vector<Item>& fGetBag() const { return bag; };

	//Functions
	void fAddItem(const Item& item);
	void fDropItem();
	void fListItems();

	//Containter
	std::vector<Item> bag;
	std::vector<Weapon> weapon;

private:

	//Pointer & objects
	Item* item;
	Weapon* weapon;
};

