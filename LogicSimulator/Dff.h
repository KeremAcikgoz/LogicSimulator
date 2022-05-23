#pragma once
#ifndef DFF_H
#define DFF_H
#include "LogicElement.h"

class Dff : public LogicElement
{

    bool isClockOn = false;
public:
    Dff(sf::Vertex pos);
    ~Dff();
    void LogicOperation();

};


#endif
