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
	health = 10 + mod_constitution;
	mana = 0 + mod_intelligence;
	mana = fNoNull(mana);
	armor_class = 10; // + armor
	initiative = mod_dexterity;
	speed = 2 + mod_dexterity;
	exp = 0;
	level = 1;
	proficiency_bonus = ProficiencyBonus[level - 1];
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

int Player::fNoNull(int value)
{
	value = (value < 0) ? 0 : value;
	return value;
}

void Player::fInsertName()
{
	std::cout << std::endl;
	std::string name;
	std::cout << "Enter your name: ";
	std::cin >> name;
	fInitialize(name);
}

void Player::fPickClass()
{
	std::cout << std::endl;
	std::cout << "== Pick a class ==" << std::endl;
	std::cout << "1. Fighter (Strength)\n"
		<< "2. Ranger (Dexterity)\n"
		<< "3. Sorcerer (Intelligence)\n" << std::endl;
	std::cout << std::endl;
	std::cout << "Enter: ";
	std::cin >> class_name;
	fPickProficiency();
}

void Player::fPickProficiency()
{
	if (class_name == "Fighter" || class_name == "fighter" || class_name == "1")
	{
		std::cout << "You've chosen fighter class.\n"
			<< "Please choose two skills:" << std::endl;
		std::cout << "1. Acrobatics\n"
			<< "2. Animal Handling\n"
			<< "3. Athletics\n"
			<< "4. History\n"
			<< "5. Insight\n"
			<< "6. Intimidation\n"
			<< "7. Perception\n"
			<< "8. Survival\n"
			<< "Choose: ";
		int pro_choice1;
		std::cin >> pro_choice1;
		switch (pro_choice1)
		{
		case 1:
			acrobatics = acrobatics + proficiency_bonus;
			break;
		case 2:
			animal_handling = animal_handling + proficiency_bonus;
			break;
		case 3:
			athletics = athletics + proficiency_bonus;
			break;
		case 4:
			history = history + proficiency_bonus;
			break;
		case 5:
			insight = insight + proficiency_bonus;
			break;
		case 6:
			intimidation = intimidation + proficiency_bonus;
			break;
		case 7:
			perception = perception + proficiency_bonus;
			break;
		case 8:
			survival = survival + proficiency_bonus;
			break;
		default:
			break;
		}
		int pro_choice2;
		std::cin >> pro_choice2;
		switch (pro_choice2)
		{
		case 1:
			acrobatics = acrobatics + proficiency_bonus;
			break;
		case 2:
			animal_handling = animal_handling + proficiency_bonus;
			break;
		case 3:
			athletics = athletics + proficiency_bonus;
			break;
		case 4:
			history = history + proficiency_bonus;
			break;
		case 5:
			insight = insight + proficiency_bonus;
			break;
		case 6:
			intimidation = intimidation + proficiency_bonus;
			break;
		case 7:
			perception = perception + proficiency_bonus;
			break;
		case 8:
			survival = survival + proficiency_bonus;
			break;
		default:
			break;
		}
	}

	else if (class_name == "Ranger" || class_name == "ranger" || class_name == "2")
	{
		std::cout << "You've chosen ranger class.\n"
			<< "Please choose three skills:" << std::endl;
		std::cout << "1. Animal Handling\n"
			<< "2. Athletics\n"
			<< "3. Insight\n"
			<< "4. Investigetion\n"
			<< "5. Nature\n"
			<< "6. Perception\n"
			<< "7. Stealth\n"
			<< "8. Survival\n"
			<< "Choose: ";
		int pro_choice1;
		std::cin >> pro_choice1;
		switch (pro_choice1)
		{
		case 1:
			animal_handling = animal_handling + proficiency_bonus;
			break;
		case 2:
			athletics = athletics + proficiency_bonus;
			break;
		case 3:
			insight = insight + proficiency_bonus;
			break;
		case 4:
			investigation = investigation + proficiency_bonus;
			break;
		case 5:
			nature = nature + proficiency_bonus;
			break;
		case 6:
			perception = perception + proficiency_bonus;
			break;
		case 7:
			stealth = stealth + proficiency_bonus;
			break;
		case 8:
			survival = survival + proficiency_bonus;
			break;
		default:
			break;
		}
		int pro_choice2;
		std::cin >> pro_choice2;
		switch (pro_choice2)
		{
		case 1:
			animal_handling = animal_handling + proficiency_bonus;
			break;
		case 2:
			athletics = athletics + proficiency_bonus;
			break;
		case 3:
			insight = insight + proficiency_bonus;
			break;
		case 4:
			investigation = investigation + proficiency_bonus;
			break;
		case 5:
			nature = nature + proficiency_bonus;
			break;
		case 6:
			perception = perception + proficiency_bonus;
			break;
		case 7:
			stealth = stealth + proficiency_bonus;
			break;
		case 8:
			survival = survival + proficiency_bonus;
			break;
		default:
			break;
		}
		int pro_choice3;
		std::cin >> pro_choice3;
		switch (pro_choice3)
		{
		case 1:
			animal_handling = animal_handling + proficiency_bonus;
			break;
		case 2:
			athletics = athletics + proficiency_bonus;
			break;
		case 3:
			insight = insight + proficiency_bonus;
			break;
		case 4:
			investigation = investigation + proficiency_bonus;
			break;
		case 5:
			nature = nature + proficiency_bonus;
			break;
		case 6:
			perception = perception + proficiency_bonus;
			break;
		case 7:
			stealth = stealth + proficiency_bonus;
			break;
		case 8:
			survival = survival + proficiency_bonus;
			break;
		default:
			break;
		}
	}

	else if (class_name == "Sorcerer" || class_name == "sorcerer" || class_name == "3")
	{
		std::cout << "You've chosen sorcerer class.\n"
			<< "Please choose two skills:" << std::endl;
		std::cout << "1. Arcana\n"
			<< "2. Deception\n"
			<< "3. Insight\n"
			<< "4. Intimidation\n"
			<< "5. Persuasion\n"
			<< "6. Religion\n"
			<< "Choose: ";
		int pro_choice1;
		std::cin >> pro_choice1;
		switch (pro_choice1)
		{
		case 1:
			arcana = arcana + proficiency_bonus;
			break;
		case 2:
			deception = deception + proficiency_bonus;
			break;
		case 3:
			insight = insight + proficiency_bonus;
			break;
		case 4:
			intimidation = intimidation + proficiency_bonus;
			break;
		case 5:
			persuasion = persuasion + proficiency_bonus;
			break;
		case 6:
			religion = religion + proficiency_bonus;
			break;
		default:
			break;
		}
		int pro_choice2;
		std::cin >> pro_choice2;
		switch (pro_choice2)
		{
		case 1:
			arcana = arcana + proficiency_bonus;
			break;
		case 2:
			deception = deception + proficiency_bonus;
			break;
		case 3:
			insight = insight + proficiency_bonus;
			break;
		case 4:
			intimidation = intimidation + proficiency_bonus;
			break;
		case 5:
			persuasion = persuasion + proficiency_bonus;
			break;
		case 6:
			religion = religion + proficiency_bonus;
			break;
		default:
			break;
		}
	}
}