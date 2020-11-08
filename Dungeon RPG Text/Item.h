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
	inline const std::string& fGetName() { return name; };
	inline const std::string& fGetId() { return id; }
	inline const std::string& fGetDescription() { return description; }

	//Modifiers
	inline std::string& fSetName(std::string& name) { return this->name = name; }
	inline std::string& fSetId(std::string& id) { return this->id = id; }

	//Functions
	
private:
	
	std::string name;
	std::string id;
	std::string description;
};