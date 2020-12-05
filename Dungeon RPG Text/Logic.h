#pragma once
#include "Combat.h"

class Logic
{
public:
	Logic();
	virtual ~Logic();

	//Operators

	//Functions
	void fMainMenu();
	void fNewGame();

	//Mechanics
	bool fGameRunning();
	
	//Story functions

	//Accessors
	inline const bool fGetPlaying() const { return this->playing; }

	//Modifiers

private:
	
	int choice;
	bool playing;

	//Player related
	Player player;
	Combat combat;
};

