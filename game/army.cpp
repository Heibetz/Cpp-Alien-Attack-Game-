#include "gameheader.h"

/*
* Hank Heiselbetz
* Alien Attack Project
* army.cpp
* Includes the army functions code
*/

//Army()
//default constructor
//passed nothing
//returns nothing
Army::Army()
{
	//creates a dummy alien incase missile hits
	dummyAlien = new Pixie("alien.bmp", 300, -500, UNDEFINED_PIXIE);
	float x = 125.0; //Creates a float x to input alien at that X
	float y = 15.0; //creates a float Y to input alien at that Y
	//for loop that sets up an array of aliens
	for (int i = 0; i < MAX_ALIENS; i++) {
		alien[i] = new Pixie( "alien.bmp", x, y, ALIEN_PIXIE );
		x += 55; //adds 55 to float X to move the alien 55 inputs right
	}
}

//Draw
//Draws the aliens to the screen
//Passed a RenderWindow object
//void
void Army::draw(RenderWindow& window)
{
	//for loops that draws the array of aliens
	for (int i = 0; i < MAX_ALIENS; i++) {
		if (alien[i]->getType() != UNDEFINED_PIXIE) {
			alien[i]->draw(window);
		}
	}
}

//AlienMove
//Moves the aliens left and right, once it reaches an edge it moves the aliens down
//passed a boolean called moveRight
//void
void Army::alienMove(bool& moveRight)
{
	bool changeDirection = false;
	//for loop that runs through array of aliens
    for (int i = 0; i < MAX_ALIENS; i++) {
		//checks if alien touches barrier then goes opposite direction
        if (alien[i]->getX() < WINDOW_WIDTH - 30 && moveRight)
        {
			//moves
			if (alien[i]->getType() == ALIEN_PIXIE) {
				alien[i]->move(DISTANCE, 0);
			}
			//if touches barrier, stops moving right
            if (alien[i]->getX() > WINDOW_WIDTH - 31) {
				changeDirection = true;
				float getTempY = alien[i]->getY();
				//makes the aliens move downwards once it touches barrier
				for (int y = 0; y < MAX_ALIENS; y++) {
					alien[y]->setY((getTempY + 15));
				}
            }	
        }
    }

	//runs through array of aliens
    for (int x = 0; x < MAX_ALIENS; x++) {
		//checks to make sure its not moving right and that ne alens are touching left barrier
        if (alien[x]->getX() > 1 && !moveRight)
        {
			//moves aliens to left
			if (alien[x]->getType() == ALIEN_PIXIE) {
				alien[x]->move(-DISTANCE, 0);
			}
			//checks if any alien has touched the left barrier and moves them down and back to the right
            if (alien[x]->getX() < 1) {
 				changeDirection = true;
				float getTempY2 = alien[x]->getY();
				//moves aliens down
				for (int z = 0; z < MAX_ALIENS; z++) {
					alien[z]->setY((getTempY2 + 15));
				}
            }
        }
    }
	//changes the direction of the alien by changing the boolean
	if (changeDirection) {
		moveRight = !moveRight;
	}
}

//alienFiringMissiles
//Makes the aliens fire missiles
//passed a rand int x and y, a renderWindow object to draw on screen,
//passed a Pixie alien Missile 1 and alien Missile 2 to be drawn
//passed 2 booleans to see if the missiles are in air
//void
void Army::alienFiringMissiles(int x, int y, RenderWindow &window, Pixie& alienMissile, Pixie& alienMissile2, bool& isAlienMissileAlive, bool& isAlienMissile2Alive)
{
	//checks to see if alien missile is alive
	if (!isAlienMissileAlive) {
		//changes alien missile alive to true and then gets the aliens location
		isAlienMissileAlive = true;
		float alienMissileX = alien[x]->getX();
		float alienMissileY = alien[x]->getY();
		//sets aliens location to missile location
		alienMissile.setPosition(alienMissileX, alienMissileY);
	}

	//create an if else to make sure that isAlienMissileAlive is true
	if (isAlienMissileAlive) {
		//moves alien missile down the screen and the draws it
		alienMissile.move(0, DISTANCE);

		alienMissile.draw(window);
	}
	else {
		isAlienMissileAlive = false;
	}

	//If the missile reaches the bottom, isAlienMissile is set to false, creating a new missile
	if (alienMissile.getY() > WINDOW_HEIGHT) {
		isAlienMissileAlive = false;
	}

	//Same process repeated for alien missile 2
	if (!isAlienMissile2Alive) {
		isAlienMissile2Alive = true;
		float alienMissileX = alien[y]->getX();
		float alienMissileY = alien[y]->getY();
		alienMissile2.setPosition(alienMissileX, alienMissileY);
	}

	if (isAlienMissile2Alive) {
		alienMissile2.move(0, DISTANCE);

		alienMissile2.draw(window);
	}
	else {
		isAlienMissile2Alive = false;
	}

	//check barrier for missile 2
	if (alienMissile2.getY() > WINDOW_HEIGHT) {
		isAlienMissile2Alive = false;
	}	
}

