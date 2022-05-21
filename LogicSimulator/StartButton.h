#pragma once
#include "Button.h"
#include <iostream>
using namespace std;

class StartButton :
    public Button
{
public:
    StartButton(sf::Vector2f pos) {
        if (!texture.loadFromFile("../assets/START.png"))
        {
            cout << "Failed to load texture !" << endl;
        }
        sprite.setTexture(texture);
        sprite.setPosition(pos);
    }
};

