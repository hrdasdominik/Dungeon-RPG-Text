#pragma once
#include "Dice.h"

class Item
{
public:
	Item();
	Item(std::string);
	virtual ~Item();

	//Accessors
	inline const std::string& fGetName() { return name; };
	inline const int& fGetDamage() { return damage; };

	//Modifiers
	inline std::string& fSetName(std::string& name) { return this->name = name; }

private:
	std::string name;
	int damage;
};

