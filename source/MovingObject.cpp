
#include "MovingObject.h"
#include <iostream>
#include <string>


// The constructor method
MovingObject::MovingObject(std::string ObjectPath, float xPos, float yPos)
{


      m_Texture.loadFromFile(ObjectPath);
      m_Sprite.setTexture(m_Texture);
      m_Sprite.setPosition(xPos, yPos);
      m_Active = false;

      m_StartingXPos = xPos;
      m_StartingYPos = yPos;
      srand((int)time(0) * 10);
  	  m_SpriteSpeed = (rand() % 200);
      // m_IntRect.height = rectHeigh;
      // m_IntRect.width = rectWidth;

  }

  void MovingObject::randomizeHeight()
  {
  	srand((int)time(0) );
  	float height = (rand() % 1900 ) - 100;
    float width = (rand() % 1080 ) - 100;
  	m_Sprite.setPosition(width, height);
  }

  void MovingObject::randomizeSpeed()
  {
  	srand((int)time(0) );
  	m_SpriteSpeed = (rand() % 200);
  }

  void MovingObject::moveRight()
  {
      m_Sprite.setPosition(
          m_Sprite.getPosition().x +	(m_SpriteSpeed * m_DeltaTime.asSeconds()),
  		m_Sprite.getPosition().y);
  }
  void MovingObject::moveLeft()
  {
      m_Sprite.setPosition(
          m_Sprite.getPosition().x -	(m_SpriteSpeed * m_DeltaTime.asSeconds()),
  		m_Sprite.getPosition().y);
  }
  void MovingObject::moveUp()
  {
      m_Sprite.setPosition(
          m_Sprite.getPosition().y -	(m_SpriteSpeed * m_DeltaTime.asSeconds()),
  		m_Sprite.getPosition().x);
  }
  void MovingObject::moveDown()
  {
      m_Sprite.setPosition(
          m_Sprite.getPosition().y +	(m_SpriteSpeed * m_DeltaTime.asSeconds()),
  		m_Sprite.getPosition().x);
  }


  bool MovingObject::isActive()
  {
      m_DeltaTime = m_Clock.restart();
      return m_Active;
  }

  void MovingObject::setActive(bool active)
  {
      m_Active = active;
  }

  float MovingObject::getXPos()
  {
      return m_Sprite.getPosition().x;
  }

  float MovingObject::getYPos()
  {
      return m_Sprite.getPosition().y;
  }

  sf::Sprite MovingObject::getSprite()
  {
      return m_Sprite;
  }
  sf::IntRect MovingObject::getIntRect(float rectHeigh, float rectWidth)
  {
    return m_IntRect;
  }
