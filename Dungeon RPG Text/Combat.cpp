#include "Combat.h"

void Combat::fTurnOrder(Enemy& enemy, Enemy& enemy2)
{
	
	int result1 = enemy.fRollInitiative();
	int result2 = enemy2.fRollInitiative();

	if (result1 > result2)
	{
		lOrder.emplace_back(enemy);
		lOrder.emplace_back(enemy2);
	}
	else if (result1 < result2)
	{
		lOrder.emplace_back(enemy2);
		lOrder.emplace_back(enemy);
	}
	else
	{
		fTurnOrder(enemy, enemy2);
	}
}

void Combat::fBattle(Player& player, Enemy& enemy)
{

}

void Combat::fBattle(Player& player, Enemy& enemy, Enemy& enemy2)
{
	fTurnOrder(enemy, enemy2);
	player.fRollInitiative();
	while (player.fIsAlive() == true && (enemy.fIsAlive() == true || enemy2.fIsAlive() == true))
	{
		//If first enemy is alive
		if (lOrder.front().fGetAlive() == true)
		{
			if (lOrder.front().fGetInitiative() > player.fGetInitiative())
			{
				//First enemy action
				std::cout << enemy.fGetName() << " is first to act." << std::endl;
				int result = enemy.fAction();
				if (result > 0)
				{
					if (result >= player.fGetAC())
					{
						int damage = enemy.fRollDamage();
						player.fTakeDamage(damage);
						std::cout << player.fGetName() << " has been hit for " << damage << " points." << std::endl;
						std::cout << player.fGetName() << " has left " << player.fGetHealth() << " health points.\n" << std::endl;
						player.fIsAlive();
					}
					else
					{
						std::cout << enemy.fGetName() << " has missed you.\n" << std::endl;
					}
				}

				//If second enemy is alive
				if (lOrder.back().fGetAlive() == true)
				{ 
					if (lOrder.back().fGetInitiative() > player.fGetInitiative())
					{
						//Second enemy action
						std::cout << enemy2.fGetName() << " is second to act." << std::endl;
						int result = enemy2.fAction();
						if (result > 0)
						{
							if (result >= player.fGetAC())
							{
								int damage = enemy2.fRollDamage();
								player.fTakeDamage(damage);
								std::cout << player.fGetName() << " has been hit for " << damage << " points." << std::endl;
								std::cout << player.fGetName() << " has left " << player.fGetHealth() << " health points.\n" << std::endl;
								player.fIsAlive();
							}
							else
							{
								std::cout << enemy2.fGetName() << " has missed you.\n" << std::endl;
							}
						}
						//Player turn
						std::cout << player.fGetName() << " is third to act." << std::endl;
						std::string choice;
						std::cin >> choice;
					}
					else
					{
						//Player Turn
						std::cout << player.fGetName() << " is second to act." << std::endl;
						//Second enemy action
						std::cout << enemy2.fGetName() << " is third to act." << std::endl;
						int result = enemy2.fAction();
						if (result > 0)
						{
							if (result >= player.fGetAC())
							{
								int damage = enemy.fRollDamage();
								player.fTakeDamage(damage);
								std::cout << player.fGetName() << " has been hit for " << damage << " points." << std::endl;
								std::cout << player.fGetName() << " has left " << player.fGetHealth() << " health points.\n" << std::endl;
								player.fIsAlive();
							}
							else
							{
								std::cout << enemy2.fGetName() << " has missed you.\n" << std::endl;
							}
						}
					}
				}
				else //If second enemy is dead
				{
					//Player Turn
					std::cout << player.fGetName() << " is second to act." << std::endl;
					std::string choice;
					std::cin >> choice;
				}
			}
			else if (lOrder.front().fGetInitiative() < player.fGetInitiative())
			{
				//Player action
				std::cout << player.fGetName() << " is first to act." << std::endl;
				std::string choice;
				std::cin >> choice;

				if (enemy.fGetAlive() == true)
				{
					//First enemy action
					std::cout << enemy.fGetName() << " is second to act." << std::endl;
					int result = enemy.fAction();
					if (result > 0)
					{
						if (result >= player.fGetAC())
						{
							int damage = enemy.fRollDamage();
							player.fTakeDamage(damage);
							std::cout << player.fGetName() << " has been hit for " << damage << " points." << std::endl;
							std::cout << player.fGetName() << " has left " << player.fGetHealth() << " health points.\n" << std::endl;
							player.fIsAlive();
						}
						else
						{
							std::cout << enemy.fGetName() << " has missed you.\n" << std::endl;
						}
					}
				}

				if (enemy2.fGetAlive() == true)
				{
					//Second enemy action
					std::cout << enemy2.fGetName() << " is second to act." << std::endl;
					int result = enemy2.fAction();
					if (result > 0)
					{
						if (result >= player.fGetAC())
						{
							int damage = enemy2.fRollDamage();
							player.fTakeDamage(damage);
							std::cout << player.fGetName() << " has been hit for " << damage << " points." << std::endl;
							std::cout << player.fGetName() << " has left " << player.fGetHealth() << " health points.\n" << std::endl;
							player.fIsAlive();
						}
						else
						{
							std::cout << enemy2.fGetName() << " has missed you.\n" << std::endl;
						}
					}
				}
			}
		}
	}
}

/*
			int result = enemy.fAction();
			if (result > 0)
			{
				if (result >= player.fGetAC())
				{
					int damage = enemy.fRollDamage();
					player.fTakeDamage(damage);
					std::cout << player.fGetName() << " has been hit for " << damage << " points." << std::endl;
					std::cout << player.fGetName() << " has left " << player.fGetHealth() << " health points.\n" << std::endl;
				}
				else
				{
					std::cout << enemy.fGetName() << " has missed you.\n" << std::endl;
				}
			}
*/