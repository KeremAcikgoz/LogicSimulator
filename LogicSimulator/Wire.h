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
    //Wire();
    Wire(sf::Vertex start_point, Pin* start_pin, Pin* tmp_end_pin);
    ~Wire();
    void Extend(sf::Vertex end_point);
    void ConnectWire(Pin* end_pin);
    void UpdatePosition(sf::Vertex new_position);
    sf::VertexArray GetPosition();
    Pin* GetFirstPin();
};
