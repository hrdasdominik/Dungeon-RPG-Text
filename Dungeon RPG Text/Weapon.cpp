#include "Weapon.h"

Weapon::Weapon(std::string name, int damage, int times, std::string id)
	: Item(name, id)
{
	std::ifstream weaponlist("weaponlist.txt");
	if (weaponlist.is_open())
	{
		std::string line;
		bool found = false;
		while (!weaponlist.eof())
		{
			weaponlist >> line;
			if (line == name)
			{
				weaponlist >> fGetName()
					>> this->damage
					>> this->times;
				found = true;
			}
		}
		if (found == false)
		{
			std::cout << "No such weapon has been found." << std::endl;
		}
	}
	else
	{
		std::cout << "Weapon file failed to load." << std::endl;
	}
	weaponlist.close();
	fSetId(id);
}