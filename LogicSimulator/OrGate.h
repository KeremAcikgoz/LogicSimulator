#pragma once
#ifndef ORGATE_H
#define ORGATE_H

#include "LogicElement.h"

class OrGate : public LogicElement
{
public:
    OrGate(sf::Vertex pos);
    ~OrGate();
    void LogicOperation();
};

#endif