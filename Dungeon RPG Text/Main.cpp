#include "Logic.h"

int main()
{
	srand((unsigned int)time(NULL));

	Logic logic;
	Inventory inventory;
	Item item{ "Axe" };
	Item item2{ "Shield" };
	Item item3{ "Potion" };
	inventory.fAddItem(item);
	inventory.fAddItem(item2);
	inventory.fAddItem(item3);
	inventory.fListItems();
	inventory.fDropItem();
	inventory.fListItems();
		
	while (logic.fGetPlaying())
	{
		logic.fMainMenu();
	}

	return 0;
}