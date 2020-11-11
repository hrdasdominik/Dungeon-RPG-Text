#include "Enemy.h"

Enemy::Enemy(std::string name)
{
	fLoadList(name);

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
	alive = true;
	initiative = mod_dexterity;
}

//FUnctions
int Enemy::fRollInitiative()
{
	return dice->fRoll(20, 1) + mod_dexterity;
}

//Behind the scene functions
void Enemy::fLoadList(std::string name)
{
	std::ifstream enemylist ("enemylist.txt");

	if(enemylist.is_open())
	{ 
		bool found = false;
		std::string line;
		while(!enemylist.eof())
		{ 
			enemylist >> line;
			if (line == name)
			{
				enemylist >> this->name
					>> health
					>> armor_class
					>> level
					>> exp_drop
					>> damage
					>> damage_time
					>> additional_damage
					>> strength
					>> dexterity
					>> constitution
					>> intelligence
					>> wisdom
					>> charisma
					>> bonus_hit;
				found = true;
			}
		}
		if (found == false)
			std::cout << "Failed to load enemy." << std::endl;
	}
	else
	{
		std::cout << "File failed to load." << std::endl;
	}
	enemylist.close();
}
