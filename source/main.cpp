// Include important C++ libraries here
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
//#include <switch.h>
#include <dirent.h>
#include <stdint.h>
#include <cstdio>
#include <stdint.h>

#include "cloud.cpp"

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





//    //gnome image
//    sf::Image gnomeImage;
//	gnomeImage.loadFromFile("romfs/gnome.png");
//	const sf::Uint8* gnomeImagePtr = gnomeImage.getPixelsPtr(); 
//	sf::Texture gnomeTexture;
//	gnomeTexture.create(378, 328);
//	int pos = 0; // add 1 until 9 
//	std::cout<<"hello";
//	gnomeTexture.update(gnomeImagePtr, 38, 41, 0, 287);
//	
//	
//	sf::Sprite gnomeSprite;
//	gnomeSprite.setTexture(gnomeTexture);
//	gnomeSprite.setPosition(400, 400);
//	//gnomeTexture.update(gnomeImagePtr, 38, 41, (38 * pos), 287);



    bool gnomeActive = false;
    float gnomeSpeed = 0.0f;
    sf::IntRect gnomeRect(0,(328.0f-37.8f),36.5,41);
    
    sf::Texture gnomeTexture;
    gnomeTexture.loadFromFile("romfs/gnome.png");
    
    sf::Sprite gnomeSprite;
    gnomeSprite.setTexture(gnomeTexture);
    gnomeSprite.setTextureRect(gnomeRect);
    gnomeSprite.setPosition(256,256);
    //changing gnomeRect should change the image in sprite? 
    

    




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
    

	
	

	// make 3 cloud sprites from 1 texture
	sf::Texture textureCloud;

	// Load 1 new texture
	textureCloud.loadFromFile("romfs/cloud.png");

	// 3 New sprites withe the same texture
	sf::Sprite spriteCloud1;
	sf::Sprite spriteCloud2;
	sf::Sprite spriteCloud3;
	spriteCloud1.setTexture(textureCloud);
	spriteCloud2.setTexture(textureCloud);
	spriteCloud3.setTexture(textureCloud);

	// Position the clouds off screen
	spriteCloud1.setPosition(0, 0);
	spriteCloud2.setPosition(0, 150);
	spriteCloud3.setPosition(0, 300);

	// Are the clouds currently on screen?
	bool cloud1Active = false;
	bool cloud2Active = false;
	bool cloud3Active = false;

	// How fast is each cloud?
	float cloud1Speed = 0.0f;
	float cloud2Speed = 0.0f;
	float cloud3Speed = 0.0f;

	// Variables to control time itself
	sf::Clock clock;
	sf::Clock gnomeClock;
	sf::Time gnomeTime = clock.restart();

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
		    if (sf::Joystick::isButtonPressed(0,0) || 
		        sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) ||
		        event.type == sf::Event::Closed)
		    {
			    window.close();
		    }
		    
		    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
		    {
		        gnomeSprite.setPosition(gnomeSprite.getPosition().x - 10, gnomeSprite.getPosition().y);
		        if (gnomeSprite.getPosition().x < 0) 
		        {
		            gnomeSprite.setPosition(1900, gnomeSprite.getPosition().y);
		        }
		        gnomeRect.width = -abs(gnomeRect.width);
		    }
		    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
		    {
		        gnomeSprite.setPosition(gnomeSprite.getPosition().x + 10, gnomeSprite.getPosition().y);
		        if (gnomeSprite.getPosition().x > 1900) 
		        {
		            gnomeSprite.setPosition(0, gnomeSprite.getPosition().y);
		        }
		        gnomeRect.width = abs(gnomeRect.width);
		    }
	    }

		/*
		****************************************
		Update the scene
		****************************************
		*/
		// Measure time
		sf::Time dt = clock.restart();
		
		if (gnomeClock.getElapsedTime().asSeconds() > 0.15f) 
		{
		    if (gnomeRect.left >= (378 - 41)) 
		    {
		        gnomeRect.left = 0;
		    }
		    else
		    {
		        gnomeRect.left += 38.1f;
		    }		    
		    gnomeSprite.setTextureRect(gnomeRect);
		    gnomeTime = gnomeClock.restart();
		} 
		

