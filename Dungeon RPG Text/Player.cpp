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

int Player::fAction()
{
	int choice;
	std::cout << "1. Attack\n"
			  << "2. Skill\n"
			  << "3. Inventory\n"
			  << "4. Run away\n"
			  << "Choose: ";
	std::cin >> choice;
	switch (choice)
	{
	case 1:
		return fRollHit();
		break;
	case 2:
		return 0;
		break;
	case 3:
		return 0;
		break;
	case 4:
		return 0;
		break;
	}
	return 0;
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
void Player::fPlayerCreation()
{
	std::cout << std::endl;
	std::string name;
	std::cout << "Enter your name: ";
	std::cin >> name;
	fInitialize(name);
	fGetStatsAttributes();
	fPickClass();
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
	{ 
		std::cout << name << " is dead." << std::endl;
		return alive == false;
	}
	else
		return alive == true;
}

void Player::fPickClass()
{
	std::cout << "== Pick a class ==" << std::endl;
	std::cout << "Fighter (Strength, Constitution)\n";
	std::cout << "Ranger (Strength, Dexterity)\n";
	std::cout << "== Write the name of the class as written ==" << std::endl;
	std::cout << "Enter: ";
	std::string choice;
	std::cin >> choice;
	std::cout << std::endl;
	fReadFromSQL(choice);
}

//Behind the scene functions
void Player::fReadFromSQL(std::string name)
{
	
		sqlite3* db;
		sqlite3_stmt* stmt = 0;
		std::string sql = "SELECT NAME, HEALTH, ARMOR, WEAPON FROM CLASS WHERE NAME = ?";

		int rc = sqlite3_open("database.db", &db);
		if (rc != SQLITE_OK)
			std::cout << "Error opening database." << std::endl;

		rc = sqlite3_prepare_v2(db, sql.c_str(), sql.length(), &stmt, nullptr);

		rc = sqlite3_bind_text(stmt, 1, name.c_str(), name.length(), SQLITE_STATIC);
		
		if (rc != SQLITE_OK)
		{
			std::string errmsg(sqlite3_errmsg(db));
			sqlite3_finalize(stmt);
			throw errmsg;
		}

		rc = sqlite3_step(stmt);

		if (rc != SQLITE_ROW && rc != SQLITE_DONE)
		{
			std::string errmsg(sqlite3_errmsg(db));
			sqlite3_finalize(stmt);
			throw errmsg;
		}
		
		try
		{
			if (rc == SQLITE_DONE)
			{
				sqlite3_finalize(stmt);
				throw std::string("Class not found");
			}
		}

		catch (...)
		{
			std::cout << "Error. Please write the name of the class from the list below." << std::endl;
			fPickClass();
		}
		class_name = name;
		this->health = sqlite3_column_int(stmt, 1);
		this->armor_name = (char*)sqlite3_column_text(stmt, 2);
		this->weapon_name = (char*)sqlite3_column_text(stmt, 3);

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
		sqlite3_finalize(stmt);
		sqlite3_close(db);

		fChooseProfSkill(class_name);
}

static int callback(void* NotUsed, int argc, char** argv, char** azColName) {
	int i;
	for (i = 0; i < argc; i++) {
		std::cout << i << " " << argv[i] << std::endl;
	}
	return 0;
}

/*void Player::fChooseProfSkill(std::string name)
{
	sqlite3* db;
	char* zErrMsg = 0;
	char* sql;

	if (name == "Fighter")
		sql = (char*)"SELECT NAME FROM SKILLS WHERE FIGHTER = 1";
	else if (name == "Ranger")
		sql = (char*)"SELECT NAME FROM SKILLS WHERE RANGER = 1";
	else
		sql = nullptr;

	int rc = sqlite3_open("database.db", &db);
	if (rc != SQLITE_OK)
		std::cout << "Error opening database." << std::endl;

	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Operation done successfully\n");
	}

	sqlite3_close(db);
}*/

//skill tree treba rijesit kroz baze nekak
void Player::fChooseProfSkill(std::string name)
{
	if (name == "Fighter")
	{ 
		std::vector<std::string> string_skills = { "Acrobatics", "Animal handling", "Athletics", "History", "Insight", "Intimidation", "Perception", "Survival" };
		std::vector<int*> int_skills = { &acrobatics, &animal_handling, &athletics, &history, &insight, &intimidation, &perception, &survival };
		
		mod_strength += proficiency_bonus;
		mod_constitution += proficiency_bonus;

		int choice = 0;
		std::cout << "Choose two skills: \n" << std::endl;

		for (size_t i = 0; i < string_skills.size(); i++)
		{
			std::cout << i << " - " << string_skills[i] << std::endl;
		}
		
		std::cin >> choice;
		*int_skills[choice] += proficiency_bonus;
		
		std::cout << string_skills[choice] << " is now " << *int_skills[choice] << ".\n" << std::endl;

		string_skills.erase(string_skills.begin() + choice);
		*int_skills.erase(int_skills.begin() + choice);

		for (size_t i = 0; i < string_skills.size(); i++)
		{
			std::cout << i << " - " << string_skills[i] << std::endl;
		}

		std::cin >> choice;

		*int_skills[choice] += proficiency_bonus;
		std::cout << string_skills[choice] << " is now " << *int_skills[choice] << ".\n" << std::endl;
	}
}

int Player::fNoNull(int value)
{
	value = (value < 0) ? 0 : value;
	return value;
}