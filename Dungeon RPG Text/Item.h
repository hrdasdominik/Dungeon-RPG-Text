#pragma once
#include <string>

class Item
{
public:
	Item();
	virtual ~Item();
private:
	int space;
	std::string name;
};

