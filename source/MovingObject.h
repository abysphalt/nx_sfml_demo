#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class MovingObject
{
private:
  int m_ID;
  sf::Texture m_Texture;
  sf::IntRect m_IntRect;
  sf::Sprite m_Sprite;

  float m_StartingXPos;
  float m_StartingYPos;

  float m_SpriteSpeed = 0.0f;

  bool m_Active;

  sf::Clock m_Clock;
  sf::Time m_DeltaTime;

public:
  MovingObject(std::string ObjectPath, float xPos, float yPos);

  sf::Time restartTime();
  void randomizeHeight();
  void randomizeSpeed();

  void moveLeft();
  void moveRight();
  void moveUp();
  void moveDown();

  void stopLeft();
  void stopRight();
  void stopUp();
  void stopDown();

  bool isActive();
  void setActive(bool active);

  float getXPos();
  float getYPos();

  sf::Sprite getSprite();
  sf::IntRect getIntRect(float rectHeigh, float rectWidth);

};
