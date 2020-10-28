#include "Player.h"

Player::Player()
{
	fInitialize("Player");
}

Player::~Player()
{

}

bool Player::fIsAlive()
{
	if (health <= 0)
		return alive == false;
	else
		return alive == true;
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
	health = health + mod_constitution;
	health = fNoNull(health);
	armor_class = 10; // + armor
	initiative = mod_dexterity;
	exp = 0;
	level = 1;
	proficiency_bonus = ProficiencyBonus[level - 1];
	damage = 0;
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
	std::cout << "Health: " << health << std::endl;
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

int Player::fNoNull(int value)
{
	value = (value < 0) ? 0 : value;
	return value;
}

int Player::fSetWeapon()
{
	int choice;
	std::cout << "Pick a weapon from your inventory:\n"
		<< std::endl;
	inventory->fListItems();
	std::cout << "Choose: ";
	std::cin >> choice;
	return damage = bag[choice].fGetDamage();
}

void Player::fInsertName()
{
	std::cout << std::endl;
	std::string name;
	std::cout << "Enter your name: ";
	std::cin >> name;
	fInitialize(name);
}

void Player::fGiveExp()
{
	exp = exp + 45;
}

void Player::fPickClass()
{
	std::cout << "== Pick a class ==" << std::endl;
	std::cout << "1. Fighter (Strength)\n"
		<< "2. Ranger (Dexterity)\n"
		<< "3. Sorcerer (Charisma)\n" << std::endl;
	std::cout << "Enter: ";
	std::cin >> class_name;
	std::cout << std::endl;
	fClassCreation();
}

void Player::fClassCreation()
{
	if (class_name == "Fighter" || class_name == "fighter" || class_name == "1")
	{
		class_name = "Fighter";
		health = 10 + mod_constitution;
		saving_strength = saving_strength + proficiency_bonus;
		saving_constitution = saving_constitution + proficiency_bonus;
		std::cout << "You've chosen fighter class.\n"
			<< "Your health is set to: " << health << std::endl << std::endl;
		std::cout <<"Please choose two skills:" << std::endl;
		std::cout << "1. Acrobatics (Dexterity)\n"
			<< "2. Animal Handling (Wisdom)\n"
			<< "3. Athletics (Strenght)\n"
			<< "4. History (Intelligence)\n"
			<< "5. Insight (Wisdom)\n"
			<< "6. Intimidation (Charisma)\n"
			<< "7. Perception (Wisdom)\n"
			<< "8. Survival (Wisdom)\n"
			<< "Choose the first one: ";
		int pro_choice1;
		std::cin >> pro_choice1;
		switch (pro_choice1)
		{
		case 1:
			std::cout << "Acrobatics before: " << acrobatics << std::endl;
			acrobatics = acrobatics + proficiency_bonus;
			std::cout << "Acrobatics now: " << acrobatics << std::endl << std::endl;
			break;
		case 2:
			std::cout << "Animal Handling before: " << animal_handling << std::endl;
			animal_handling = animal_handling + proficiency_bonus;
			std::cout << "Animal Handling now: " << animal_handling << std::endl << std::endl;
			break;
		case 3:
			std::cout << "Athletics before: " << athletics << std::endl;
			athletics = athletics + proficiency_bonus;
			std::cout << "Athletics now: " << athletics << std::endl << std::endl;
			break;
		case 4:
			std::cout << "History before: " << history << std::endl;
			history = history + proficiency_bonus;
			std::cout << "History now: " << history << std::endl << std::endl;
			break;
		case 5:
			std::cout << "Insight before: " << insight << std::endl;
			insight = insight + proficiency_bonus;
			std::cout << "Insight now: " << insight << std::endl << std::endl;
			break;
		case 6:
			std::cout << "Intimidation before: " << intimidation << std::endl;
			intimidation = intimidation + proficiency_bonus;
			std::cout << "Intimidation now: " << intimidation << std::endl << std::endl;
			break;
		case 7:
			std::cout << "Perception before: " << perception << std::endl;
			perception = perception + proficiency_bonus;
			std::cout << "Perception now: " << perception << std::endl << std::endl;
			break;
		case 8:
			std::cout << "Survival before: " << survival << std::endl;
			survival = survival + proficiency_bonus;
			std::cout << "Survival now: " << survival << std::endl << std::endl;
			break;
		default:
			break;
		}
		std::cout << "Choose the second one: ";
		int pro_choice2;
		std::cin >> pro_choice2;
		switch (pro_choice2)
		{
		case 1:
			std::cout << "Acrobatics before: " << acrobatics << std::endl;
			acrobatics = acrobatics + proficiency_bonus;
			std::cout << "Acrobatics now: " << acrobatics << std::endl << std::endl;
			break;
		case 2:
			std::cout << "Animal Handling before: " << animal_handling << std::endl;
			animal_handling = animal_handling + proficiency_bonus;
			std::cout << "Animal Handling now: " << animal_handling << std::endl << std::endl;
			break;
		case 3:
			std::cout << "Athletics before: " << athletics << std::endl;
			athletics = athletics + proficiency_bonus;
			std::cout << "Athletics now: " << athletics << std::endl << std::endl;
			break;
		case 4:
			std::cout << "History before: " << history << std::endl;
			history = history + proficiency_bonus;
			std::cout << "History now: " << history << std::endl << std::endl;
			break;
		case 5:
			std::cout << "Insight before: " << insight << std::endl;
			insight = insight + proficiency_bonus;
			std::cout << "Insight now: " << insight << std::endl << std::endl;
			break;
		case 6:
			std::cout << "Intimidation before: " << intimidation << std::endl;
			intimidation = intimidation + proficiency_bonus;
			std::cout << "Intimidation now: " << intimidation << std::endl << std::endl;
			break;
		case 7:
			std::cout << "Perception before: " << perception << std::endl;
			perception = perception + proficiency_bonus;
			std::cout << "Perception now: " << perception << std::endl << std::endl;
			break;
		case 8:
			std::cout << "Survival before: " << survival << std::endl;
			survival = survival + proficiency_bonus;
			std::cout << "Survival now: " << survival << std::endl << std::endl;
			break;
		default:
			break;
		}
	}

	else if (class_name == "Ranger" || class_name == "ranger" || class_name == "2")
	{
	class_name = "Ranger";
	health = 10 + mod_constitution;
	saving_strength = saving_strength + proficiency_bonus;
	saving_dexterity = saving_dexterity + proficiency_bonus;
	std::cout << "You've chosen ranger class.\n"
		<< "Your health is set to: " << health << std::endl << std::endl;
	std::cout << "Please choose three skills:" << std::endl;
		std::cout << "1. Animal Handling (Wisdom)\n"
			<< "2. Athletics (Strenght)\n"
			<< "3. Insight (Wisdom)\n"
			<< "4. Investigetion (Intelligence)\n"
			<< "5. Nature (Intelligence)\n"
			<< "6. Perception (Wisdom)\n"
			<< "7. Stealth (Dexterity)\n"
			<< "8. Survival (Wisdom)\n"
			<< "Choose the first one: ";
		int pro_choice1;
		std::cin >> pro_choice1;
		switch (pro_choice1)
		{
		case 1:
			std::cout << "Animal Handling before: " << animal_handling << std::endl;
			animal_handling = animal_handling + proficiency_bonus;
			std::cout << "Animal Handling now: " << animal_handling << std::endl << std::endl;
			break;
		case 2:
			std::cout << "Athletics before: " << athletics << std::endl;
			athletics = athletics + proficiency_bonus;
			std::cout << "Athletics now: " << athletics << std::endl << std::endl;
			break;
		case 3:
			std::cout << "Insight before: " << insight << std::endl;
			insight = insight + proficiency_bonus;
			std::cout << "Insight now: " << insight << std::endl << std::endl;
			break;
		case 4:
			std::cout << "Investigetion before: " << investigation << std::endl;
			investigation = investigation + proficiency_bonus;
			std::cout << "Investigetion now: " << investigation << std::endl << std::endl;
			break;
		case 5:
			std::cout << "Nature before: " << nature << std::endl;
			nature = nature + proficiency_bonus;
			std::cout << "Nature now: " << nature << std::endl << std::endl;
			break;
		case 6:
			std::cout << "Perception before: " << perception << std::endl;
			perception = perception + proficiency_bonus;
			std::cout << "Perception now: " << perception << std::endl << std::endl;
			break;
		case 7:
			std::cout << "Stealth before: " << stealth << std::endl;
			stealth = stealth + proficiency_bonus;
			std::cout << "Stealth now: " << stealth << std::endl << std::endl;
			break;
		case 8:
			std::cout << "Survival before: " << survival << std::endl;
			survival = survival + proficiency_bonus;
			std::cout << "Survival now: " << survival << std::endl << std::endl;
			break;
		default:
			break;
		}
		std::cout << "Choose the second one: ";
		int pro_choice2;
		std::cin >> pro_choice2;
		switch (pro_choice2)
		{
		case 1:
			std::cout << "Animal Handling before: " << animal_handling << std::endl;
			animal_handling = animal_handling + proficiency_bonus;
			std::cout << "Animal Handling now: " << animal_handling << std::endl << std::endl;
			break;
		case 2:
			std::cout << "Athletics before: " << athletics << std::endl;
			athletics = athletics + proficiency_bonus;
			std::cout << "Athletics now: " << athletics << std::endl << std::endl;
			break;
		case 3:
			std::cout << "Insight before: " << insight << std::endl;
			insight = insight + proficiency_bonus;
			std::cout << "Insight now: " << insight << std::endl << std::endl;
			break;
		case 4:
			std::cout << "Investigetion before: " << investigation << std::endl;
			investigation = investigation + proficiency_bonus;
			std::cout << "Investigetion now: " << investigation << std::endl << std::endl;
			break;
		case 5:
			std::cout << "Nature before: " << nature << std::endl;
			nature = nature + proficiency_bonus;
			std::cout << "Nature now: " << nature << std::endl << std::endl;
			break;
		case 6:
			std::cout << "Perception before: " << perception << std::endl;
			perception = perception + proficiency_bonus;
			std::cout << "Perception now: " << perception << std::endl << std::endl;
			break;
		case 7:
			std::cout << "Stealth before: " << stealth << std::endl;
			stealth = stealth + proficiency_bonus;
			std::cout << "Stealth now: " << stealth << std::endl << std::endl;
			break;
		case 8:
			std::cout << "Survival before: " << survival << std::endl;
			survival = survival + proficiency_bonus;
			std::cout << "Survival now: " << survival << std::endl << std::endl;
			break;
		default:
			break;
		}
		std::cout << "Choose the third one: ";
		int pro_choice3;
		std::cin >> pro_choice3;
		switch (pro_choice3)
		{
		case 1:
			std::cout << "Animal Handling before: " << animal_handling << std::endl;
			animal_handling = animal_handling + proficiency_bonus;
			std::cout << "Animal Handling now: " << animal_handling << std::endl << std::endl;
			break;
		case 2:
			std::cout << "Athletics before: " << athletics << std::endl;
			athletics = athletics + proficiency_bonus;
			std::cout << "Athletics now: " << athletics << std::endl << std::endl;
			break;
		case 3:
			std::cout << "Insight before: " << insight << std::endl;
			insight = insight + proficiency_bonus;
			std::cout << "Insight now: " << insight << std::endl << std::endl;
			break;
		case 4:
			std::cout << "Investigetion before: " << investigation << std::endl;
			investigation = investigation + proficiency_bonus;
			std::cout << "Investigetion now: " << investigation << std::endl << std::endl;
			break;
		case 5:
			std::cout << "Nature before: " << nature << std::endl;
			nature = nature + proficiency_bonus;
			std::cout << "Nature now: " << nature << std::endl << std::endl;
			break;
		case 6:
			std::cout << "Perception before: " << perception << std::endl;
			perception = perception + proficiency_bonus;
			std::cout << "Perception now: " << perception << std::endl << std::endl;
			break;
		case 7:
			std::cout << "Stealth before: " << stealth << std::endl;
			stealth = stealth + proficiency_bonus;
			std::cout << "Stealth now: " << stealth << std::endl << std::endl;
			break;
		case 8:
			std::cout << "Survival before: " << survival << std::endl;
			survival = survival + proficiency_bonus;
			std::cout << "Survival now: " << survival << std::endl << std::endl;
			break;
		default:
			break;
		}
	}

	else if (class_name == "Sorcerer" || class_name == "sorcerer" || class_name == "3")
	{
	class_name = "Sorcerer";
	health = 6 + mod_constitution;
	saving_constitution = saving_constitution + proficiency_bonus;
	saving_charisma = saving_charisma + proficiency_bonus;
	std::cout << "You've chosen sorcerer class.\n"
		<< "Your health is set to: " << health << std::endl << std::endl;
	std::cout << "Please choose two skills:" << std::endl;
		std::cout << "1. Arcana (Intelligence)\n"
			<< "2. Deception (Charisma)\n"
			<< "3. Insight (Wisdom)\n"
			<< "4. Intimidation (Charisma)\n"
			<< "5. Persuasion (Charisma)\n"
			<< "6. Religion (Intelligence)\n"
			<< "Choose the first one: ";
		int pro_choice1;
		std::cin >> pro_choice1;
		switch (pro_choice1)
		{
		case 1:
			std::cout << "Arcana before: " << arcana << std::endl;
			arcana = arcana + proficiency_bonus;
			std::cout << "Arcana now: " << arcana << std::endl << std::endl;
			break;
		case 2:
			std::cout << "Deception before: " << deception << std::endl;
			deception = deception + proficiency_bonus;
			std::cout << "Deception now: " << deception << std::endl << std::endl;
			break;
		case 3:
			std::cout << "Insight before: " << insight << std::endl;
			insight = insight + proficiency_bonus;
			std::cout << "Insight now: " << insight << std::endl << std::endl;
			break;
		case 4:
			std::cout << "Intimidation before: " << intimidation << std::endl;
			intimidation = intimidation + proficiency_bonus;
			std::cout << "Intimidation now: " << intimidation << std::endl << std::endl;
			break;
		case 5:
			std::cout << "Persuasion before: " << persuasion << std::endl;
			persuasion = persuasion + proficiency_bonus;
			std::cout << "Pesuasion now: " << persuasion << std::endl << std::endl;
			break;
		case 6:
			std::cout << "Religion before: " << religion << std::endl;
			religion = religion + proficiency_bonus;
			std::cout << "Religion now: " << religion << std::endl << std::endl;
			break;
		default:
			break;
		}
		std::cout << "Choose the second one: ";
		int pro_choice2;
		std::cin >> pro_choice2;
		switch (pro_choice2)
		{
		case 1:
			std::cout << "Arcana before: " << arcana << std::endl;
			arcana = arcana + proficiency_bonus;
			std::cout << "Arcana now: " << arcana << std::endl << std::endl;
			break;
		case 2:
			std::cout << "Deception before: " << deception << std::endl;
			deception = deception + proficiency_bonus;
			std::cout << "Deception now: " << deception << std::endl << std::endl;
			break;
		case 3:
			std::cout << "Insight before: " << insight << std::endl;
			insight = insight + proficiency_bonus;
			std::cout << "Insight now: " << insight << std::endl << std::endl;
			break;
		case 4:
			std::cout << "Intimidation before: " << intimidation << std::endl;
			intimidation = intimidation + proficiency_bonus;
			std::cout << "Intimidation now: " << intimidation << std::endl << std::endl;
			break;
		case 5:
			std::cout << "Persuasion before: " << persuasion << std::endl;
			persuasion = persuasion + proficiency_bonus;
			std::cout << "Pesuasion now: " << persuasion << std::endl << std::endl;
			break;
		case 6:
			std::cout << "Religion before: " << religion << std::endl;
			religion = religion + proficiency_bonus;
			std::cout << "Religion now: " << religion << std::endl << std::endl;
			break;
		default:
			break;
		}
	}
	
	else 
	{
		std::cout << "Error. Please select one of the given classes" << std::endl;
		fPickClass();
	}
}