#include "Inventory.h"

Inventory::Inventory()
{

}

Inventory::~Inventory()
{

}

void Inventory::fAddItem(Item& item)
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

void Inventory::fAddWeapon()
{
	int choice;
	std::cout << "Choose a weapon from the list: \n" << std::endl;
	fListItems();
	std::cout << "Choose: ";
	std::cin >> choice;
	weaponSlot->push_back(bag.at(choice));
}
