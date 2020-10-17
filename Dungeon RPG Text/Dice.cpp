#include "Dice.h"


Dice::Dice()
{
	
}

Dice::~Dice()
{

}

int Dice::fRoll(int sides, int number)
{
	int result = {};
	for(int roll = 0; roll < number; roll++)
	{
		result += rand() % sides + 1;
	}
	return result;
}