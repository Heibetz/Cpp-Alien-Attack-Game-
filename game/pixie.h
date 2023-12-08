#pragma once
#include "gameHeader.h"

/*
* Hank Heiselbetz
* Alien Attack Project
* pixie.h
* Includes the class for Pixie
*/

class Pixie {
private:
	Texture currentTexture; //current texture obejct
	Sprite mySprite; //current sprite
	float x; //position x
	float y; //current y
	Pixie* nextPixie; //address of next pixie
	Pixie* previousPixie; //address of prvious pixie
	static int nextPixieID; //ID of the next pixie
	int myID; //ID of the current pixie
	int pixieType; //current pixie type
public: 
	Pixie(); //default
	Pixie(string texture, float x, float y, int pixieType); //w/ variables

	//Draws the spirte
	//passed the window
	//returns nothing
	void draw(RenderWindow& window);

	//moves the object
	//is passed x and y
	//returns nothing
	void move(float x, float y);

	//sets the scale for the object
	//is passed the x and y scale
	//returns nothing
	void setScale(float xScale, float yScale);

	//sets the position of the object
	//is passed the x and the y
	///returns nothing
	void setPosition(float x, float y);

	//getters and setters
	float getX() { return x; };
	float getY() { return y; };
	Sprite getSprite() { return mySprite; };
	Texture getTexture() { return currentTexture; };
	int getID() { return myID; };
	int getType() { return pixieType; };
	Pixie* getNext() { return nextPixie; };
	Pixie* getPrevious() { return previousPixie; };
	Pixie* getSelfPointer() { return this; };

	//sets pixie type
	//passed pixie type
	//retuns nothing
	void setType(int pixieType) { this->pixieType = pixieType; };

	//sets x 
	//passed x
	//returns nothing
	void setX(float xValue);

	//sets y
	//passed y
	//returns nothing
	void setY(float yValue);
};