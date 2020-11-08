#include "Inventory.h"

//Constructor
Inventory::Inventory()
{
	itemList["rock"] = "A plain rock. Might try to hit somebody or use as distraction.\n";
	itemList["iron key"] = "A key. Looks like made of iron. \nMight unlock some door or chest.\n";
}

//Functions
void Inventory::fAddItem(Item& item)
{
	bag.push_back(&item);
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
		std::cout << i << " - " << bag[i]->fGetName() << '\n';
	}
}

void Inventory::fPrintDescription()
{
	int choice;
	fListItems();
	std::cout << "Which item do you want to inspect: ";
	std::cin >> choice;
	fGetDescription(bag[choice]->fGetName());
}

//Weapon functions
int Inventory::fEquipWeapon(Item& item)
{
	if (weaponSlot.size() == 0)
	{
		if (item.fGetId() == weapon.fGetId())
		{
			Weapon* wp = dynamic_cast<Weapon*>(&item);
			fAddWeapon(*wp);
			return wp->fGetDamage();
		}
		else
		{
			std::cout << "That's not a weapon!\n" << std::endl;
		}
	}
	else
	{
		std::cout << "Please first unequip the weapon! \n";
	}
}

int Inventory::fUnEquipWeapon()
{
	Item* wp = dynamic_cast<Item*>(weaponSlot[0]);
	bag.push_back(weaponSlot[0]);
	weaponSlot.erase(weaponSlot.begin());
	return 4;
}

//Armor functions
int Inventory::fEquipArmor(Item& item)
{
	if (armorSlot.size() == 0)
	{
		if (item.fGetId() == armor.fGetId())
		{
			Armor* ar = dynamic_cast<Armor*>(&item);
			fAddArmor(*ar);
			return ar->fGetArmor();
		}
		else
		{
			std::cout << "That's not an armor!\n" << std::endl;
		}
	}
	else
	{
		std::cout << "Please first unequip the armor! \n";
	}
}

int Inventory::fUnEquipArmor()
{
	Item* ar = dynamic_cast<Item*>(weaponSlot[0]);
	bag.push_back(armorSlot[0]);
	armorSlot.erase(armorSlot.begin());
	return 10;
}

//Behind the scene functions
std::string Inventory::fGetDescription(std::string name)
{
	auto match = itemList.find(name);
	return match->second;
}

void Inventory::fDeleteItem(int index)
{
	bag.erase(bag.begin() + index);
}

void Inventory::fAddWeapon(Weapon& weapon)
{
	weaponSlot.push_back(&weapon);
}

void Inventory::fAddArmor(Armor& armor)
{
	armorSlot.push_back(&armor);
}