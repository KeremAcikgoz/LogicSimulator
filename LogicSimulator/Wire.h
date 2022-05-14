#pragma once
#include "Object.h"
#include <iostream>
#include <SFML/Graphics.hpp>
//using namespace std;
class Wire : public Object
{
    sf::Vertex line[2];
public:
    Wire() {
       /* if (!textures[1].loadFromFile("../assets/AND.png"))
        {
           std::cout << "Failed to load texture !" << endl;
        }
        sprite.setPosition(sf::Vector2f(x,y));
        sprite.setTexture(textures[1]);*/

        //window->draw(sprite);
    }
    /*sf::Sprite getSprite() {
        return sprite;
    }*/
};
