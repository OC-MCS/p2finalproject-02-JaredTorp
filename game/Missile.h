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

	Missile(Texture& missileTexture, Vector2f pos)
	{
	
		missile.setTexture(missileTexture); 
		missile.setPosition(pos);
		


	}

	//you will need a missile overloaded constructor, just look at the alien class for example
	//we use the overloaded for multiple missiles



	void setMissilePosition(Vector2f pos)
	{
		missile.setPosition(pos);
	}

	/*void missileMove()
	{
	


		



	}*/


	void draw(RenderWindow& win)
	{
		missile.move(0, -10);
		win.draw(missile);
		
		
		
	}

	FloatRect getMissileBounds()
	{
		return missile.getGlobalBounds();
	}



};