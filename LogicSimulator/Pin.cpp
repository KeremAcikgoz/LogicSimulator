#include "Pin.h"
#include "Object.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Wire.h"

Pin::Pin() {
	type = INPUT;
	state = HIGHZ;
	index = 0;
	numConnections = 0;
}
Pin::Pin(pinType pin_type, int pin_index, sf::Vertex position) {
	type = pin_type;
	state = HIGHZ;
	index = pin_index;
	pos = position.position;
	numConnections = 0;
	return;
}
Pin::~Pin(){
	cout << "pin destructor called" << endl;
}

void Pin::AddConnection(Object* conn_wire) {
	wires[numConnections] = conn_wire;
	numConnections += 1;
	return;
}

void Pin::RemoveConnection(Object* rem_wire) {
	Object* tmp[MAX_CONNECTIONS];
	int j = 0;
	int i = 0;
	while (i < numConnections) {
		if (rem_wire == wires[j]) {
			j++;
			continue;
		}
		tmp[i] = wires[j];
		j++;
		i++;

	}
	*wires = *tmp;
	numConnections--;
	return;
}
void Pin::DragPin(sf::Vertex new_pos) {
	this->pos = new_pos.position;
	for (int i = 0; i < numConnections; i++) {
		wires[i]->UpdatePosition(new_pos);
	}
	return;
}

bool Pin::IsSrc() {
	return type == OUTPUT;
}

Pin* Pin::ConnectedTo() {
	Pin* conn = new Pin[MAX_CONNECTIONS];
	for (int i = 0; i < numConnections; i++) {
		Wire* wire = dynamic_cast<Wire*>(wires[i]);
		if (IsSrc()) {
			conn[i] = *wire->GetPin(0);
		}
		else {
			conn[i] = *wire->GetPin(1);
		}
	}
	return conn;
}
