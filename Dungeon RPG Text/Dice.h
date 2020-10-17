#pragma once
#include <ctime>
#include <iomanip>
#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
#include <numeric>

class Dice
{
public:
	Dice();
	virtual ~Dice();
	
	//Functions
	int fRoll(int sides, int number);
	int fRollStats();

	//Accessors
	static Dice* fGetDice() { return &dice; }

	//Modifiers

private:
	static Dice dice;
};

