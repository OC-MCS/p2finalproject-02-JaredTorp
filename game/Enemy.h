#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>

//this class handles a single enemy's attributes
using namespace sf;


class Enemy
{
private:
	Sprite enemy; //holds the enemy sprite
	float movement; //holds the movement of the enemy, we will change it between level 1 and 2
	

public:
	

	//======================================================
	// function name: Enemy
	// parameters: Vector2f pos- pass a position,
	//Texture& enemyTexture--pass a texture by reference
	// int movement- passing a movement
	// return type: none, void
	//======================================================
	Enemy(Vector2f pos, Texture& enemyTexture, float movement)
	{
		//set the texture of the enemy
		enemy.setTexture(enemyTexture);

		enemy.setPosition(pos); //set the position of the enemy
		
		this->movement = movement; //setting the new movement to the movement


	}


	//======================================================
	// function name: Draw
	// parameters: RenderWindow& win- pass the window
	// return type: none, void
	//======================================================
	void draw(RenderWindow& win)
	{
		win.draw(enemy); //one liner that draws the enemy
	}


	//======================================================
	// function name: EnemyMove()
	// parameters: none
	// return type: none, void
	//======================================================
	void EnemyMove()
	{	
		enemy.move(0, movement); //moves the enemy
	}
	
	//======================================================
	// function name: getEnemyPosition()
	// parameters: none
	// return type: Vector2f - we return the position
	//======================================================
	Vector2f getEnemyPosition()
	{
		return enemy.getPosition(); //returns enemy position
	}

	//======================================================
	// function name: setEnemyPosition()
	// parameters: Vector2f- to set the position
	// return type: none void
	//======================================================
	void setEnemyPosition(Vector2f pos)
	{
		enemy.setPosition(pos); //setting the enemy position
	}
	
	
	//======================================================
	// function name: getEnemyBounds()
	// parameters: none
	// return type: FloatRect, returns the bounds of the enemy
	//======================================================
	FloatRect getEnemyBounds()
	{
		return enemy.getGlobalBounds(); //returns the enemy's bounds
	}
	  
	//======================================================
	// function name: getEnemyXPosition()
	// parameters: none
	// return type:int, to get the x positont
	//======================================================
	float getEnemyXPosition()
	{
		return enemy.getPosition().x; //returns the enemy's x position
	}



};