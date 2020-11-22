#pragma once
#include "Dice.h"

class Item
{
public:
	Item(std::string name = "None", std::string id = "Item")
	{
		this->name = name;
		this->id = id;
	};
	virtual ~Item() {};

	//Accessors
	inline std::string& fGetName() { return name; };
	inline std::string& fGetId() { return id; }
	inline char*& fGetDescription() { return description; }

	//Modifiers
	inline std::string& fSetName(std::string& name) { return this->name = name; }
	inline std::string& fSetId(std::string& id) { return this->id = id; }
	inline char*& fSetDescription(char*& description) { return this->description = description; }
	
private:
	std::string name;
	std::string id;
	char* description;
};