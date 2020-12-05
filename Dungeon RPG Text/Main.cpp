#include "Logic.h"

int main()
{
	srand((unsigned int)time(NULL));

	Logic logic;

	while (logic.fGameRunning() == true)
	{
		logic.fMainMenu();
	}

	return 0;
}