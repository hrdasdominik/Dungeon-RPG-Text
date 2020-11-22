#pragma once
#include "Item.h"

class Armor : public Item
{
public:
	Armor(std::string name, std::string id = "Armor");
	virtual ~Armor() {};

	//Accessor
	inline const int& fGetArmor() { return armor; };

	//Modifiers
	inline int& fSetArmor(int& armor) { return this->armor = armor; }

private:
	//Behind the scene functions
	void fReadFromSQL(std::string name);

	int armor;
};

