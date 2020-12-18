#pragma once
#include "Player.h"
#include "Enemy.h"

class Combat
{
public:
	//Con n Destructor
	Combat() { turn = 1; }
	virtual ~Combat() = default;

	//Functions
	void fTurnRoll(Player& player, Enemy& enemy);
	void fTurnRoll(Player& player, Enemy& enemy, Enemy& enemy2);
	void fBattle(Player& player, Enemy& enemy);
	void fBattle(Player& player, Enemy& enemy, Enemy& enemy2);

private:
	//Functions
	void fEnemyAction(Enemy& enemy, Player& player);
	void fPlayerAction(Player& player, Enemy& enemy);
	void fPlayerAction(Player& player, Enemy& enemy, Enemy& enemy2);

	std::list<Enemy> lOrder;
	int turn;
};

