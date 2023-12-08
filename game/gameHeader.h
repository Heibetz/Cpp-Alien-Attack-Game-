#pragma once
/*
* Hank Heiselbetz
* Alien Attack Project
* gameHeader.h
* Has the header information 
*/

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

//const amount of aliens
const int MAX_ALIENS = 10;

#include "pixie.h"
#include "army.h"

// Constants for the game 
const float DISTANCE = 5.0f; // When the ship moves it moves 5 pixels at a time. 
const int WINDOW_WIDTH = 800; // window is 800 pixels wide
const int WINDOW_HEIGHT = 600;// window is 600 pixels vertically "high"

//constants used for passing to the pixies
const int UNDEFINED_PIXIE = 1; //used for dummy alien pixies
const int PLAYER_SHIP_PIXIE = 2; //used for pixie ship
const int PLAYER_MISSILE_PIXIE = 3; //used for player missile pixies
const int BACKGROUND_PIXIE = 4; //used for background pixie
const int ALIEN_PIXIE = 5; //used for alien pixies

// Game Functions
void moveShip(Pixie &ship); 

void MoveAndStopShipMissile(bool& isShipMissileInFlight, RenderWindow& window, Pixie& missile);
