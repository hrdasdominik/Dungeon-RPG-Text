#include "Inventory.h"

Inventory::Inventory()
{

}

Inventory::~Inventory()
{

}

void Inventory::fAddItem(const Item& item)
{
	bag.push_back(item);
}

void Inventory::fDropItem(int index)
{
	bag.erase(bag.begin() + index);
}

void Inventory::fListItems()
{
	for (std::vector<Item>::iterator i = bag.begin(); i != bag.end(); ++i)
	{
		std::cout << *i << '\n';
	}
}
