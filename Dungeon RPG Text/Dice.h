#pragma once
#include <ctime>
#include <iomanip>
#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <functional>

class Dice
{
public:
	Dice();
	virtual ~Dice();
	
	//Functions
	int fRoll(int sides, int number);

	//Accessors
	static Dice* fGetDice() { return &dice; }

	//Modifiers

private:
	static Dice dice;
};

