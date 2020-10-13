#include "Logic.h"

int main()
{
	srand(time(NULL));

	Logic logic;
		
	while (logic.fGetPlaying())
	{
		logic.fMainMenu();
	}

	return 0;
}