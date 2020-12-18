#include "Armor.h"

Armor::Armor(std::string name, std::string id)
	: Item(name, id)
{
    fReadFromSQL(name);
}

void Armor::fReadFromSQL(std::string name)
{
    sqlite3* db;
    sqlite3_stmt* stmt = 0;
    std::string sql = "SELECT NAME, ARMOR, DESCRIPTION FROM ARMOR WHERE NAME = ?";

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
        throw std::string("Armor not found");
    }
    this->name = name;
    armor = sqlite3_column_int(stmt, 1);
    char* ptr = (char*)sqlite3_column_text(stmt, 2);
    fSetDescription(ptr);

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}