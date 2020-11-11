#include "Armor.h"

Armor::Armor(std::string name, int armor, std::string id)
	: Item(name, id)
{
	std::ifstream armorlist("armorlist.txt");
	if (armorlist.is_open())
	{
		std::string line;
		bool found = false;
		while (!armorlist.eof())
		{
			armorlist >> line;
			if (line == name)
			{
				armorlist >> fGetName()
					>> this->armor;
				found = true;
			}
		}
		if (found == false)
		{
			std::cout << "No such armor has been found." << std::endl;
		}
	}
	else
	{
		std::cout << "Armor file failed to load." << std::endl;
	}
	armorlist.close();
	fSetId(id);
}
