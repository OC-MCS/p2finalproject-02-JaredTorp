//=========================================================
// This is just the starting point for your final project.
// You are expected to modify and add classes/files as needed.
// The code below is the original code for our first graphics
// project (moving the little green ship). 
//========================================================

#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
#include "GameUI.h"
#include "Ship.h"
#include "GameSettings.h"

using namespace sf; 

//============================================================
// Jared Torp
// Final project, Space invaders
// Due April 19, 2019
//============================================================

// note: a Sprite represents an image on screen. A sprite knows and remembers its own position
// ship.move(offsetX, offsetY) adds offsetX, offsetY to 
// the current position of the ship. 
// x is horizontal, y is vertical. 
// 0,0 is in the UPPER LEFT of the screen, y increases DOWN the screen



int main()
{
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "aliens!");
	// Limit the framerate to 60 frames per second
	window.setFramerateLimit(60);

	//creating the GameUI object 
	GameUI GameUI;
	Ship Ship(window);//creates the ship object and passes the window
	GameSettings GameSettings;
	



	//should this be in a class?????????????
	Texture starsTexture;
	if (!starsTexture.loadFromFile("stars.jpg"))
	{
		cout << "Unable to load stars texture!" << endl;
		exit(EXIT_FAILURE);
	}

	// A sprite is a thing we can draw and manipulate on the screen.
	// We have to give it a "texture" to specify what it looks like

	Sprite background;
	background.setTexture(starsTexture);
	// The texture file is 640x480, so scale it up a little to cover 800x600 window
	background.setScale(1.5, 1.5);
	

	while (window.isOpen())
	{
		
		Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == Event::Closed)
				window.close();
			else if (event.type == Event::MouseButtonReleased)
			{
				//check to see if the Start button was pressed
				Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
				GameUI.handleMouseUp(mousePos);
			}
		
		
		}

		if (!GameUI.getGameStarted())
		{
			window.draw(background);
			GameUI.drawStart(window);
			
		}
		else
		{
			//texture for the stars background
			window.draw(background);

			GameUI.drawGame(window, GameSettings); //draw the lives counter and the enemies
			Ship.draw(window);
			Ship.moveShip();

			
			//LEFT OFF HERE

			//if (enemy.getEnemyBounds().intersects(Ship.getShipBounds()))
			//	{
			//		GameSettings.LoseLife();
			//		should we check the lives here? for the game over function?
			//      restart the game
			//	}

		
		
		
		}
		// end the current frame; this makes everything that we have 
		// already "drawn" actually show up on the screen
		window.display();


	}
	

	return 0;
}

