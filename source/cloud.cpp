#include <sstream>
#include <dirent.h>

#include <iostream>
#include <string>
//#include <ctime.h>

#include "cloud.h"

//This is the constructor method
Cloud::Cloud(std::string backgroundPath, float x_pos, float y_pos, int cloudId)
{
    m_CloudId = cloudId;
    m_Texture.loadFromFile(backgroundPath);
    m_Sprite.setTexture(m_Texture);
    m_Sprite.setPosition(x_pos, y_pos); 
    m_Active = false;
    m_StartingYpos = y_pos;
    
    srand((int)time(0) * 10);
	m_SpriteSpeed = (rand() % 200);
    
          
}

void Cloud::randomizeHeight()
{   
	srand((int)time(0) * (m_CloudId*10));
	float height = (rand() % (m_CloudId*150)) - 100;
	m_Sprite.setPosition(-200, height);
}

void Cloud::randomizeSpeed()
{
	srand((int)time(0) * (m_CloudId * 10));
	m_SpriteSpeed = (rand() % 200);
}

void Cloud::move()
{       
    m_Sprite.setPosition(
        m_Sprite.getPosition().x +	(m_SpriteSpeed * dt.asSeconds()),
		m_Sprite.getPosition().y);
}

bool Cloud::isActive()
{
    dt = clock.restart(); 
    return m_Active;
}

void Cloud::setActive(bool active)
{
    m_Active = active; 
}

float Cloud::getXPos()
{
    return m_Sprite.getPosition().x;
}

sf::Sprite Cloud::getSprite()
{
    return m_Sprite;    
}

















