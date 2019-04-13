#pragma once

#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>


using namespace sf;

class Missile
{
private: 
	Sprite missile;
	Texture missileTexture; //dont keep in here
	
//Vector2f missilePosition; //this may be stupid

public:

	Missile()
	{
		if (!missileTexture.loadFromFile("missile.png"))
		{
			cout << "Unable to load missile texture!" << endl;
			exit(EXIT_FAILURE);
		}
		missile.setTexture(missileTexture); 

		


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


	void draw(RenderWindow& win, bool& flag)
	{
		 


		if (missile.getPosition().y > 0)
		{
			missile.move(0, -10);
			win.draw(missile);
		}
		else
		{
			flag = false;
			
		}
		
	}





};