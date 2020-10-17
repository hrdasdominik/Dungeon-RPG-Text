#include "Logic.h"

int main()
{
	srand((unsigned int)time(NULL));

	Logic logic;
		
	while (logic.fGetPlaying())
	{
		logic.fMainMenu();
	}

	return 0;
}