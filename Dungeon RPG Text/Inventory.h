#pragma once
#include "Weapon.h"
#include "Armor.h"

class Inventory
{
public:
	Inventory();
	virtual ~Inventory() {};

	//Functions
	void fAddItem(Item& item);
	void fDropItem();
	void fListItems();
	void fPrintDescription();

	//Weapon functions
	int fEquipWeapon(Item& item);
	int fEquipTimes(Weapon& element);
	int fUnEquipWeapon();

	//Armor functions
	int fEquipArmor(Item& item);
	int fUnEquipArmor();

	//Accessor
	std::vector<Item*> fGetBag() { return bag; }
	std::vector<Weapon*> fGetWeaponSlot() { return weaponSlot; }
	std::vector<Armor*> fGetArmorSlot() { return armorSlot; }

private:
	//Behind the scene functions
	std::string fGetDescription(std::string name);
	void fDeleteItem(int index);
	void fAddWeapon(Weapon& weapon);
	void fAddArmor(Armor& weapon);

private:
	//Containters
	std::vector<Item*> bag;
	std::vector<Weapon*> weaponSlot;
	std::vector<Armor*> armorSlot;
	std::map<std::string, std::string> itemList;

	//Pointers & objects
	Item item;
};

