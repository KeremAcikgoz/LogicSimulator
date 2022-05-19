#include "Wire.h"
#include "Object.h"
#include <iostream>
#include "Pin.h"
#include <SFML/Graphics.hpp>
using namespace std;

Wire::Wire(sf::Vertex start_point, Pin* start_pin, Pin* tmp_end_pin) {
	line[0] = start_point;
	line[1] = start_point;
	pins[0] = start_pin;
	pins[1] = tmp_end_pin;
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

void Wire::Extend(sf::Vertex end_point) {
	line[1] = end_point;
}
void Wire::ConnectWire(Pin* end_pin) {
	pins[1]->RemoveConnection(this);
	pins[1] = end_pin;
	pins[1]->AddConnection(this);
	this->UpdatePosition(sf::Vertex(pins[0]->pos));
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

Pin* Wire::GetFirstPin() {
	return pins[0];
}