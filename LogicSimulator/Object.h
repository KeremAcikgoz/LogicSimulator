#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class Object {
protected:
    bool locked;
    bool state;
    bool selected;
    sf::Texture textures[2];
    bool moving;
public:
    sf::RenderWindow window;
    Object* next;
    sf::Sprite sprite;
    Object() {
        //window = window;
        //textures = textures
        locked = false;
        next = NULL;
        selected = false;
        state = false;
        moving = false;
    }
    ~Object() {
        cout << "Object Destructor called" << endl;
    }
    /*sf::RenderWindow getWindow() {
        return *window;
    }*/
    bool getState() {
        return state;
    }
    bool IsLocked() {
        return locked;
    }
    bool IsSelected() {
        return selected;
    }
    sf::Sprite getSprite() {
        return sprite;
    }
    void move(bool movingAnElement)
    {
        sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        if (this->moving)
        {
            this->sprite.setPosition(mousePosition.x - this->sprite.getGlobalBounds().width / 2, mousePosition.y - this->sprite.getGlobalBounds().height / 2);
            if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                this->moving = false;
                movingAnElement = false;
            }
        }
        else
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && mousePosition.x > this->sprite.getPosition().x &&
                mousePosition.y > this->sprite.getPosition().y && mousePosition.x < this->sprite.getPosition().x + this->sprite.getGlobalBounds().width &&
                mousePosition.y < this->sprite.getPosition().y + this->sprite.getGlobalBounds().height && !movingAnElement)
            {
                this->moving = true;
                movingAnElement = true;
            }
        }
        //const Object& operator[](int i) const {
        //    if (i < 0) {
        //        cerr << "Index out of range!" << endl;
        //        return;
        //    }
        //    
        //    return [i];

        //}
    };


};