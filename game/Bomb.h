#pragma once

#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>


using namespace sf;

class Bomb
{
private:
	Sprite bomb;



public:
	
	//overloaded constructor
	Bomb(Texture& bombTexture, Vector2f pos)
	{
		bomb.setTexture(bombTexture);
		bomb.setPosition(pos);
	}

	//drawing the bomb WHEN we drop one
	void dropBomb(RenderWindow& win)
	{
		bomb.move(0, 10); //move the bomb
		win.draw(bomb); //draw the bomb

	}

	//to check to see if the bomb hit the player
	FloatRect getBombBounds()
	{
		return bomb.getGlobalBounds();
	}

	//get the y position of the bomb for deleting offscreen on the below
	int getBombYPos()
	{
		return bomb.getPosition().y;
	}

	//draw the bomb
	void draw(RenderWindow& win)
	{
		win.draw(bomb);
	}




};