//Name, Purpose, Input parameters, Return values(or void)
//detectAlienMissileHits
//detects if the alien is hit by a missile
//Passed a pixie missile and a boolean that turns false if alien is hit
//void
void Army::detectAlienMissileHits(Pixie& missile, bool& isMissileInFlight)
{
	//gets the area of the missile
	FloatRect missileBounds = missile.getSprite().getGlobalBounds();
	//creates a for loop for the array
	for (int i = 0; i < MAX_ALIENS; i++) {
		//gets the bounds for each alien
		FloatRect alienBounds = alien[i]->getSprite().getGlobalBounds();
		//if missile bound touches alien bound
		if (missileBounds.intersects(alienBounds)) {
			//removes the missile in flight
			isMissileInFlight = false;
			//sets missile position off screen
			missile.setPosition(-100, -100);
			//Gets rid of alien hit by putting in dummy information for it.
			alien[i] = dummyAlien;
		}
	}
}

//CheckAliensLife()
//Checks to see if all aliens have been removed. If they have, program exits
//passed nothing
//void
void Army::checkAliensLife()
{
	//counter used to check if all aliens are dead
	int counter = 10;
	//for loop for array of aliens
	for (int i = 0; i < MAX_ALIENS; i++) {
		//checks to see if any aliens are dead. If they are dead
		//the counter removes one. Once all 10 are dead counter will
		//be set to 0 and the user wins the game.
		if (alien[i]->getType() == UNDEFINED_PIXIE) {
			counter--;
			if (counter == 0) {
				cout << "All Aliens are dead! You win!" << endl;
				exit(0);
			}
		}
	}
}

//detectShipMissileHits
//detects if the ship is hit by a missile. If hit 3 times the user loses
//passed an int counter, pixie ship, pixie alien missile 1 and 2, and 
//booleans for both alien missiles
//void
void Army::detectShipMissileHits(int& counter, Pixie& ship, Pixie& alienMissile1, Pixie& alienMissile2, bool& isAlienMissile1Alive, bool& isAlienMissile2Alive)
{
	//gets the bounds for both missiles
	FloatRect missileBounds = alienMissile1.getSprite().getGlobalBounds();
	FloatRect missile2Bounds = alienMissile2.getSprite().getGlobalBounds();
	//creates a for loop for array of aliens
	for (int i = 0; i < MAX_ALIENS; i++) {
		//gets bound for the ship
		FloatRect shipBounds = ship.getSprite().getGlobalBounds();
		//if statements checking if missile intersects ship
		if (missileBounds.intersects(shipBounds) || missile2Bounds.intersects(shipBounds))
		{
			//counter-- used to count how many times the ship gets hit
			counter--;
			//if counter = 0 then user loses.
			if (counter == 0) {
				cout << "Alien ship DEAD. Died too many times." << endl;
				exit(0);
			}
			//if missile intersects, missiles are set to false
			isAlienMissile1Alive = false;
			isAlienMissile2Alive = false;
			//ship is set back to original position
			ship.setPosition(WINDOW_WIDTH / 2.0, WINDOW_HEIGHT / 2.0);
		}
	}
}

//Name, Purpose, Input parameters, Return values(or void)
//checkAlienHeight()
//checks the alien height to see if the aliens have fallen below the ship
//passed nothing
//returns nothing
void Army::checkAlienHeight()
{
	//creates for loop for array of aliens
	for (int i = 0; i < MAX_ALIENS; i++) {
		//if aliens y coordinate is past the ship, you lose 
		if (alien[i]->getY() > ((WINDOW_HEIGHT + 50) / 2.0)) {
			cout << "You lost! Aliens passed your ship :(" << endl;
			exit(0);
		}
	}
}