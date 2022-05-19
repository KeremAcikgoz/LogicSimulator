#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
using namespace std;

enum ObjectTypes { O_NULL, O_AND, O_OR, O_XOR, O_NOT, O_LED, O_Vdd, O_GND, O_Dff, O_WIRE };

class Object
{
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
    ObjectTypes TypeId;
    bool isSource;
    Object() {
        //window = window
        //textures = textures
        locked = false;
        next = NULL;
        selected = false;
        state = false;
        moving = false;
        isSource = false;
        //TypeId = O_AND;

    }
    virtual ~Object() {
         cout << "Object Destructor called" << endl;
    }
    virtual bool getState() {
        return state;
    }
    virtual bool IsLocked() {
        return locked;
    }
    virtual bool IsSelected() {
        return selected;
    }
    virtual sf::Sprite getSprite() {
        return sprite;
    }
    virtual void SetSelected(bool isSelected) {
        selected = isSelected;
    }
    virtual void UpdatePosition(sf::Vertex new_position) = 0;
    virtual bool DoesContain(sf::Vector2f mPos) {
        return sprite.getGlobalBounds().contains(mPos);
    }
    virtual sf::VertexArray GetPosition() = 0;

};
