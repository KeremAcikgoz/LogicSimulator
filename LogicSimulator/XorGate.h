#pragma once
#ifndef XORGATE_H
#define XORGATE_H
#include "LogicElement.h"

class XorGate : public LogicElement
{

public:
    XorGate(sf::Vertex pos);
    ~XorGate();
    void LogicOperation();

};


#endif
