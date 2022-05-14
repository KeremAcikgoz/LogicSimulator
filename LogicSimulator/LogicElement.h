#pragma once
#include "Object.h"
#include "Pin.h"

class LogicElement :
    public Object
{
protected:
    Pin pins[4]; //List of pins of the logic element
    int numPins; //Number of pins of the logic element
    sf::Vertex position;
public:
    LogicElement(sf::Vertex pos) 
    {
        sprite.setPosition(sf::Vector2f(pos.position.x, pos.position.y));
    }
    virtual void Drag(sf::Vertex new_position){
        sprite.setPosition(new_position.position);
    }

    //virtual string Texture(ObjectTypes type){
    //    string texture;
    //    switch (type)
    //    {
    //    case O_AND:
    //        texture = "../assets/AND.png";
    //        break;
    //    
    //    default:
    //        texture = "";
    //        break;
    //    }
    //    texture = "";
    //    return texture;
    //}
};


//hello