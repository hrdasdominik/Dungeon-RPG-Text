#include "Weapon.h"

Weapon::Weapon(std::string name, int damage)
{
	fSetName(name);
	this->damage = damage;
}

Weapon::~Weapon()
{

}