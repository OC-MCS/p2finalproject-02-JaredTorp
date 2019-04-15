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
#include <list>
#include "EnemyList.h"
#include "MissileList.h" 
#include <list>

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
	EnemyList EnemyList;
	MissileList MissileList;


	///////////////////////////////////////////
	//should this be in a class?????????????//
	/////////////////////////////////////////
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

	bool spacePressed = false; //to keep track of the misiles when the space is pressed


	//ANIMATION LOOP
	while (window.isOpen())
	{


		Event event; //variable for the event
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == Event::Closed)
				window.close();
			else if (event.type == Event::MouseButtonReleased)
			{
				//check to see if the Start button was pressed
				Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
				GameUI.handleMouseUp(mousePos); //checks the position of the moust to click the start
			}



			else if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Space)
				{
					MissileList.addMissile(Ship.getShipPosition());

				}

			}

		}

			//the game hasnt started
			if (!GameUI.getGameStarted())
			{

				window.draw(background);
				GameUI.drawStart(window);


			}

			//the game starts
			else if (GameSettings.getLives() != 0 && GameUI.getGameStarted()) // we want to keep in this if function until lives = 0
			{


				//texture for the stars background
				window.draw(background);
				//draw the games
				GameUI.drawGame(window, GameSettings); //draw the lives counter and the enemies
				//draw the ship/move the ship
				Ship.moveShip();
				Ship.draw(window);

				//draw the enemies and move the enemies
				EnemyList.moveEnemies();
				EnemyList.DrawEnemies(window);
				EnemyList.CheckDeleteEnemy(MissileList, GameSettings); //checks to see if the enemy is dead
				
				

				MissileList.drawMissiles(window);  //draw the missiles, pass the window and the bool
				MissileList.CheckIfOffscreen(); //check to see if the missile is off the screen 
				

				//we need to check to see if any of the enemies passes the Y value
				if (EnemyList.enemyTooLow() == true)
				{
					cout << "The enemies are too low!" << endl;
					GameSettings.LoseLife(); //need to lose a life
					EnemyList.resetEnemyPositions(); //need to reset the enemies positions back to the top

					/*GameUI.setGameStarted(false); */ //keep this here, do we restart?

				}


				//check to see if the missiles hit the enemy
				//pass the missile list and the Gamesetting to keep track of enemies killed
				
			

				
				
					
				
				

				
				




			}



		// end the current frame; this makes everything that we have 
		// already "drawn" actually show up on the screen
			window.display();





		

		
	}
	
	return 0;
}
