#pragma once
#include "Item.h"

class Weapon : public Item
{
public:
	Weapon(std::string name = "None", int damage = 0, int times = 0, std::string id = "Weapon");
	virtual ~Weapon() {};

	//Accessor
	inline const int& fGetDamage() { return damage; };
	inline const int& fGetTimes() { return times; }

	//Modifiers
	inline int& fSetDamage(int& damage) { return this->damage = damage; }
	inline int& fSetTimes(int& times) { return this->times = times; }


	//Functions

private:
	int damage;
	int times;
};

