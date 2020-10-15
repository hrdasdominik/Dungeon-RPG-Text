#include "Logic.h"


Logic::Logic()
{
	choice = 0;
	playing = true;
}

Logic::~Logic()
{

}

void Logic::fInsertName()
{
	std::cout << std::endl;
	std::string name;
	std::cout << "Enter your name: ";
	std::cin >> name;
	player.fInitialize(name);
}

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

void Logic::fPickClass()
{
	std::cout << std::endl;
	std::cout << "== Pick a class ==" << std::endl;
	std::cout << "1. Fighter (Strength)\n" 
			<< "2. Hunter (Dexterity)\n" 
			<< "3. Mage (Intelligence)\n" << std::endl;
	std::cout << std::endl;
	std::cout << "Enter: ";
	std::cin >> choice;

	switch (choice)
	{
	case 1:
		player.fSetClass("Fighter");
		break;
	case 2:
		player.fSetClass("Hunter");
		break;
	case 3:
		player.fSetClass("Mage");
		break;
	default:
		break;
	}
	
}

void Logic::fNewGame()
{
	fInsertName();
	player.fGetStatsAll();
	fPickClass();
}