//		if (!gnomeActive)
//		{
//			srand((int)time(0) * 10);
//			gnomeSpeed = (rand() % 200) + 200;
//
//			gnomeSprite.setPosition(0, 200);
//			gnomeActive = true;
//		}
//		else
//		{
//            
//			gnomeSprite.setPosition(gnomeSprite.getPosition().x + 1, gnomeSprite.getPosition().y);
//
//			// Has the bee reached the right hand edge of the screen?
//			if (gnomeSprite.getPosition().x > 1900)
//			{
//				// Set it up ready to be a whole new bee next frame
//				gnomeActive = false;
//				//goLeft = true;
//				
//				
//				gnomeRect.width = -gnomeRect.width;
//			}
//		}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		

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

		// Manage the clouds
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
		
		
		
		
		
		// Cloud 1
		if (!cloud1Active)
		{

			// How fast is the cloud
			srand((int)time(0) * 10);
			cloud1Speed = (rand() % 200);

			// How high is the cloud
			srand((int)time(0) * 10);
			float height = (rand() % 150);
			spriteCloud1.setPosition(-200, height);
			cloud1Active = true;


		}
		else
		{

			spriteCloud1.setPosition( spriteCloud1.getPosition().x + (cloud1Speed * dt.asSeconds()), spriteCloud1.getPosition().y);

			// Has the cloud reached the right hand edge of the screen?
			if (spriteCloud1.getPosition().x > 1920)
			{
				// Set it up ready to be a whole new cloud next frame
				cloud1Active = false;
			}
		}
		// Cloud 2
		if (!cloud2Active)
		{

			// How fast is the cloud
			srand((int)time(0) * 20);
			cloud2Speed = (rand() % 200);

			// How high is the cloud
			srand((int)time(0) * 20);
			float height = (rand() % 300) - 150;
			spriteCloud2.setPosition(-200, height);
			cloud2Active = true;


		}
		else
		{

			spriteCloud2.setPosition(
				spriteCloud2.getPosition().x +
				(cloud2Speed * dt.asSeconds()),
				spriteCloud2.getPosition().y);

			// Has the cloud reached the right hand edge of the screen?
			if (spriteCloud2.getPosition().x > 1920)
			{
				// Set it up ready to be a whole new cloud next frame
				cloud2Active = false;
			}
		}

		if (!cloud3Active)
		{

			// How fast is the cloud
			srand((int)time(0) * 30);
			cloud3Speed = (rand() % 200);

			// How high is the cloud
			srand((int)time(0) * 30);
			float height = (rand() % 450) - 150;
			spriteCloud3.setPosition(-200, height);
			cloud3Active = true;


		}
		else
		{

			spriteCloud3.setPosition(
				spriteCloud3.getPosition().x +
				(cloud3Speed * dt.asSeconds()),
				spriteCloud3.getPosition().y);

			// Has the cloud reached the right hand edge of the screen?
			if (spriteCloud3.getPosition().x > 1920)
			{
				// Set it up ready to be a whole new cloud next frame
				cloud3Active = false;
			}
		}



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
//		window.draw(spriteCloud1);
//		window.draw(spriteCloud2);
//		window.draw(spriteCloud3);

        window.draw(cloud1.getSprite());
        window.draw(cloud2.getSprite());
        window.draw(cloud3.getSprite());
        
        

		// Draw the tree
		window.draw(spriteTree);

		// Drawraw the insect
		window.draw(spriteBee);
		
		gnomeSprite.setScale(3, 3);
		window.draw(gnomeSprite);

		// Show everything we just drew
		window.display();


	}

	return 0;
}
