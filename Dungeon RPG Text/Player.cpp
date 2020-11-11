#include "Player.h"

//Constructor
Player::Player()
{
	fInitialize("Player");
}


//Functions
void Player::fLevelUp()
{
	while (exp >= required_experience[level])
	{
		++level;
		std::cout << "Exp needed to next level: " << required_experience[level] << std::endl;

		if (class_name == "Fighter" || class_name == "Ranger")
			health = health + dice->fRoll(10, 1);

		else if (class_name == "Sorcerer")
			health = health + dice->fRoll(6, 1);
	}
}

void Player::fGiveExp()
{
	exp = exp + 45;
}

void Player::fGetStatsAttributes() const
{
	std::cout << std::endl;
	std::cout << "== Attributes ==" << std::endl;
	std::cout << "Strength: " << strength << " (" << mod_strength << ")" << std::endl;
	std::cout << "Dexterity: " << dexterity << " (" << mod_dexterity << ")" << std::endl;
	std::cout << "Constitution: " << constitution << " (" << mod_constitution << ")" << std::endl;
	std::cout << "Intelligence: " << intelligence << " (" << mod_intelligence << ")" << std::endl;
	std::cout << "Wisdom: " << wisdom << " (" << mod_wisdom << ")" << std::endl;
	std::cout << "Charisma: " << charisma << " (" << mod_charisma << ")" << std::endl;
	std::cout << std::endl;
}

void Player::fGetStatsAll() const
{
	std::cout << std::endl;
	std::cout << "= Character Sheet =" << std::endl;
	std::cout << "Name: " << name << std::endl;
	std::cout << "Class: " << class_name << std::endl;
	std::cout << "Health: " << health << std::endl;
	std::cout << "Damage: " << roll_times << "d" << damage << std::endl;
	std::cout << "Armor: " << armor_class << std::endl;
	std::cout << "Level: " << level << std::endl;
	std::cout << "Exp: " << exp << std::endl;
	std::cout << std::endl;
	std::cout << "== Attributes ==" << std::endl;
	std::cout << "Strength: " << strength << " (" << mod_strength << ")" << std::endl;
	std::cout << "Dexterity: " << dexterity << " (" << mod_dexterity << ")" << std::endl;
	std::cout << "Constitution: " << constitution << " (" << mod_constitution << ")" << std::endl;
	std::cout << "Intelligence: " << intelligence << " (" << mod_intelligence << ")" << std::endl;
	std::cout << "Wisdom: " << wisdom << " (" << mod_wisdom << ")" << std::endl;
	std::cout << "Charisma: " << charisma << " (" << mod_charisma << ")" << std::endl;
	std::cout << std::endl;
	std::cout << "== Saving throws ==" << std::endl;
	std::cout << "Strength: " << saving_strength << std::endl;
	std::cout << "Dexterity: " << saving_dexterity << std::endl;
	std::cout << "Constitution: " << saving_constitution << std::endl;
	std::cout << "Intelligence: " << saving_intelligence << std::endl;
	std::cout << "Wisdom: " << saving_wisdom << std::endl;
	std::cout << "Charisma: " << saving_charisma << std::endl;
	std::cout << std::endl;
	std::cout << "== Skills ==" << std::endl;
	std::cout << "Acrobatics: " << acrobatics << std::endl;
	std::cout << "Animal handling: " << animal_handling << std::endl;
	std::cout << "Arcana: " << arcana << std::endl;
	std::cout << "Athletics: " << athletics << std::endl;
	std::cout << "Deception: " << deception << std::endl;
	std::cout << "History: " << history << std::endl;
	std::cout << "Insight: " << insight << std::endl;
	std::cout << "Intimidation: " << intimidation << std::endl;
	std::cout << "Investigation: " << investigation << std::endl;
	std::cout << "Medicine: " << medicine << std::endl;
	std::cout << "Nature: " << nature << std::endl;
	std::cout << "Perception: " << perception << std::endl;
	std::cout << "Performance: " << performance << std::endl;
	std::cout << "Persuasion: " << persuasion << std::endl;
	std::cout << "Religion: " << religion << std::endl;
	std::cout << "Sleight of hand: " << sleight_of_hand << std::endl;
	std::cout << "Stealth: " << stealth << std::endl;
	std::cout << "Survival: " << survival << std::endl;
	std::cout << std::endl;
}

int Player::fRollInitiative()
{
	return dice->fRoll(20, 1) + mod_dexterity;
}


//Inventory
void Player::fListItem()
{
	inventory.fListItems();
}

