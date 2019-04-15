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
	
		missile.setTexture(missileTexture); 
		missile.setPosition(pos);

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