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
    bool is_connected[2] = {false, false};
public:
    //Wire();
    Wire(sf::Vertex start_point, Pin* start_pin, Pin* tmp_end_pin);
    ~Wire();
    void Extend(sf::Vertex end_point);
    void ConnectWire(Pin* end_pin);
    void UpdatePosition(sf::Vertex new_position);
    sf::VertexArray GetPosition();
    Pin* GetPin(int i);
    void LogicOperation();
    bool IsConnected(int i); 
    bool DoesContain(sf::Vector2f mPos) {
        bool ret = false;
        sf::VertexArray lines = this->GetPosition();
        if (lines.getBounds().contains(mPos) && IsClose(Slope(line[0].position, mPos), Slope(mPos, line[1].position), 2.f)) {
            ret = true;
        }
        lines[0];
        return ret;
    }
    float Slope(sf::Vector2f v1, sf::Vector2f v2) {
        return (v1.y - v2.y) / (v1.x - (v2.x));
    }
    bool IsClose(float f1, float f2, float epsilon) {
        return abs(f1 - f2) < epsilon;
    }
};
