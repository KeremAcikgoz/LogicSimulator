#pragma once
#include "Object.h"
#include "Pin.h"
#include "utils.h"
class LogicElement :
    public Object
{
protected:
    Pin pins[4]; //List of pins of the logic element
    int numPins; //Number of pins of the logic element
    sf::Vertex position;
public:
    LogicElement(sf::Vertex pos) {
        if (!textures[1].loadFromFile(Texture(this->TypeId)))
        {
            cout << "Failed to load texture !" << endl;
        }
        sprite.setPosition(sf::Vector2f(pos.position.x, pos.position.y));
        sprite.setTexture(textures[1]);
    }
    void Drag(sf::Vertex new_position){
        sprite.setPosition(new_position.position);
    }
};

//hello