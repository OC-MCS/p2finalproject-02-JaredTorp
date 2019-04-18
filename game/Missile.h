#pragma once

#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>


using namespace sf;

class Missile
{
private: 
	Sprite missile; //the missile's sprite
	

public:
	
	//======================================================
	// function name: Missile
	// parameters: Texture& missileTexture - pass the missile's texture
	// Vector2f pos - pass the position
	// return type: none, its a constructor
	//======================================================
	Missile(Texture& missileTexture, Vector2f pos)
	{
		
		Vector2f offset(9, 0); //sets the offset of the missile so it is aligned with the ship
		missile.setTexture(missileTexture);  //set texture
		missile.setPosition(pos + offset); //i Put this offset here to keep the missile center to the ship

	}

	//======================================================
	// function name: draw
	// parameters: RenderWindow
	// return type: none, its a constructor
	//======================================================
	void draw(RenderWindow& win)
	{
		missile.move(0, -10); //move the missile
		win.draw(missile); //draw the missile
		
	}


	//======================================================
	// function name: getMissileBounds()
	// parameters:
	// return type: nFloatRect, returns the global bounds of the missile
	//======================================================
	FloatRect getMissileBounds()
	{
		return missile.getGlobalBounds();
	}

	//======================================================
	// function name: getMissileYPos()
	// parameters:
	// return type: int
	//======================================================
	float getMissileYPos()
	{
		return missile.getPosition().y; //returns the y position of the missile
	}


};