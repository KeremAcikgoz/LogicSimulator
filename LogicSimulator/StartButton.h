#pragma once
#include "Button.h"
#include <iostream>
using namespace std;

class StartButton :
    public Button
{
public:
    /*bool clicked = sf::Mouse::isButtonPressed(sf::Mouse::Left);*/
    StartButton(sf::Vector2f pos) {
        if (!texture.loadFromFile("../assets/START.png"))
        {
            cout << "Failed to load texture !" << endl;
        }
        sprite.setTexture(texture);
        sprite.setPosition(pos);
    }
    bool checkClick(sf::Vector2f mousePos) {
        if (mousePos.x > sprite.getPosition().x && mousePos.x < (sprite.getPosition().x + sprite.getGlobalBounds().width)) {
            if (mousePos.y > sprite.getPosition().y && mousePos.y < (sprite.getPosition().y + sprite.getGlobalBounds().height)) {
                if (current == false) {
                    current = true;
                }
                else {
                    current = false;
                }
            }
        }
        return current;
    }
};

