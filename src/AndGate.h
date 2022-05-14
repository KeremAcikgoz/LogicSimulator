#pragma once
#ifndef ANDGATE_H
#define ANDGATE_H

#include "LogicElement.h"

class AndGate :
    public LogicElement
{
public:
    AndGate(sf::Vertex pos) : LogicElement(pos) {
        
        numPins = 3;
        TypeId = O_AND;
    };

};

#endif