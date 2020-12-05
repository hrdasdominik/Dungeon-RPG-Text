#include "Enemy.h"

Enemy::Enemy(std::string name)
{
	fReadFromSQL(name);

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
	initiative = 0;
}

//Functions
int Enemy::fRollInitiative()
{
	return initiative = dice->fRoll(20, 1) + mod_dexterity;
}

bool Enemy::fIsAlive()
{
    if (health <= 0)
    { 
        std::cout << name << " is dead." << std::endl;
        return alive == false;
    }
    else
        return alive == true;
}

int Enemy::fAction()
{
    if (health >= (health / 3))
    {
        return fRollHit();
    }
    else
    {
        int result = rand() % 100 + 1;
        if (result > 13)
        {
            return fRollHit();
        }
        else
        {
            Enemy::~Enemy();
            return 0;
        }
    }
}

//Behind the scene functions
void Enemy::fReadFromSQL(std::string name)
{
    sqlite3* db;
    sqlite3_stmt* stmt = 0;
    std::string sql = "SELECT NAME, HEALTH, ARMOR, LEVEL, EXPDROP, DAMAGE, DAMAGETIME, ADDITIONALDAMAGE, STRENGTH, DEXTERITY, CONSTITUTION, INTELLIGENCE, WISDOM, CHARISMA, BONUSHIT FROM ENEMIES WHERE NAME = ?";

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
    if (rc == SQLITE_DONE)
    {
        sqlite3_finalize(stmt);
        throw std::string("Enemy not found");
    }

    this->name = name;
    this->health = sqlite3_column_int(stmt, 1);
    this->armor = sqlite3_column_int(stmt, 2);
    this->level = sqlite3_column_int(stmt, 3);
    this->exp_drop = sqlite3_column_int(stmt, 4);
    this->damage = sqlite3_column_int(stmt, 5);
    this->damage_time = sqlite3_column_int(stmt, 6);
    this->additional_damage = sqlite3_column_int(stmt, 7);
    this->strength = sqlite3_column_int(stmt, 8);
    this->dexterity = sqlite3_column_int(stmt, 9);
    this->constitution = sqlite3_column_int(stmt, 10);
    this->intelligence = sqlite3_column_int(stmt, 11);
    this->wisdom = sqlite3_column_int(stmt, 12);
    this->charisma = sqlite3_column_int(stmt, 13);
    this->bonus_hit = sqlite3_column_int(stmt, 14);

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

int Enemy::fNoNull(int value)
{
    value = (value < 0) ? 0 : value;
    return value;
}