#pragma once
#ifndef GND_H
#define GND_H

#include "LogicElement.h"

class Gnd : public LogicElement
{
public:
    Gnd(sf::Vertex pos);
    ~Gnd();
    void LogicOperation();
};

#endif