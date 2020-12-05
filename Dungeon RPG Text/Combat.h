#pragma once
#include "Player.h"
#include "Enemy.h"

class Combat
{
public:
	//Con n Destructor
	Combat() { turn = 0; }
	virtual ~Combat() = default;

	//Functions
	void fTurnOrder(Enemy& enemy, Enemy& enemy2);
	void fBattle(Player& player, Enemy& enemy);
	void fBattle(Player& player, Enemy& enemy, Enemy& enemy2);

private:
	std::list<Enemy> lOrder;
	int turn;
};

