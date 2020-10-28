#include "Logic.h"

int main()
{
	srand((unsigned int)time(NULL));

	Logic logic;
	Inventory inventory;
	Weapon axe{ "Axe", 8 };
	Player player;

	inventory.fAddItem(axe);
	player.fSetWeapon();
		
	while (logic.fGetPlaying())
	{
		logic.fMainMenu();
	}

	return 0;
}