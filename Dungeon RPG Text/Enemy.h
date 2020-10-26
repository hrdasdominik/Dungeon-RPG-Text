#pragma once
#include "Dice.h"

class Dice;

class Enemy
{
public:

	Enemy();
	virtual ~Enemy();

	//Functions
	bool fIsAlive();
	int fNoNull(int value);
	int fRollInitiative();

	//Accessors

	//Modifiers

private:
	//Class pointers
	Dice* dice;

	//Arrays
	int AttributeMod[20] = { -5, -4, -4, -3, -3, -2, -2, -1, -1, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5 };

	//Basic stats
	bool alive;
	std::string name;
	int health;
	int initiative;

	//Attributes
	int strength;
	int dexterity;
	int constitution;
	int intelligence;
	int wisdom;
	int charisma;

	//Modifiers
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

