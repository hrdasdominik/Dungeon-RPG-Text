#include "Inventory.h"

Inventory::Inventory()
{
	item = {};
}

Inventory::~Inventory()
{

}

void Inventory::fAddItem(const Item& item)
{
	bag.push_back(item);
}

void Inventory::fDropItem()
{
	fListItems();
	int index = 0;
	std::cout << "Which item would you like to drop: ";
	std::cin >> index;
	bag.erase(bag.begin() + index);
}

void Inventory::fListItems()
{
	for (unsigned i = 0; i < bag.size(); i++)
	{
		std::cout << i << " - " << bag[i].fGetName() << '\n';
	}
}
