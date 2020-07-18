#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

//using namespace sf;

class Cloud
{
private:
    int m_CloudId;
    sf::Texture m_Texture;
    sf::Sprite m_Sprite;

    float m_StartingYpos;

    float m_SpriteSpeed = 0.0f;

    bool m_Active;

    sf::Clock clock;
    sf::Time dt;


    //float m_Speed = 1300.0f;
    //float m_DirectionX = .2f;
    //float m_DirectionY = .2f;

public:
    Cloud(std::string backgroundPath, float x_pos, float y_pos, int cloudId);

    void randomizeHeight();
    void randomizeSpeed();
    void move();

    bool isActive();
    void setActive(bool active);

    float getXPos();

    sf::Sprite getSprite();


    //Ball(float startX,float startY);

    //sf::FloatRect getPosition();

    //sf::RectangleShape getShape();

    //float getXVelocity();
    // float getYVelocity();



    //void resetSpeed();

    //void update(Time dt);
};
