#pragma once
#include "Object.h"
#include <iostream>
#include "Pin.h"
#include <SFML/Graphics.hpp>
using namespace std;
class Wire : public Object
{
    Pin* pins[2];
    sf::Vertex line[2];
    
public:
    Wire(sf::Vertex start_point, Pin start_pin) {
        line[0] = start_point;
        line[1] = start_point;
        pins[0] = &start_pin;
        pins[1] = NULL;
    }
    void Extend(sf::Vertex end_point){
        line[1] = end_point;
    }
    void ConnectWire(Pin end_pin){
        pins[1] = &end_pin;
    }

};
