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
    void checkClick(sf::Vector2f mousePos) {
        if (mousePos.x > sprite.getPosition().x && mousePos.x < (sprite.getPosition().x + sprite.getGlobalBounds().width)) {
            if (mousePos.y > sprite.getPosition().y && mousePos.y < (sprite.getPosition().y + sprite.getGlobalBounds().height)) {
                current = true;
            }
        }
    }

    Button() {
        current = false;
    }

    virtual sf::Sprite getSprite() {
        return sprite;
    }

};

