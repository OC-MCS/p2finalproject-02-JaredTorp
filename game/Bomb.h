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

	Bomb(Texture& bombTexture, Vector2f pos)
	{
		bomb.setTexture(bombTexture);
		bomb.setPosition(pos);
	}

	void draw(RenderWindow& win)
	{
		bomb.move(0, 10); //move the bomb
		win.draw(bomb); //draw the bomb

	}

	FloatRect getBombBounds()
	{
		return bomb.getGlobalBounds();
	}

	//get the y position of the bomb for deleting offscreen
	int getBombYPos()
	{
		return bomb.getPosition().y;
	}




};