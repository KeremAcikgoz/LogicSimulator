#pragma once
#include "LogicElement.h"
#include "utils.h"
class AndGate :
    public LogicElement
{
public:
    AndGate(sf::Vertex pos) : LogicElement(pos) {
        
        numPins = 3;
        TypeId = O_AND;
    };

};