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
	this->strength = dice->fRoll(6, 3);
	this->dexterity = dice->fRoll(6, 3);
	this->constitution = dice->fRoll(6, 3);
	this->intelligence = dice->fRoll(6, 3);
	this->wisdom = dice->fRoll(6, 3);
	this->charisma = dice->fRoll(6, 3);
	
	//Modifiers
	this->mod_strength = fGetMod(this->strength);
	this->mod_dexterity = fGetMod(this->dexterity);
	this->mod_constitution = fGetMod(this->constitution);
	this->mod_intelligence = fGetMod(this->intelligence);
	this->mod_wisdom = fGetMod(this->wisdom);
	this->mod_charisma = fGetMod(this->charisma);

	//Saving throws
	this->saving_strength = this->mod_strength;
	this->saving_dexterity = this->mod_dexterity;
	this->saving_constitution = this->mod_constitution;
	this->saving_intelligence = this->mod_intelligence;
	this->saving_wisdom = this->mod_wisdom;
	this->saving_charisma = this->mod_charisma;

	//Skills
	this->acrobatics = this->mod_dexterity;
	this->animal_handling = this->mod_wisdom;
	this->arcana = this->mod_intelligence;
	this->athletics = this->mod_strength;
	this->deception = this->mod_charisma;
	this->history = this->mod_intelligence;
	this->insight = this->mod_wisdom;
	this->intimidation = this->mod_charisma;
	this->investigation = this->mod_intelligence;
	this->medicine = this->mod_wisdom;
	this->nature = this->mod_intelligence;
	this->perception = this->mod_wisdom;
	this->performance = this->mod_charisma;
	this->persuasion = this->mod_charisma;
	this->religion = this->mod_intelligence;
	this->sleight_of_hand = this->mod_dexterity;
	this->stealth = this->mod_dexterity;
	this->survival = this->mod_wisdom;

	this->alive = true;
	this->x_pos, y_pos = 0, 0;
	this->name = name;
	this->class_name = "None";
	this->health = 10 + this->mod_constitution;
	this->mana = 0 + this->mod_intelligence;
	this->armor_class = 10 + this->mod_dexterity;
	this->initiative = this->mod_dexterity;
	this->speed = 2 + this->mod_dexterity;
	this->exp = 0;
	this->level = 1;
	this->proficiency_bonus = level % 2;
}

void Player::fGetStatsAttributes() const
{
	std::cout << std::endl;
	std::cout << "== Attributes ==" << std::endl;
	std::cout << "Strength: " << this->strength << " (" << this->mod_strength << ")" << std::endl;
	std::cout << "Dexterity: " << this->dexterity << " (" << this->mod_dexterity << ")" << std::endl;
	std::cout << "Constitution: " << this->constitution << " (" << this->mod_constitution << ")" << std::endl;
	std::cout << "Intelligence: " << this->intelligence << " (" << this->mod_intelligence << ")" << std::endl;
	std::cout << "Wisdom: " << this->wisdom << " (" << this->mod_wisdom << ")" << std::endl;
	std::cout << "Charisma: " << this->charisma << " (" << this->mod_charisma << ")" << std::endl;
	std::cout << std::endl;
}


void Player::fGetStatsAll() const
{
	std::cout << std::endl;
	//std::cout << std::setw(10) << std::setfill('=') << std::endl;
	std::cout << "= Character Sheet =" << std::endl;
	std::cout << "Name: " << this->name << std::endl;
	std::cout << "Class: " << this->class_name << std::endl;
	std::cout << "Level: " << this->level << std::endl;
	std::cout << "Exp: " << this->exp << std::endl;
	std::cout << std::endl;
	std::cout << "== Attributes ==" << std::endl;
	std::cout << "Strength: " << this->strength << " (" << this->mod_strength << ")" << std::endl;
	std::cout << "Dexterity: " << this->dexterity << " (" << this->mod_dexterity << ")" << std::endl;
	std::cout << "Constitution: " << this->constitution << " (" << this->mod_constitution << ")" << std::endl;
	std::cout << "Intelligence: " << this->intelligence << " (" << this->mod_intelligence << ")" << std::endl;
	std::cout << "Wisdom: " << this->wisdom << " (" << this->mod_wisdom << ")" << std::endl;
	std::cout << "Charisma: " << this->charisma << " (" << this->mod_charisma << ")" << std::endl;
	std::cout << std::endl;
	std::cout << "== Saving throws ==" << std::endl;
	std::cout << "Strength: " << this->saving_strength << std::endl;
	std::cout << "Dexterity: " << this->saving_dexterity << std::endl;
	std::cout << "Constitution: " << this->saving_constitution << std::endl;
	std::cout << "Intelligence: " << this->saving_intelligence << std::endl;
	std::cout << "Wisdom: " << this->saving_wisdom << std::endl;
	std::cout << "Charisma: " << this->saving_charisma << std::endl;
	std::cout << std::endl;
	std::cout << "== Skills ==" << std::endl;
	std::cout << "Acrobatics: " << this->acrobatics << std::endl;
	std::cout << "Animal handling: " << this->animal_handling << std::endl;
	std::cout << "Arcana: " << this->arcana << std::endl;
	std::cout << "Athletics: " << this->athletics << std::endl;
	std::cout << "Deception: " << this->deception << std::endl;
	std::cout << "History: " << this->history << std::endl;
	std::cout << "Insight: " << this->insight << std::endl;
	std::cout << "Intimidation: " << this->intimidation << std::endl;
	std::cout << "Investigation: " << this->investigation << std::endl;
	std::cout << "Medicine: " << this->medicine << std::endl;
	std::cout << "Nature: " << this->nature << std::endl;
	std::cout << "Perception: " << this->perception << std::endl;
	std::cout << "Performance: " << this->performance << std::endl;
	std::cout << "Persuasion: " << this->persuasion << std::endl;
	std::cout << "Religion: " << this->religion << std::endl;
	std::cout << "Sleight of hand: " << this->sleight_of_hand << std::endl;
	std::cout << "Stealth: " << this->stealth << std::endl;
	std::cout << "Survival: " << this->survival << std::endl;
	std::cout << std::endl;
}



int Player::fGetMod(int attribute)
{
	return AttributeMod[attribute];
}