#include "Simulation.h"
#include "Object.h"
#include "Wire.h"
#include "LogicElement.h"

void Simulation::Simulate(Object* objects) {
	Object* obj = objects;
	while (obj) {
		if (obj->TypeId != O_WIRE) {
			LogicElement* le = dynamic_cast<LogicElement*>(obj);
			le->LogicOperation();
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < le->GetPin(i)->numConnections; j++) {
					Wire* wire = dynamic_cast<Wire*>(le->GetPin(i)->wires[j]);
					wire->LogicOperation();
				}
			}
		}
		obj = obj->next;
	}
	return;
}