#pragma once
#include "Dice.h"

class Item
{
public:
	Item();
	virtual ~Item();
private:
	int space;
	std::string name;
};

