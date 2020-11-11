#include "Logic.h"

Logic::Logic()
{
	choice = 0;
	playing = true;
}

Logic::~Logic()
{

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


void Logic::fNewGame()
{
	player.fInsertName();
	player.fGetStatsAttributes();
	player.fPickClass();
	Enemy enemy("Goblin");
	fBattle(enemy);
}

void Logic::fBattle(Enemy& enemy)
{
	if (player.fRollInitiative() > enemy.fRollInitiative())
	{
		while (player.fGetAlive() == true && enemy.fGetAlive() == true)
		{

			std::cout << "You see " << enemy.fGetName() << ".\n"
				<< "What do you wanna do?" << std::endl;
			std::string choice;
			std::cin >> choice;
			if (choice == "Attack")
			{
				if (player.fRollHit() > enemy.fGetAC())
				{
					enemy.fTakeDamage(player.fRollDamage());
					std::cout << enemy.fGetName() << " has left "
						<< enemy.fGetHealth() << " health." << std::endl;
				}
				else
					std::cout << player.fGetName() << " has missed." << std::endl;
			}
			if (enemy.fRollHit() > player.fGetAC())
			{
				player.fTakeDamage(enemy.fRollDamage());
				std::cout << player.fGetName() << " has left " 
					<< player.fGetHealth() << " health." << std::endl;
			}
			else
				std::cout << enemy.fGetName() << " has missed." << std::endl;
		}
	}
	else if (player.fRollInitiative() < enemy.fRollInitiative())
	{
		while (player.fGetAlive() == true && enemy.fGetAlive() == true)
		{
			if (enemy.fRollHit() > player.fGetAC())
			{
				player.fTakeDamage(enemy.fRollDamage());
				std::cout << player.fGetName() << " has left "
					<< player.fGetHealth() << " health." << std::endl;
			}
			else
				std::cout << enemy.fGetName() << " has missed." << std::endl;

			std::cout << "You see " << enemy.fGetName() << ".\n"
				<< "What do you wanna do?" << std::endl;
			std::string choice;
			std::cin >> choice;
			if (choice == "Attack")
			{
				if (player.fRollHit() > enemy.fGetAC())
				{
					enemy.fTakeDamage(player.fRollDamage());
					std::cout << enemy.fGetHealth() << std::endl;
				}
				else
					std::cout << player.fGetName() << " has missed." << std::endl;
			}
		}
	}
	
}

