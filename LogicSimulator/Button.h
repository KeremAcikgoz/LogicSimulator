#include <SFML/Graphics.hpp>
#include <string>

#pragma once

using namespace std;


class Button {
protected:
    sf::Sprite sprite;
    sf::Text text;
    sf::Texture texture;
public:
  
    bool current;
    //bool getVar();
    //sf::Sprite* getSprite();
    virtual bool checkClick(sf::Vector2f mousePos) {
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

    Button() {
        current = false;
    }

    virtual sf::Sprite getSprite() {
        return sprite;
    }

};

