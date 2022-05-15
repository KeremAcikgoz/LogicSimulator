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
    Wire(sf::Vertex start_point, Pin* start_pin, Pin* tmp_end_pin);
    ~Wire() {
        pins[0]->RemoveConnection(this);
        pins[1]->RemoveConnection(this);
        UpdatePosition(sf::Vertex(sf::Vector2f(0.f, 0.f)));
    }
    void Extend(sf::Vertex end_point);
    void ConnectWire(Pin* end_pin);
    void UpdatePosition(sf::Vertex new_position);
    sf::VertexArray GetPosition();
};
