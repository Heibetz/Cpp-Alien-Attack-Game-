#include "gameHeader.h"


/*
* Hank Heiselbetz
* Alien Attack Project
* pixie.cpp
* Includes the functions for class Pixie
*/

Pixie::Pixie()
{
	x = 0;
	y = 0;
	nextPixie = nullptr;
	previousPixie = nullptr;
	nextPixieID = 0;
	myID = 0;
	myID = nextPixieID++;
	pixieType = UNDEFINED_PIXIE;
}

Pixie::Pixie(string texture, float x, float y, int pixieType)
{
	if (!currentTexture.loadFromFile(texture)) {
		cout << "Could not open file" << texture << endl;
	}
	mySprite.setTexture(currentTexture);
	mySprite.setPosition(x, y);

	this->x = x;
	this->y = y;
	this->pixieType = pixieType;
	myID = nextPixieID++;
	nextPixie = nullptr;
	previousPixie = nullptr;

}


int Pixie::nextPixieID = 0;


void Pixie::draw(RenderWindow& window)
{
	window.draw(mySprite);
}

void Pixie::move(float x, float y)
{
	this->x += x;
	this->y += y;
	mySprite.setPosition(this -> x, this-> y );
}

void Pixie::setScale(float xScale, float yScale)
{
	mySprite.setScale(xScale, yScale);
}

void Pixie::setPosition(float x, float y)
{
	this->x = x;
	this->y = y;
	mySprite.setPosition(x, y);
}

void Pixie::setX(float xValue)
{
	x = xValue;
	mySprite.setPosition(xValue, y);
}

void Pixie::setY(float yValue)
{
	y = yValue;
	mySprite.setPosition(x, yValue);
}
