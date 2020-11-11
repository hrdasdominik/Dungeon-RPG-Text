#pragma once
#include "Dice.h"
class Enemy
{
public:
	Enemy(std::string name);
	virtual ~Enemy() {};

	//Accessors
	inline const bool& fGetAlive() const { return alive; }
	inline const std::string& fGetName() const { return name; }
	inline const int& fGetHealth() const { return health; }
	inline const int& fGetAC() const { return armor_class; }
	inline const int& fGetInitiative() const { return initiative; }
	inline const int& fGetLevel() const { return level; }
	inline const int& fGetExpDrop() const { return exp_drop; }

	//Modifiers


	//Functions
	int fRollInitiative();
	inline void fTakeDamage(int damage) { health -= damage; }
	inline int fRollHit() const { return dice->fRoll(20, 1) + bonus_hit; }
	inline int fRollDamage() const { return dice->fRoll(damage, damage_time) + additional_damage; }

private:
	//Behind the scene functions
	void fLoadList(std::string name);

	//Objects
	Dice* dice;

	//Array
	int AttributeMod[20] = { -5, -4, -4, -3, -3, -2, -2, -1, -1, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5 };

	//Basic stats
	bool alive;
	std::string name;
	int health;
	int armor_class;
	int initiative;
	int level;
	int exp_drop;
	int damage;
	int damage_time;
	int additional_damage;
	int bonus_hit;

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
};

