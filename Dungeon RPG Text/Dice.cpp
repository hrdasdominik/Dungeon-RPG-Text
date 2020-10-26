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
	std::cout << result;
	for(int roll = 0; roll < number; roll++)
	{
		result += rand() % sides + 1;
	}
	return result;
}

int Dice::fRollStats()
{
	std::vector<int>stats;
	stats.push_back(fRoll(6, 1));
	/*stats.push_back(fRoll(6, 1));
	stats.push_back(fRoll(6, 1));
	stats.push_back(fRoll(6, 1));*/
	std::sort(stats.begin(), stats.end());
	stats.erase(stats.begin());
	int result = std::accumulate(stats.begin(), stats.end(), 0);
	return result;
}

