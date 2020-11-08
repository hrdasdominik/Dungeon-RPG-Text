#pragma once
#include "Inventory.h"

class Player
{
public:

	//Constructor n Deconstructor
	Player();
	virtual ~Player() {};

	//Functions
	void fLevelUp();
	void fGiveExp();
	void fGetStatsAttributes() const;
	void fGetStatsAll() const;

	//Inventory
	void fListItem();
	void fAddItem(Item& item);
	void fEquipWeapon();
	void fUnEquipWeapon();
	
	//Player creation
	void fInitialize(std::string name);
	bool fIsAlive();
	void fPickClass();
	void fInsertName();

	//Accessors
	inline const bool& fGetAlive() const { return alive; }
	inline const std::string& fGetName() const { return name; }
	inline const std::string& fGetClass() const { return class_name; }
	inline const int& fGetHealth() const { return health; }
	inline const int& fGetAC() const { return armor_class; }
	inline const int& fGetINT() const { return initiative; }
	inline const int& fGetExp() const { return exp; }
	inline const int& fGetLevel() const { return level; }
	inline const int& fGetPB() const { return proficiency_bonus; }

	//Modifiers
	inline void fSetClass(std::string& class_name) { this->class_name = class_name; }
	inline void fSetDamage(Weapon& weapon) { this->damage = weapon.fGetDamage(); }

private: 
	//Behind the scene functions
	void fClassCreation();
	int fNoNull(int value);

private:
	//Class pointers
	Dice* dice;
	Weapon* weapon;
	Inventory inventory;

	//Arrays
	int AttributeMod[20] = { -5, -4, -4, -3, -3, -2, -2, -1, -1, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5};
	int ProficiencyBonus[20] = { 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5 };
	int required_experience[11] = { 0, 45, 95, 145, 210, 285, 380, 495, 610, 745, 9999999 };

	//Basic stats
	bool alive;
	std::string name;
	std::string class_name;
	int health;
	int armor_class;
	int initiative;
	int exp;
	int level;
	int proficiency_bonus;
	int damage;

	//Attributes
	int strength;
	int dexterity;
	int constitution;
	int intelligence;
	int wisdom;
	int charisma;

	//Attribute modifiers
	int mod_strength;
	int mod_dexterity;
	int mod_constitution;
	int mod_intelligence;
	int mod_wisdom;
	int mod_charisma;

	//Saving throws
	int saving_strength;
	int saving_dexterity;
	int saving_constitution;
	int saving_intelligence;
	int saving_wisdom;
	int saving_charisma;

	//Skills
	int acrobatics;
	int animal_handling;
	int arcana;
	int athletics;
	int deception;
	int history;
	int insight;
	int intimidation;
	int investigation;
	int medicine;
	int nature;
	int perception;
	int performance;
	int persuasion;
	int religion;
	int sleight_of_hand;
	int stealth;
	int survival;
};