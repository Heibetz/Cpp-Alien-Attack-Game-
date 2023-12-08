#pragma once
#include "gameHeader.h"

/*
* Hank Heiselbetz
* Alien Attack Project
* army.h
* Includes the class for Army
*/

class Army {
private:
	//creates a pointer to an array of pixie objects
	Pixie* alien[MAX_ALIENS];
	Pixie* dummyAlien;
public:
	//default constructor sets up all aliens 
	Army();

	//gets type of alien
	int getType(int x) { return alien[x]->getType(); };

	//draws the aliens
	//passed a window object to draw
	//returns nothing
	void draw(RenderWindow &window);

	//moves the aliens left and right and up and down
	//passed a boolean that checks if moving right
	//returns nothing
	void alienMove(bool& moveRight);

	//This functions has aliens shoot missiles downward on the screen
	//passsed a RenderWindow object, a Army object, Two alien missile objects, and two boolean object to check is missile is fired
	//returns nothing
	void alienFiringMissiles(int x, int y, RenderWindow &window, Pixie& alienMissile, Pixie& alienMissile2, bool& alienMissile1, bool& alienMissileTwo);

	void detectAlienMissileHits(Pixie& missile, bool& isMissileInFlight);

	void checkAliensLife();

	void detectShipMissileHits(int& counter, Pixie& ship, Pixie& alienMissile1, Pixie& alienMissile2, bool& isAlienMissile1Alive, bool& isAlienMissile2Alive);

	void checkAlienHeight();
};