#include "Weapon.h"

Weapon::Weapon(std::string name, int damage)
{
	fSetName(name);
	fSetDamage(damage);
}

Weapon::~Weapon()
{

}