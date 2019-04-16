#pragma once

#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>


using namespace sf;

class Missile
{
private: 
	Sprite missile;
	

public:
	
	//overoaded constructor
	Missile(Texture& missileTexture, Vector2f pos)
	{
		
		Vector2f offset(9, 0);
		missile.setTexture(missileTexture); 
		missile.setPosition(pos + offset); //i Put this offset here to keep the missile center to the ship

	}


	//draw/move the missile
	void draw(RenderWindow& win)
	{
		missile.move(0, -10); //move the missile
		win.draw(missile); //draw the missile
		
	}

	//function to get the missile bounds
	FloatRect getMissileBounds()
	{
		return missile.getGlobalBounds();
	}

	//get the y position of the missile
	int getMissileYPos()
	{
		return missile.getPosition().y;
	}


};