#pragma once
#include "Object.h"
#include "Pin.h"
#include <SFML/Graphics.hpp>
using namespace std;
class LogicElement : public Object
{
protected:
    Pin pins[4]; //List of pins of the logic element
    int numPins = 0; //Number of pins of the logic element
    sf::Vertex position;
    sf::Vertex relativePinLocations[4];
    sf::Vector2f RoughSize = sf::Vector2f(10, 10);
public:
    LogicElement(sf::Vertex pos);
    virtual ~LogicElement();
    void UpdatePosition(sf::Vertex new_position);
    Pin* DoesTouchPins(sf::Vector2f mPos, bool* isTrue);
    sf::VertexArray GetPosition();
    bool DoesContainPin(Pin* pin);
    Pin* GetPin(int i);
    

};


//hello
