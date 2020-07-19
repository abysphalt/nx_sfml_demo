// Include important C++ libraries here
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
////#include <switch.h>
//#include <dirent.h>


#include "cloud.cpp"
#include "MovingObject.cpp"

// Define the switch resolution here we are using the switch's fullscreen
const int WIDTH = 1920;
const int HEIGTH = 1080;



extern int main()
{
	// Setup NXLink and Nintento swith related function.
	//    socketInitializeDefault();
	//    nxlinkStdio();
	//    Result rc = romfsInit();


	// Create a video mode object
	sf::VideoMode vm(WIDTH, HEIGTH);

	// Create and open a window for the game
	sf::RenderWindow window(vm, "Timber!!!");

	// Create a texture to hold a graphic on the GPU
	sf::Texture textureBackground;
	textureBackground.loadFromFile("romfs/background.png");
	sf::Sprite spriteBackground;
	spriteBackground.setTexture(textureBackground);
	spriteBackground.setPosition(0, 0);


	// Make a tree sprite
	sf::Texture textureTree;
	textureTree.loadFromFile("romfs/tree.png");
	sf::Sprite spriteTree;
	spriteTree.setTexture(textureTree);
	spriteTree.setPosition(810, 0);

	// Prepare the bee
	sf::Texture textureBee;
	textureBee.loadFromFile("romfs/bee.png");
	sf::Sprite spriteBee;
	spriteBee.setTexture(textureBee);
	spriteBee.setPosition(0, 800);

	// Is the bee currently moving?
	bool beeActive = false;

	// How fast can the bee fly
	float beeSpeed = 0.0f;



	Cloud cloud1("romfs/cloud.png", 0, 150, 1);
  Cloud cloud2("romfs/cloud.png", 0, 300, 2);
  Cloud cloud3("romfs/cloud.png", 0, 450, 3);


	MovingObject player1("romfs/player.png",800,800);



	// Variables to control time itself
	sf::Clock clock;

	// Pause the Game
	bool mainMenu = true;

	while (window.isOpen())
	{

		/*
		****************************************
		Handle the players input
		****************************************
		*/
		sf::Event event;
		while (window.pollEvent(event))
		{
		    if (sf::Joystick::isButtonPressed(0,8) ||
		        sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) ||
		        event.type == sf::Event::Closed)
		    {
			    window.close();
		    }

	    }
			if (sf::Joystick::isButtonPressed(0,9) ||
					sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
					{
						mainMenu = false;
					}

		/*
		****************************************
		Update the scene
		****************************************
		*/
		// Measure time
		if (!mainMenu)
		{
			sf::Time dt = clock.restart();

			// Setup the bee
			if (!beeActive)
			{

				// How fast is the bee
				srand((int)time(0) * 10);
				beeSpeed = (rand() % 200) + 200;

				// How high is the bee
				srand((int)time(0) * 10);
				float height = (rand() % 500) + 500;
				spriteBee.setPosition(2000, height);
				beeActive = true;

			}
			else
				// Move the bee on the Y axis
			{

				spriteBee.setPosition( spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()), spriteBee.getPosition().y);

				// Has the bee reached the right hand edge of the screen?
				if (spriteBee.getPosition().x < -100)
				{
					// Set it up ready to be a whole new bee next frame
					beeActive = false;
				}
			}

			// Manage the clouds class
			if (!cloud1.isActive())
			{
			    cloud1.randomizeHeight();
			    cloud1.randomizeSpeed();
			    cloud1.setActive(true);
			}
			else
			{
			    cloud1.move();
			    if (cloud1.getXPos() > 1920)
				{
					// Set it up ready to be a whole new cloud next frame
					cloud1.setActive(false);
				}
			}
			if (!cloud2.isActive())
			{
			    cloud2.randomizeHeight();
			    cloud2.randomizeSpeed();
			    cloud2.setActive(true);
			}
			else
			{
			    cloud2.move();
			    if (cloud2.getXPos() > 1920)
				{
					// Set it up ready to be a whole new cloud next frame
					cloud2.setActive(false);
				};
			}
			if (!cloud3.isActive())
			{
			    cloud3.randomizeHeight();
			    cloud3.randomizeSpeed();
			    cloud3.setActive(true);
			}
			else
			{
			    cloud3.move();
			    if (cloud3.getXPos() > 1920)
				{
					// Set it up ready to be a whole new cloud next frame
					cloud3.setActive(false);
				}
			}


			if (!player1.isActive())
			{
					player1.randomizeHeight();
					player1.randomizeSpeed();
					player1.setActive(true);
			}
			else
			{
					player1.moveDown();
					if (player1.getYPos() < 0)
				{
					// Set it up ready to be a whole new cloud next frame
					player1.setActive(false);

				}
			}



			}//end main menu
			/*
			****************************************
			Draw the scene
			****************************************
			*/

			// Clear everything from the last frame
			window.clear();

			// Draw our game scene here
			window.draw(spriteBackground);

			// Draw the clouds


			window.draw(cloud1.getSprite());
	    window.draw(cloud2.getSprite());
	    window.draw(cloud3.getSprite());

			// Draw the tree
			window.draw(spriteTree);

			// Drawraw the insect
			window.draw(spriteBee);

			window.draw(player1.getSprite());

			// Show everything we just drew
			window.display();


		}


	return 0;
}
