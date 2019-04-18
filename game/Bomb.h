#pragma once

#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>


using namespace sf;

class Bomb
{
private:
	Sprite bomb; //bomb's sprite
	float movement; //an int that keeps track of the movement


public:
	
	//======================================================
	// function name: Bomb()
	// parameters: Texture& bombTexture- we pass the texture of the bomb by reference
	// return type: none, its a constructor
	//======================================================
	Bomb(Texture& bombTexture, Vector2f pos)
	{
		bomb.setTexture(bombTexture); //sets the texture
		bomb.setPosition(pos); //sets the bomb's position
		movement = 6; //movement of the bomb is 6
	}

	//======================================================
	// function name: Bomb()
	// parameters: Texture& bombTexture- we pass the texture of the bomb by reference
	// return type: none, its a constructor
	//======================================================
	FloatRect getBombBounds()
	{
		return bomb.getGlobalBounds();
	}

	//======================================================
	// function name: getBombYPos()
	// parameters:none
	// return type: int, we want the Y position
	//======================================================
	float getBombYPos()
	{
		return bomb.getPosition().y; //return the y position
	}

	//======================================================
	// function name: draw()
	// parameters: RenderWindow& Window- pass the window to draw
	// return type: none, its a void
	//======================================================
	void draw(RenderWindow& win)
	{
		bomb.move(0, movement); //move the bomb
		win.draw(bomb); //draw the bomb
	}



};