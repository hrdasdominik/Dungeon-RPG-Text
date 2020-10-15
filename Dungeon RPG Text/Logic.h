#pragma once
#include "Player.h"

class Logic
{
public:
	Logic();
	virtual ~Logic();

	//Operators

	//Functions
	void fInsertName();
	
	//Game functions
	void fMainMenu();
	void fPickClass();
	void fNewGame();
	

	//Accessors
	inline const bool fGetPlaying() const { return this->playing; }

	//Modifiers

private:
	int choice;
	bool playing;

	//Player related
	Player player;
};

