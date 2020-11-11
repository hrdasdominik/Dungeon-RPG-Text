#pragma once
#include "Item.h"

class Armor : public Item
{
public:
	Armor(std::string name = "None", int armor = 0, std::string id = "Armor");
	virtual ~Armor() {};

	//Accessor
	inline const int& fGetArmor() { return armor; };

	//Modifiers
	inline int& fSetArmor(int& armor) { return this->armor = armor; }

	//Functions
	

private:
	int armor;
};

