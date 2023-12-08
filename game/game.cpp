#include "gameHeader.h"
/*
* Hank Heiselbetz
* Alien Attack Project
* game.cpp
* Has the main functions codes
*/

//int main
//runs the code for the game
//passed nothing
//returns 0
int main()
{
	// Create the window for graphics. 
	//  The "aliens" is the text in the title bar on the window. 
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "aliens!");
	
	// Limit the framerate to 60 frames per second
	window.setFramerateLimit(60);

	//sets everything up
	Pixie background("stars.jpg", 0, 0, BACKGROUND_PIXIE);
	background.setScale(1.5, 1.5);

	//creates pixie for ship
	Pixie ship("ship.png", 0, 0, PLAYER_SHIP_PIXIE);

	//calling Army object to set aliens.
	Army aliens;
	//This will be passed to alien.move later on.
	bool moveRight = true;
	
	//Ship missile
	Pixie missile("missile.bmp", 0, 0, PLAYER_MISSILE_PIXIE);

	//Sets the pixie of alien missiles
	Pixie alienMissile("missile.bmp", 0, 0, UNDEFINED_PIXIE); //pixie alien missile 1
	Pixie alienMissile2("missile.bmp", 0, 0, UNDEFINED_PIXIE); //pixie alien missile 2
	bool isAlienMissileAlive = false; //creates boolean to see if missile in air
	bool isAlienMissile2Alive = true; //creates boolean to see if missile in air
	
	//sets position of ship
	float shipX = window.getSize().x / 2.0f;
	float shipY = window.getSize().y / 2.0f;
	ship.setPosition(shipX, shipY);
	bool isShipMissileInFlight = false; // used to know if a missile is 'on screen'. 

	//creating a bool to see of ship is alive
	bool isShipAlive = true;

	//creating a counter for the amount of player lifes
	int counter = 3;


	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		// For now, we just need this so we can click on the window and close it
		Event event;

		// This while loop checks to see if anything happened since last time
		// we drew the window and all its graphics. 
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) // Did the user kill the window by pressing the "X"?
				window.close();
			else if (event.type == Event::KeyPressed) // did the user press a key on the keyboard?
			{
				if (event.key.code == Keyboard::Space && !isShipMissileInFlight)
				{
					isShipMissileInFlight = true;
					int missileX = ship.getX();
					int missileY = ship.getY();
					missile.setPosition(missileX, missileY);
				}
			}
		}

		//===========================================================
		// Everything from here to the end of the loop is where you put your
		// code to produce ONE frame of the animation. The next iteration of the loop will
		// render the next frame, and so on. All this happens ~ 60 times/second.
		//===========================================================

		// draw background first, so everything that's drawn later 
		// will appear on top of background
		background.draw(window);

		//detect key presses to update the position of the ship. 
		//See moveShip() function above.
		moveShip(ship);

		//Protects the ship from going out of the boundaries
		if (ship.getX() < 0)
		{
			ship.setPosition(0, ship.getY());
		}
		if (ship.getX() > WINDOW_WIDTH - 20)
		{
			ship.setPosition(WINDOW_WIDTH - 20, ship.getY());
		}

		// draw the ship on top of background 
		// (the ship from previous frame was erased when we drew background)
		ship.draw(window);

		//moves the aliens right and left and down the screen.
		aliens.alienMove(moveRight);


		//Creates a randome x and y to pass to alienFiringMissiles
		int x = rand() % 10;
		int y = rand() % 10;
		//Checks to make sure alien is alive
		while (aliens.getType(x) != ALIEN_PIXIE) {
			x = rand() % 10;
		}
		//Check to make sure alien is alive
		while (aliens.getType(y) != ALIEN_PIXIE) {
			y = rand() % 10;
		}
		//This function has alien shoot missiles
		aliens.alienFiringMissiles(x, y, window, alienMissile, alienMissile2, isAlienMissileAlive, isAlienMissile2Alive);


		//drawing the aliens on top of the background
		aliens.draw(window);

		//moves the missile and stops it if it goes above y = 0
		MoveAndStopShipMissile(isShipMissileInFlight, window, missile);

		//Detects aliens being hit by missiles
		aliens.detectAlienMissileHits(missile, isShipMissileInFlight);

		//checks to make sure not all the aliens are dead 
		//if dead, program exits and the user wins.
		aliens.checkAliensLife();

		//Detects if ship is hit by a missile.
		//If the ship is hit 3 times, the game exits and the user loses.
		aliens.detectShipMissileHits(counter, ship, alienMissile, alienMissile2, isAlienMissileAlive, isAlienMissile2Alive);

		//checks alien height. If aliens get too low, game ends
		aliens.checkAlienHeight();

		// end the current frame; this makes everything that we have 
		// already "drawn" actually show up on the screen
		window.display();
	} 

	return 0;
}

