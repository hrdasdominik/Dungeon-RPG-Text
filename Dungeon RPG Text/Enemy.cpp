#include "Enemy.h"

Enemy::Enemy()
{
	alive = true;
	name = "Enemy";
	health = 10;
	health = fNoNull(health);
	initiative = 0;

	//Attributes
	strength = 10;
	dexterity = 10;
	constitution = 10;
	intelligence = 10;
	wisdom = 10;
	charisma = 10;

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
}

Enemy::~Enemy()
{

}

bool Enemy::fIsAlive()
{
	if (health <= 0)
		return alive == false;
	else
		return alive == true;
}

int Enemy::fNoNull(int value)
{
	value = (value < 0) ? 0 : value;
	return value;
}

int Enemy::fRollInitiative()
{
	int result = dice->fRoll(20, 1);
	result = result + mod_dexterity;
	return result;
}
