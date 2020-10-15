#include "Player.h"
#include "Dice.h"


Player::Player()
{
	fInitialize("Player");
}

Player::~Player()
{

}

void Player::fInitialize(std::string name)
{
	//Attributes
	strength = dice->fRoll(6, 3);
	dexterity = dice->fRoll(6, 3);
	constitution = dice->fRoll(6, 3);
	intelligence = dice->fRoll(6, 3);
	wisdom = dice->fRoll(6, 3);
	charisma = dice->fRoll(6, 3);
	
	//Modifiers
	mod_strength = fGetMod(strength - 1);
	mod_dexterity = fGetMod(dexterity - 1);
	mod_constitution = fGetMod(constitution - 1);
	mod_intelligence = fGetMod(intelligence - 1);
	mod_wisdom = fGetMod(wisdom - 1);
	mod_charisma = fGetMod(charisma - 1);

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
	x_pos, y_pos = 0, 0;
	this->name = name;
	class_name = "None";
	health = 10 + mod_constitution;
	mana = 0 + mod_intelligence;
	armor_class = 10 + mod_dexterity;
	initiative = mod_dexterity;
	speed = 2 + mod_dexterity;
	exp = 0;
	level = 1;
	proficiency_bonus = level % 2;
}

int Player::fGetMod(int attribute)
{
	return AttributeMod[attribute];
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
	//std::cout << std::setw(10) << std::setfill('=') << std::endl;
	std::cout << "= Character Sheet =" << std::endl;
	std::cout << "Name: " << name << std::endl;
	std::cout << "Class: " << class_name << std::endl;
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

void Player::fLevelUp()
{
	static const int required_experience[] =
	{
	  45, 95, 145, 210, 285, 380, 495, 610, 745, 99999999
	};

	while (exp >= required_experience[level])
		++level;
}
