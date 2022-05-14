#pragma once
#ifndef ANDGATE_H
#define ANDGATE_H

#include "LogicElement.h"

class AndGate :
    public LogicElement
{
public:
    AndGate(sf::Vertex pos) : LogicElement(pos) {
        if (!textures[1].loadFromFile("../assets/AND.png"))
        {
            cout << "Failed to load texture !" << endl;
        }
        sprite.setTexture(textures[1]);
        numPins = 3;
        TypeId = O_AND;
    };

};

#endif