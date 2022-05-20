#include "Wire.h"
#include "Object.h"
#include <iostream>
#include "Pin.h"
#include <SFML/Graphics.hpp>
using namespace std;

Wire::Wire(sf::Vertex start_point, Pin* start_pin, Pin* tmp_end_pin) {
	line[0] = start_point;
	line[1] = start_point;
	if (start_pin->type == INPUT) {
		pins[0] = start_pin;
		pins[1] = tmp_end_pin;
		is_connected[0] = true;
	}
	else {
		pins[0] = tmp_end_pin;
		pins[1] = start_pin;
		is_connected[1] = true;
	}
	start_pin->AddConnection(this);
	tmp_end_pin->AddConnection(this);
	TypeId = O_WIRE;
	UpdatePosition(start_point);
	cout << "Wire created" << endl;
}

Wire::~Wire() {
	pins[0]->RemoveConnection(this);
	pins[1]->RemoveConnection(this);
	//delete[] pins;
	//delete[] line;
	UpdatePosition(sf::Vertex(sf::Vector2f(0.f, 0.f)));
	cout << "wire destructed" << endl;
}

void Wire::ConnectWire(Pin* end_pin) {
	
	if (end_pin->type == INPUT) {
		pins[0]->RemoveConnection(this);
		pins[0] = end_pin;
		pins[0]->AddConnection(this);
		is_connected[0] = true;
	}
	else {
		is_connected[1] = true;
		pins[1]->RemoveConnection(this);
		pins[1] = end_pin;
		pins[1]->AddConnection(this);
	}
	
	this->UpdatePosition(pins[0]->pos);
}

void Wire::UpdatePosition(sf::Vertex new_position) { 
	//I dont need new_position
	line[0] = sf::Vertex(pins[0]->pos);
	line[1] = sf::Vertex(pins[1]->pos);
}

sf::VertexArray Wire::GetPosition() {
	sf::VertexArray lines(sf::LinesStrip, 2);
	lines[0].position = line[0].position;
	lines[1].position = line[1].position;
	return lines;
}

Pin* Wire::GetPin(int i) {
	return pins[i];
}

void Wire::LogicOperation() {
	this->pins[1]->state = this->pins[0]->state;
	return;
}

bool Wire::IsConnected(int i) {
	return is_connected[i];
}