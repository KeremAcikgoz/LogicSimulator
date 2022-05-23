#pragma once
#ifndef CLOCK_H
#define CLOCK_H
#include "LogicElement.h"

class Clock : public LogicElement
{

public:
    Clock(sf::Vertex pos);
    ~Clock();
    void LogicOperation();
    sf::Clock clock;
};


#endif
