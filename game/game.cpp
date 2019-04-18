
//============================================================
// Jared Torp
// Final project, Space invaders
// Due April 19, 2019
//============================================================


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


void ResetGame(EnemyList& Enemies, MissileList& Missiles, BombList& Bombs, GameSettings& Settings, Ship& Ship); //prototype



int main()
{
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "aliens!");
	// Limit the framerate to 60 frames per second
	window.setFramerateLimit(60);


	//creating the GameUI object 
	GameUI GameUI; //define a GameUI object
	Ship Ship(window);//creates the ship object and passes the window
	GameSettings Settings; //Create a settings object
	EnemyList Enemies; //EnemyList object 
	MissileList Missiles; //MissileList Object
	BombList Bombs; //List of Bomb Object


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

	bool gameWon = false; //these bools will help us draw the text if the player
	bool gameLost = false;// or the enemy wins the game

	bool PlayerHit; //define a bool to check if the player was hit
	Enemies.createEnemies(1); //to Initially set the level 1 enemies before we hit the loop

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
				GameUI.handleMouseUp(mousePos, Settings); //checks the position of the mouse to click the start
			
			}
			else if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Space)
				{
					Missiles.addMissile(Ship.getShipPosition()); //shoots a missile when the space is pressed

				}

			}

		}

		



			//This if statement displays the start screen, and the game has not started
			if (Settings.getGameStarted() ==  false)
			{

				window.draw(background); //draw the background
				GameUI.drawStart(window); //draw the start box
				if (gameWon)
				{
					GameUI.drawWinner(window); //draws the text of the player winning
				}
				if (gameLost)
				{
					GameUI.drawLoser(window); //draws the text of the aliens winning
				}

			}

			//the game starts here, the level should be at level one
			else if (Settings.getGameStarted() == true) // The game has started
			{
		
				//Draws the stars background
				window.draw(background);

				//draw the games
				GameUI.drawGame(window, Settings); //draw the lives counter and the enemies

				//draw the ship/move the ship
				Ship.moveShip();
				Ship.draw(window);

				//draw the enemies and move the enemies
				Enemies.moveEnemies();
				Enemies.DrawEnemies(window);
				Enemies.CheckDeleteEnemy(Missiles, Settings); //checks to see if the enemy is dead
				
				
				//draw/fire the Missiles
				Missiles.drawMissiles(window);  //draw the missiles, pass the window and the bool
				Missiles.CheckIfOffscreen(); //check to see if the missile is off the screen 
				
				//Bombs
				//do game1 bomb
				if (frameCounter == Settings.getDropRate())
				{
					Enemies.DropBomb(Bombs); //drops a bomb every drop rate, depending on level one or two
					frameCounter = 0;
				}

				Bombs.drawBombs(window); //function that draws bombs
				Bombs.CheckIfOffscreen(); //checks to see if we need to delete the bombs
				
				//sets the bool to true or false, whether or not the player has been hit by a bomb
				PlayerHit = Bombs.CheckHitPlayer(Ship); //we need to check if the bomb hits the player, so we pass the ship
				//set player hit equal to the function

				//we need to check to see if any of the enemies passes the Y value
				if (Enemies.enemyTooLow() == true || PlayerHit)
				{
					Ship.ResetShipPos(); //reset the ship position
					Settings.LoseLife(); //need to lose a life
					Enemies.resetEnemyPositions(); //need to reset the enemies positions back to the top
					Bombs.DeleteList(); //we dont want the bombs to stay
					Missiles.DeleteList(); //also resets the missiles 

				}

				//check to see if all the enemies have been killed!
				if (Enemies.getEnemyList().size() == 0 && Settings.getLevel() == 1)
				{
					Ship.ResetShipPos(); //reset the ship position
					Settings.setLevel(2); //set the level to two
					Missiles.DeleteList(); //because we dont want to accidentally shoot the level 2 enemies
					Bombs.DeleteList(); //we dont want the bombs to stay
					Enemies.createEnemies(Settings.getLevel()); //recreate the enemies
					Settings.setDropRate(60);//change the time (frames), for the drop rate
					//so it drops every second
					frameCounter = 0; //reset the frame counter

				}

				//Level 2 checks to see if the game is won
				if (Enemies.getEnemyList().size() == 0 && Settings.getLevel() == 2)
				{
					//resetting the game
					ResetGame(Enemies, Missiles, Bombs, Settings, Ship); //func call to reset the game
					frameCounter = 0; //reset the frame counter
					Settings.setGameStarted(false); //the game is now NOT started
					gameWon = true; //game was  won
					gameLost = false; //game was not lost
					//YOU WIN!
				}

				//check if GAMEOVER when lives run out
				//this function will reset the game
				if (Settings.getLives() == 0)
				{
					//resetting the game
					ResetGame(Enemies, Missiles, Bombs, Settings, Ship); //func call to reset the game
					frameCounter = 0; //reset the frame counter
					Settings.setGameStarted(false); //the game is now NOT started
					gameWon = false; //game was not won
					gameLost = true; //game was lost
					//Aliens win!

				}



			}

		// end the current frame; this makes everything that we have 
		// already "drawn" actually show up on the screen
			window.display();
			//increment the frame counter
			frameCounter++; //to count the frames, will count 60 a second
	}

	
	
	return 0;
}


//======================================================
// function name: ResetGame
// parameters: 
// EnemyList& Enemies- pass the EnemyList Object
// MissileList& Missiles- pass the MissileList Object
// BombList& Bombs- pass the BombList Object
// GameSettings& Settings- pass the GameSettings Object
// return type: none, its a void
//======================================================
void ResetGame(EnemyList& Enemies, MissileList& Missiles, BombList& Bombs, GameSettings& Settings, Ship& ship)
{
	ship.ResetShipPos(); //reset the ship position
	Enemies.DeleteList(); //delete all the enemies
	Missiles.DeleteList(); //delete all the Missiles
	Bombs.DeleteList(); //delete all the bombs
	Settings.setLives(3); //set the lives back to 3
	Settings.setLevel(1); //set the level back to one
	Enemies.createEnemies(1); //create the enemies for level 1
	Settings.setDropRate(120); //set the drop rate back to 120
	Settings.setEnemyKilled(0); //setting the enemies killed back to zero
}