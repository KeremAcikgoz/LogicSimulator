#pragma once
#include "Button.h"
#include <iostream>
using namespace std;

class StopButton :
    public Button
{
public:
    StopButton(sf::Vector2f pos) {
        if (!texture.loadFromFile("../assets/STOP.png"))
        {
            cout << "Failed to load texture !" << endl;
        }
        sprite.setTexture(texture);
        sprite.setPosition(pos);
    }
};

