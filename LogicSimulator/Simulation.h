#pragma once
#include "Object.h"

class Simulation
{
public:
	static void Simulate(Object* object);
	static bool StartSimulation(Object* object);
};

