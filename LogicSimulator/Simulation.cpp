#include "Simulation.h"
#include "Object.h"
#include "Wire.h"
#include "LogicElement.h"

using namespace std;


void Simulation::Simulate(Object* objects) {
	Object* obj = objects;
	while (obj) {
		if (obj->TypeId != O_WIRE) {
			LogicElement* le = dynamic_cast<LogicElement*>(obj);
			le->LogicOperation();
			for (int i = 0; i < 4; i++) {
				if (le->GetPin(i)->type == OUTPUT) {//Output
					for (int j = 0; j < le->GetPin(i)->numConnections; j++) {
						Wire* wire = dynamic_cast<Wire*>(le->GetPin(i)->wires[j]);
						wire->LogicOperation();
					}
				}
				if (le->GetPin(i)->type == INPUT) {//Output
					if (le->GetPin(i)->numConnections >= 0) {
						le->GetPin(i)->state = LOW;
					}
				}
			}
		}
		obj = obj->next;
	}
	return;
}

bool Simulation::StartSimulation(Object* objects) {
	Object* obj = objects;
	bool ret = true;
	while (obj) {
		if (obj->TypeId != O_WIRE) {
			LogicElement* le = dynamic_cast<LogicElement*>(obj);
			le->LogicOperation();
			for (int i = 0; i < 4; i++) {
				if (le->GetPin(i)->type == INPUT) {
					if (le->GetPin(i)->numConnections <= 0) {
						ret = false;
					}
				}
			}
		}
		obj = obj->next;
	}
	if (!ret) {
		cerr << "Check if there are any unconnected input pin(s)" << endl;
	}
	return ret;
}