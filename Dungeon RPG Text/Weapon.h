#pragma once
#include "Item.h"

class Weapon : public Item
{
public:
	Weapon(std::string name = "None", int damage = 0, std::string id = "Weapon")
		: Item(name, id)
	{
		fSetName(name);
		fSetDamage(damage);
		fSetId(id);
	}
	virtual ~Weapon() {};

	//Accessor
	inline const int& fGetDamage() { return damage; };

	//Modifiers
	inline int& fSetDamage(int& damage) { return this->damage = damage; }

	//Functions

private:
	int damage;
};

