#pragma once
#include "Item.h"

class Weapon : public Item
{
public:
	Weapon(std::string name, std::string id = "Weapon");
	virtual ~Weapon() {};

	//Accessor
	inline const int& fGetDamage() { return damage; };
	inline const int& fGetTimes() { return times; }

	//Modifiers
	inline int& fSetDamage(int& damage) { return this->damage = damage; }
	inline int& fSetTimes(int& times) { return this->times = times; }

private:
	//Behind the scene functions
	void fReadFromSQL(std::string name);

	int damage;
	int times;
};

