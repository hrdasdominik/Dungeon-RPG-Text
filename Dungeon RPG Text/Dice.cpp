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

int Dice::fStatsRoll()
{
	std::vector<int>stat;
	stat.push_back(fRoll(6, 1));
	stat.push_back(fRoll(6, 1));
	stat.push_back(fRoll(6, 1));
	stat.push_back(fRoll(6, 1));
	std::sort<>(stat.begin(), stat.end());
	stat.erase(stat.begin());
	int result = std::accumulate(stat.begin(), stat.end(), 0);
	return result;
}