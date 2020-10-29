#pragma once
#include "Dice.h"

class Item
{
public:
	Item();
	Item(std::string name);
	virtual ~Item();

	//Accessors
	inline const std::string& fGetName() { return name; };
	

	//Modifiers
	inline std::string& fSetName(std::string& name) { return this->name = name; }

private:
	std::string name;
};

