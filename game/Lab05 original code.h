#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;

// note: a Sprite represents an image on screen. A sprite knows and remembers its own position
// ship.move(offsetX, offsetY) adds offsetX, offsetY to 
// the current position of the ship. 
// x is horizontal, y is vertical. 
// 0,0 is in the UPPER LEFT of the screen, y increases DOWN the screen
void moveShip(Sprite& ship)
{
	const float DISTANCE = 5.0f;

	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		// left arrow is pressed: move our ship left 5 pixels
		// 2nd parm is y direction. We don't want to move up/down, so it's zero.
		if (!(ship.getPosition().x <= 0))
		{
			ship.move(-DISTANCE, 0);
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		// right arrow is pressed: move our ship right 5 pixels
		if (!(ship.getPosition().x >= 775))
		{
			ship.move(DISTANCE, 0);
		}


	}
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		// right arrow is pressed: move our ship right 5 pixels
		if (!(ship.getPosition().y <= 480))
		{
			if (!(ship.getPosition().y <= 0))
			{
				ship.move(0, -DISTANCE);
			}
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		// right arrow is pressed: move our ship right 5 pixels
		if (!(ship.getPosition().y >= 575))
		{
			ship.move(0, DISTANCE);
		}

	}
}


void moveEnemy(Sprite& enemy, bool &checkWall)
{
	const float DISTANCE = 5.0f;

	if (!checkWall)
	{
		if ((enemy.getPosition().x + 50) >= 800)
		{

			checkWall = true;
		}
		else
		{
			enemy.move(DISTANCE, 0);
		}
	}
	else if (checkWall)
	{
		if ((enemy.getPosition().x) <= 0)
		{
			checkWall = false;
		}
		else
		{
			enemy.move(-DISTANCE, 0);
		}
	}

}

int main()
{
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;
	int hitcount = 0;
	bool hit = false;
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "aliens!");
	// Limit the framerate to 60 frames per second
	window.setFramerateLimit(60);

	// load textures from file into memory. This doesn't display anything yet.
	// Notice we do this *before* going into animation loop.
	Texture shipTexture;
	if (!shipTexture.loadFromFile("ship.png"))
	{
		cout << "Unable to load ship texture!" << endl;
		exit(EXIT_FAILURE);
	}
	Texture starsTexture;
	if (!starsTexture.loadFromFile("stars.jpg"))
	{
		cout << "Unable to load stars texture!" << endl;
		exit(EXIT_FAILURE);
	}
	//*** add code to load the texture for the missile
	Texture missileTexture;
	if (!missileTexture.loadFromFile("missile.png"))
	{
		cout << "Unable to load missile texture!" << endl;
		exit(EXIT_FAILURE);
	}
	Texture enemyTexture;
	if (!enemyTexture.loadFromFile("enemy.png"))
	{
		cout << "Unable to load enemy texture!" << endl;
		exit(EXIT_FAILURE);
	}


	// A sprite is a thing we can draw and manipulate on the screen.
	// We have to give it a "texture" to specify what it looks like

	Sprite background;
	background.setTexture(starsTexture);
	// The texture file is 640x480, so scale it up a little to cover 800x600 window
	background.setScale(1.5, 1.5);

	// create sprite and texture it
	Sprite ship;
	ship.setTexture(shipTexture);

	// *** add code to set texture for the missile
	// create sprite and texture it
	Sprite missile;
	missile.setTexture(missileTexture);

	Sprite enemy;
	enemy.setTexture(enemyTexture);

	// initial position of the ship will be approx middle of screen
	float shipX = window.getSize().x / 2.0f;
	float shipY = window.getSize().y / 1.1f;
	ship.setPosition(shipX, shipY);

	float enemyX = window.getSize().x / 2.0f;
	float enemyY = window.getSize().y / 9.0f;
	enemy.setPosition(enemyX, enemyY);

	bool isMissileInFlight = false;
	//just checking to do mutliple missiles

	bool checkWall = false;


	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		// For now, we just need this so we can click on the window and close it
		Event event;

		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == Event::Closed)
				window.close();
			else if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Space && !isMissileInFlight)
				{
					isMissileInFlight = true;
					// ***Add code to initialize missile position
					Vector2f pos = ship.getPosition();

					missile.setPosition(pos.x, pos.y);

				}
			}
		}

		//===========================================================
		// Everything from here to the end of the loop is where you put your
		// code to produce ONE frame of the animation. The next iteration of the loop will
		// render the next frame, and so on. All this happens ~ 60 times/second.
		//===========================================================

		// draw background first, so everything that's drawn later 
		// will appear on top of background
		window.draw(background);

		//detect key presses to update the position of the ship. 
		//See moveShip() function above.
		moveShip(ship);
		/*missile.move(0, -5);*/  //wrong?
		// draw the ship on top of background 
		// (the ship from previous frame was erased when we drew background)
		window.draw(ship);

		window.draw(enemy);


		moveEnemy(enemy, checkWall);
		//checkwall


			//check for hit


		if (isMissileInFlight)
		{
			// ***code goes here to handle a missile in flight
			// don't forget to turn the flag off when the missile goes off screen!
			if (missile.getPosition().y > 0)
			{
				window.draw(missile);
				missile.move(0, -20);
			}
			else
			{
				isMissileInFlight = false;
			}
		}
		FloatRect missileBounds = missile.getGlobalBounds();
		FloatRect enemyBounds = enemy.getGlobalBounds();
		if (missileBounds.intersects(enemyBounds))
		{
			hit = true;
			missile.setPosition(200, 0); //sets the position to get away from the enemy sprites
		}

		if (hit)
		{
			cout << "Enemy Hit!" << endl;
			hitcount++;
			cout << "hitcount: " << hitcount << endl;
			hit = false;
		}




		// end the current frame; this makes everything that we have 
		// already "drawn" actually show up on the screen
		window.display();


		// At this point the frame we have built is now visible on screen.
		// Now control will go back to the top of the animation loop
		// to build the next frame. Since we begin by drawing the
		// background, each frame is rebuilt from scratch.

	} // end body of animation loop

	return 0;
}
