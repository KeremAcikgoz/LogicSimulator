#pragma once
#ifndef NOTGATE_H
#define NOTGATE_H

#include "LogicElement.h"

class NotGate : public LogicElement
{
public:
    NotGate(sf::Vertex pos);
    ~NotGate();
    void LogicOperation();
};

#endif