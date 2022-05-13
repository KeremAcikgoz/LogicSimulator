#pragma once
#include "LogicElement.h"
class AndGate :
    public LogicElement
{
public:
    AndGate(float x, float y) {
        if (!textures[1].loadFromFile("../assets/AND.png"))
        {
            cout << "Failed to load texture !" << endl;
        }
        sprite.setPosition(sf::Vector2f(x, y));
        sprite.setTexture(textures[1]);

        numPins = 3;
    };

};