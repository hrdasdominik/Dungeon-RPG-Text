#pragma once
#include "Item.h"

class Weapon : public Item
{
public:
	Weapon(std::string name = "NONE", int damage = 0);
	virtual ~Weapon();

	//Accessor
	inline const int& fGetDamage() { return damage; }

private:
	int damage;
};

