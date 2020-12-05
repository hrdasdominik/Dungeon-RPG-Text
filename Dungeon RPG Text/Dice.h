#pragma once
#include <ctime>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <Windows.h>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
#include <numeric>
#include <typeinfo>
#include <map>
#include <exception>
#include <list>
#include <iterator>
#include "sqlite3/sqlite3.h"

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

