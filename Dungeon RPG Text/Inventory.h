#pragma once
#include "Weapon.h"

class Inventory
{
public:
	Inventory();
	virtual ~Inventory();

	//Accessors
	const std::vector<Item>& fGetBag() const { return bag; };

	//Functions
	void fAddItem(Item& item);
	void fDropItem();
	void fListItems();
	void fAddWeapon();

	//Containter
	std::vector<Item> bag;
	std::vector<Weapon> weaponSlot[1];

};

