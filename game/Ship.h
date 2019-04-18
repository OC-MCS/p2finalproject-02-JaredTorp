#pragma once

#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>


using namespace sf;

class Ship
{
private:
	Sprite ship; //sprite ship
	float shipX; //holds the ship's x
	float shipY; //holds the ship's y
	Texture shipTexture; //holds the texture

public:
	//======================================================
	// function name: Ship()
	// parameters: RenderWindow&- window
	// return type: none, its a constructor
	//======================================================
	Ship(RenderWindow& window)
	{
		
		if (!shipTexture.loadFromFile("NewShip.bmp"))
		{
			cout << "Unable to load ship texture!" << endl;
			exit(EXIT_FAILURE);
		}
		//texture the ship
		ship.setTexture(shipTexture); // set the texture

		// initial position of the ship will be approx middle of screen
		shipX = window.getSize().x / 2.0f; //set the ship's x
		shipY = window.getSize().y / 1.1f; //set the ship's y
		ship.setPosition(shipX, shipY); //set the position

	}
	
	//======================================================
	// function name: draw
	// parameters: RenderWindow&- window
	// return type: none, its void
	//======================================================
	void draw(RenderWindow& win)
	{
		win.draw(ship);
	}


	//======================================================
	// function name:mMoveShip
	// parameters: none
	// return type: none, its a void
	//======================================================
	void moveShip()
	{
		
		
		const float DISTANCE = 5.0f; //sets the move distance

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

	//======================================================
	// function name: getShipBounds()
	// parameters: none
	// return type: FloatRect 
	//======================================================
	FloatRect getShipBounds()
	{
		return ship.getGlobalBounds(); //returns the bounds of the ship
	}
	
	//======================================================
	// function name: getShipPosition()
	// parameters: none
	// return type: Vector2f, returns the position
	//======================================================
	Vector2f getShipPosition()
	{
		return ship.getPosition(); //returns the position
	}
	
};