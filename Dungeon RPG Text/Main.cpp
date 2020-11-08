#include "Logic.h"

int main()
{
	srand((unsigned int)time(NULL));

	Logic logic;
	Player player;

	while (logic.fGetPlaying())
	{
		logic.fMainMenu();
	}

	return 0;
}