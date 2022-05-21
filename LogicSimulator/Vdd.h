#pragma once
#ifndef VDD_H
#define VDD_H

#include "LogicElement.h"

class Vdd : public LogicElement
{
public:
    Vdd(sf::Vertex pos);
    ~Vdd();
    void LogicOperation();
};

#endif