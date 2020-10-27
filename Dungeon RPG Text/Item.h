#pragma once
#include "Dice.h"

class Item
{
public:
	Item();
	Item(std::string);
	virtual ~Item();

	//Accessors
	inline const std::string fGetName() { return name; };

	//Modifiers

	
private:
	std::string name;
};

