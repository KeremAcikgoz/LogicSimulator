#pragma once
#include "Button.h"
#include <iostream>
using namespace std;

class StopButton :
    public Button
{
public:
    //bool clickedStop = sf::Mouse::isButtonPressed(sf::Mouse::Left);
    StopButton(sf::Vector2f pos) {
        if (!texture.loadFromFile("../assets/STOP.png"))
        {
            cout << "Failed to load texture !" << endl;
        }
        sprite.setTexture(texture);
        sprite.setPosition(pos);
    }
    bool checkClick(sf::Vector2f mousePos) {
       if (mousePos.x > sprite.getPosition().x && mousePos.x < (sprite.getPosition().x + sprite.getGlobalBounds().width)) {
            if (mousePos.y > sprite.getPosition().y && mousePos.y < (sprite.getPosition().y + sprite.getGlobalBounds().height)) {
                current = true;
            }
       }
        return current;
    }
};

