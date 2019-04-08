#pragma once

#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>


using namespace sf;

class Ship
{
private:
	Sprite ship;
	float shipX;
	float shipY;
	Texture shipTexture;

public:
	Ship(RenderWindow& window)
	{
		
		if (!shipTexture.loadFromFile("ship.png"))
		{
			cout << "Unable to load ship texture!" << endl;
			exit(EXIT_FAILURE);
		}
	ship.setTexture(shipTexture);

	// initial position of the ship will be approx middle of screen
	shipX = window.getSize().x / 2.0f;
	shipY = window.getSize().y / 1.1f;
	ship.setPosition(shipX, shipY);
	//texture the ship
	

	

	}
	
	//function to draw the ship
	void draw(RenderWindow& win)
	{
		
		win.draw(ship);
	}

	//function to move the ship based on player input
	void moveShip()
	{
		
		
		const float DISTANCE = 5.0f;

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			// left arrow is pressed: move our ship left 5 pixels
			// 2nd parm is y direction. We don't want to move up/down, so it's zero.
			if (!(ship.getPosition().x <= 0))
			{
				ship.move(-DISTANCE, 0);
			}
		}
		else if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			// right arrow is pressed: move our ship right 5 pixels
			if (!(ship.getPosition().x >= 775))
			{
				ship.move(DISTANCE, 0);
			}


		}
		
		
	}

	
	
};