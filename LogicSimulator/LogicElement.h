#pragma once
#include "Object.h"
#include "Pin.h"
class LogicElement :
    public Object
{
protected:
    Pin pins[4]; //List of pins of the logic element
    int numPins; //Number of pins of the logic element
public:
    LogicElement() {
        cout << "Logic Element Created" << endl;
    }
};

//hello