void Player::fAddItem(Item& item)
{
	inventory.fAddItem(item);
}

//Weapon
void Player::fEquipWeapon()
{
	int choice;
	fListItem();
	std::cout << "Choose a weapon: ";
	std::cin >> choice;
	damage = inventory.fEquipWeapon(*inventory.fGetBag()[choice]);
	roll_times = inventory.fEquipTimes(*inventory.fGetWeaponSlot()[0]);
}

void Player::fUnEquipWeapon()
{
	damage = inventory.fUnEquipWeapon();
}

//Armor
void Player::fEquipArmor()
{
	int choice;
	fListItem();
	std::cout << "Choose an armor: ";
	std::cin >> choice;
	armor_class = inventory.fEquipArmor(*inventory.fGetBag()[choice]);
}

void Player::fUnEquipArmor()
{
	armor_class = inventory.fUnEquipArmor();
}

//Player creation
void Player::fInitialize(std::string name)
{
	//Attributes
	strength = dice->fRollStats();
	dexterity = dice->fRollStats();
	constitution = dice->fRollStats();
	intelligence = dice->fRollStats();
	wisdom = dice->fRollStats();
	charisma = dice->fRollStats();

	//Modifiers
	mod_strength = AttributeMod[strength - 1];
	mod_dexterity = AttributeMod[dexterity - 1];
	mod_constitution = AttributeMod[constitution - 1];
	mod_intelligence = AttributeMod[intelligence - 1];
	mod_wisdom = AttributeMod[wisdom - 1];
	mod_charisma = AttributeMod[charisma - 1];

	//Saving throws
	saving_strength = mod_strength;
	saving_dexterity = mod_dexterity;
	saving_constitution = mod_constitution;
	saving_intelligence = mod_intelligence;
	saving_wisdom = mod_wisdom;
	saving_charisma = mod_charisma;

	//Skills
	acrobatics = mod_dexterity;
	animal_handling = mod_wisdom;
	arcana = mod_intelligence;
	athletics = mod_strength;
	deception = mod_charisma;
	history = mod_intelligence;
	insight = mod_wisdom;
	intimidation = mod_charisma;
	investigation = mod_intelligence;
	medicine = mod_wisdom;
	nature = mod_intelligence;
	perception = mod_wisdom;
	performance = mod_charisma;
	persuasion = mod_charisma;
	religion = mod_intelligence;
	sleight_of_hand = mod_dexterity;
	stealth = mod_dexterity;
	survival = mod_wisdom;

	alive = true;
	this->name = name;
	class_name = "None";
	health = health + mod_constitution;
	health = fNoNull(health);
	armor_class = 0;
	initiative = mod_dexterity;
	exp = 0;
	level = 1;
	proficiency_bonus = ProficiencyBonus[level - 1];
	damage = 0;
	roll_times = 0;
}

bool Player::fIsAlive()
{
	if (health <= 0)
		return alive == false;
	else
		return alive == true;
}

void Player::fPickClass()
{
	std::cout << "== Pick a class ==" << std::endl;
	std::cout << "Fighter\n";
	std::cout << "Ranger\n";
	std::cout << "Enter: ";
	std::string choice;
	std::cin >> choice;
	std::cout << std::endl;
	fLoadClasses(choice);
}

void Player::fInsertName()
{
	std::cout << std::endl;
	std::string name;
	std::cout << "Enter your name: ";
	std::cin >> name;
	fInitialize(name);
}


//Behind the scene functions

void Player::fLoadClasses(std::string name)
{
	std::ifstream classlist("classlist.txt");

	if (classlist.is_open())
	{
		std::string line;
		bool found = false;
		while (!classlist.eof())
		{
			classlist >> line;
			if (line == name)
			{
				classlist >> this->class_name
					>> health
					>> armor_name
					>> weapon_name;
				found = true;
				//Add starting armor
				Armor armor(armor_name);
				inventory.fAddItem(armor);
				inventory.fEquipArmor(armor);
				armor_class = armor.fGetArmor();
				//Add starting weapon
				Weapon weapon(weapon_name);
				inventory.fAddItem(weapon);
				inventory.fEquipWeapon(weapon);
				damage = weapon.fGetDamage();
				roll_times = weapon.fGetTimes();
				fGetStatsAll();
			}
		}
		if(found == false)
		{ 
			std::cout << "Error. Write the name of the class." << std::endl;
			fPickClass();
		}
	}
	else
	{
		std::cout << "File failed to load." << std::endl;
	}
	classlist.close();
}

int Player::fNoNull(int value)
{
	value = (value < 0) ? 0 : value;
	return value;
}