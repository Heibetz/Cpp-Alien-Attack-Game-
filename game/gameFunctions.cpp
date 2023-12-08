#include "gameHeader.h"

/*
* Hank Heiselbetz
* Alien Attack Project
* gameFunctions.cpp
* contains some functions for the main 
*/


/*
*  moveShip - This function is called to handle a keyPress event. 
*     Keyboard input is detected and ship is moved.
*   ** Part of the lab is to also handle firing a missile **
*  INPUT: The ship sprite is passed.  This merely a drawn object on the screen.
*  RETURN: None
*/
void moveShip(Pixie &ship)
{
	/*
	 *  This first If-then-else-if Block handles 
	 */
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		// left arrow is pressed: move our ship left 5 pixels ( this is -5 pixels to go left)
		// 2nd parm is y direction. We don't want to move up/down, so it's zero.
		ship.move(-DISTANCE, 0);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		// right arrow is pressed: move our ship right 5 pixels
		ship.move(DISTANCE, 0);
	}
	

}

//MoveAndStopShipMissile
//moves the ships missile and check to see if the missile goes above the barrier
//passed a boolean to see if missile is in flight
//passed a window object to draw missile
//passed a missile object to be drawn
//void
void MoveAndStopShipMissile(bool& isShipMissileInFlight, RenderWindow& window, Pixie& missile)
{
	if (isShipMissileInFlight)
	{
		missile.move(0, -DISTANCE * 3);

		missile.draw(window);

		if (missile.getY() < 0)
		{
			isShipMissileInFlight = false;
		}
	}
}

