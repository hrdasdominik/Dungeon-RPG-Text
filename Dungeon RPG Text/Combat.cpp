#include "Combat.h"

void Combat::fTurnRoll(Player& player, Enemy& enemy)
{
	int presult = player.fRollInitiative();
	std::cout << player.fGetName() << " has rolled " << presult << "." << std::endl;
	int result1 = enemy.fRollInitiative();
	std::cout << enemy.fGetName() << " has rolled " << result1 << "." << std::endl;
}

void Combat::fTurnRoll(Player& player, Enemy& enemy, Enemy& enemy2)
{
	int presult = player.fRollInitiative();
	std::cout << player.fGetName() << " has rolled " << presult << "." << std::endl;
	int result1 = enemy.fRollInitiative();
	std::cout << enemy.fGetName() << " has rolled " << result1 << "." << std::endl;
	int result2 = enemy2.fRollInitiative();
	std::cout << enemy2.fGetName() << " has rolled " << result2 << "." << std::endl;

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
		lOrder.emplace_back(enemy);
		lOrder.emplace_back(enemy2);
	}
}

void Combat::fBattle(Player& player, Enemy& enemy)
{
	fTurnRoll(player, enemy);
	while (player.fIsAlive() == true && enemy.fIsAlive() == true)
	{
		std::cout << "\nTurn: " << turn << ".\n" << std::endl;

		if (player.fGetInitiative() >= enemy.fGetInitiative())
		{
			fPlayerAction(player, enemy);
			if (enemy.fGetHealth() <= 0)
				break;
			fEnemyAction(enemy, player);
			if (player.fGetHealth() <= 0)
				break;
			turn++;
		}
		else
		{
			fEnemyAction(enemy, player);
			if (player.fGetHealth() <= 0)
				break;
			fPlayerAction(player, enemy);
			if (enemy.fGetHealth() <= 0)
				break;
			turn++;
		}
	}
}

void Combat::fBattle(Player& player, Enemy& enemy, Enemy& enemy2)
{
	fTurnRoll(player, enemy, enemy2);
	while (player.fIsAlive() == true && (enemy.fIsAlive() == true || enemy2.fIsAlive() == true))
	{
		std::cout << "\nTurn: " << turn << ".\n" << std::endl;

		if (player.fGetInitiative() >= lOrder.front().fGetInitiative())
		{
			fPlayerAction(player, enemy, enemy2);
			if (enemy.fGetHealth() <= 0 && enemy2.fGetHealth() <= 0)
				break;
			fEnemyAction(enemy, player);
			if (player.fGetHealth() <= 0)
				break;
			fEnemyAction(enemy2, player);
			if (player.fGetHealth() <= 0)
				break;
			turn++;
		}
		else if (lOrder.front().fGetInitiative() > player.fGetInitiative() && player.fGetInitiative() >= lOrder.back().fGetInitiative())
		{
			fEnemyAction(enemy, player);
			if (player.fGetHealth() <= 0)
				break;
			fPlayerAction(player, enemy, enemy2);
			if (enemy.fGetHealth() <= 0 && enemy2.fGetHealth() <= 0)
				break;
			fEnemyAction(enemy2, player);
			if (player.fGetHealth() <= 0)
				break;
			turn++;
		}
		else
		{
			fEnemyAction(enemy, player);
			if (player.fGetHealth() <= 0)
				break;
			fEnemyAction(enemy2, player);
			if (player.fGetHealth() <= 0)
				break;
			fPlayerAction(player, enemy, enemy2);
			if (enemy.fGetHealth() <= 0 && enemy2.fGetHealth() <= 0)
				break;
			turn++;
		}
	}
}

void Combat::fEnemyAction(Enemy& enemy, Player& player)
{
	if (enemy.fGetAlive() == true)
	{
		if(enemy.fAction() > 0)
		{ 
			if (enemy.fAction() >= player.fGetAC())
			{
				std::cout << enemy.fGetName()
						<< " successfully hit "
						<< player.fGetName()
						<< "." << std::endl;

				int damage = enemy.fRollDamage();
				player.fTakeDamage(damage);
			
				std::cout << player.fGetName()
						<< " was hit for "
						<< damage
						<< " points of damage." << std::endl;
				std::cout << player.fGetName()
						<< " has left "
						<< player.fGetHealth()
						<< " health points.\n" << std::endl;
			}
			else
			{
				std::cout << enemy.fGetName() << " has missed " << player.fGetName() << " .\n" << std::endl;
			}
		}
		else
		{
			std::cout << enemy.fGetName() << " has run away." << std::endl;
		}
		
	}
}

void Combat::fPlayerAction(Player& player, Enemy& enemy)
{
	if (player.fIsAlive() == true)
	{
		std::cout << player.fGetName() << " turn." << std::endl;
	}
}

void Combat::fPlayerAction(Player& player, Enemy& enemy, Enemy& enemy2)
{
	if (player.fIsAlive() == true)
	{
		std::cout << player.fGetName() << " turn." << std::endl;
		int action = player.fAction();

		if (action == 1)
		{
			std::cout << "Choose enemy: ";
		}
		else if (action == 2)
		{
			std::cout << "Choose skill: ";
		}
		else if (action == 3)
		{
			player.fListItem();
		}
		else if (action == 4)
		{
			std::cout << player.fGetName() << " tried to run away." << std::endl;
		}

	}
}

