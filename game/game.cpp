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
#include "BombList.h"

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
	EnemyList Enemies;
	MissileList Missiles;
	BombList Bombs;


	int frameCounter = 0; //counter to count the frames, so we can keep track of every second, 60fps

	
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

	
	bool PlayerHit; //define a bool to check if the player was hit


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
				GameUI.handleMouseUp(mousePos, GameSettings); //checks the position of the moust to click the start
			
			}
			else if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Space)
				{
					Missiles.addMissile(Ship.getShipPosition());

				}

			}

		}

		



			//the game hasnt started
			if (GameSettings.getGameStarted() ==  false)
			{

				window.draw(background);
				GameUI.drawStart(window);
				

			}

			//the game starts here, the level should be at level one
			//figure out how to resart the game WITHOUT going into a whole different While loop

			else if (GameSettings.getGameStarted() == true) // The game has started
			{
				



				//texture for the stars background
				window.draw(background);

				//draw the games
				GameUI.drawGame(window, GameSettings); //draw the lives counter and the enemies

				//draw the ship/move the ship
				Ship.moveShip();
				Ship.draw(window);

				//draw the enemies and move the enemies
				Enemies.moveEnemies();
				Enemies.DrawEnemies(window);
				Enemies.CheckDeleteEnemy(Missiles, GameSettings); //checks to see if the enemy is dead
				
				
				//draw/fire the Missiles
				Missiles.drawMissiles(window);  //draw the missiles, pass the window and the bool
				Missiles.CheckIfOffscreen(); //check to see if the missile is off the screen 
				
				//Bombs
				//do game1 bomb
				if (frameCounter == GameSettings.getDropRate())
				{
					Enemies.DropBomb(Bombs);
					frameCounter = 0;
				}

				Bombs.drawBombs(window); //function that draws bombs
				Bombs.CheckIfOffscreen(); //checks to see if we need to delete the bombs
				
				//sets the bool to true or false, whether or not the player has been hit by a bomb
				PlayerHit = Bombs.CheckHitPlayer(Ship); //we need to check if the bomb hits the player, so we pass the ship


				//we need to check to see if any of the enemies passes the Y value
				if (Enemies.enemyTooLow() == true || PlayerHit)
				{
					GameSettings.LoseLife(); //need to lose a life
					Enemies.resetEnemyPositions(); //need to reset the enemies positions back to the top


				}

				//check to see if all the enemies have been killed!
				if (Enemies.getEnemyList().size() == 0 && GameSettings.getLevel() == 1)
				{
					//set the level to two

					GameSettings.setLevel(2); 
					Missiles.DeleteList(); //because we dont want to accidentally shoot the level 2 enemies
					Enemies.createEnemies(GameSettings.getLevel()); //recreate the enemies
					GameSettings.setDropRate(60);//change the time (frames), for the drop rate
					//so it drops every second
					frameCounter = 0; //reset the frame counter

				}

				//Level 2 checks to see if the game is over
				if (Enemies.getEnemyList().size() == 0 && GameSettings.getLevel() == 2)
				{
					//YOU WIN!
				}

				//check if GAMEOVER when lives run out
				//this function will reset the game
				if (GameSettings.getLives() == 0)
				{
					//resetting the game
					GameSettings.setLives(3); //set the lives back to 3
					GameSettings.setLevel(1); //set the level back to one
					Enemies.createEnemies(1); //create the enemies for level 1
					GameSettings.setDropRate(120); //set the drop rate back to 120
					GameSettings.setGameStarted(false); //the game is now NOT started
					

					//Aliens win!

				}



			}
			
			
			//would I do another while loop? I might just adjust the settings, recreate the enemies, and start again
			//Level 2 
			


		// end the current frame; this makes everything that we have 
		// already "drawn" actually show up on the screen
			window.display();

			frameCounter++; //to count the frames, will count 60 a second



		

		
	}
	
	return 0;
}
