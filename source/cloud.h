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

    public:
        Cloud(std::string backgroundPath, float x_pos, float y_pos, int cloudId);
        
        void randomizeHeight();
        void randomizeSpeed();
        void move();
        
        bool isActive();
        void setActive(bool active);
        
        float getXPos();
        
        sf::Sprite getSprite();
};
