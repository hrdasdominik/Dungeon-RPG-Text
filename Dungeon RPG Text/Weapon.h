#pragma once
#include "Item.h"

class Weapon : public Item
{
public:
	Weapon(std::string name = "NONE", int damage = 0);
	virtual ~Weapon();

	//Accessor
	inline const int& fGetDamage() { return damage; };

	//Modifiers
	inline int& fSetDamage(int& damage) { return this->damage = damage; }

private:
	int damage;
};

