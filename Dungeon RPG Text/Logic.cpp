#include "Logic.h"

Logic::Logic()
{
	choice = 0;
	playing = true;
}

Logic::~Logic()
{

}

//Functions
void Logic::fMainMenu()
{
	std::cout << "MAIN MENU" << std::endl;
	std::cout << "1. New game" << std::endl;
	std::cout << "2. Quit game" << std::endl;
	std::cout << std::endl;
	std::cout << "Choice: ";
	std::cin >> choice;

	switch (choice)
	{
	case 1:
		fNewGame();
		break;
	case 2:
		playing = false;
		break;
	default:
		break;
	}
}


void Logic::fNewGame()
{
	player.fPlayerCreation();
	Enemy enemy("Goblin");
	Enemy enemy2("Goblin");
	combat.fBattle(player, enemy, enemy2);
}

bool Logic::fGameRunning()
{
	if (player.fGetAlive() == false)
	{
		return false;
	}
	else
		return true;
}