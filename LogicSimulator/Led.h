#pragma once
#ifndef LED_H
#define LED_H

#include "LogicElement.h"

class Led : public LogicElement
{
public:
    Led(sf::Vertex pos);
    ~Led();
    void LogicOperation();
};

#endif