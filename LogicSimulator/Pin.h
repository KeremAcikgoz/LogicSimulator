#pragma once
#include "Object.h"
#include <SFML/Graphics.hpp>
#include <iostream>


constexpr auto MAX_CONNECTIONS = 10;

enum pinType { INPUT, OUTPUT }; //enum for pin type (input or output pin)
enum pinState { HIGHZ, LOW, HIGH }; //enum for pin state

class Pin
{
public:

	int index; //Index of the pin for an element
	//First input pin has index 0, second pin has index 1, output pin has index 2, on�
	pinType type; //whether this pin is input or output
	bool isSrc[MAX_CONNECTIONS]; //whether this pin is the starting point the wire connected to it or the ending pointfor that wire for every connection it has
	Pin* connectedTo[MAX_CONNECTIONS]; //List of other pins this pin is connected to
	Object* wires[MAX_CONNECTIONS]; //Wires connected to this pin
	int numConnections; //Number of connections on this pin
	sf::Vector2f pos; //Screen position of the pin
	pinState state; //Logic state of the signal on this pin

	Pin();
	Pin(pinType pin_type, int pin_index, sf::Vertex position);
	//	~Pin();
	void AddConnection(Object* conn_wire);

	void RemoveConnection(Object* rem_wire);

	void DragPin(sf::Vertex new_pos);
};

//bebek		
