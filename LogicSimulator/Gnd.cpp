#include "Gnd.h"
#include "LogicElement.h"
#include <SFML/Graphics.hpp>
#include "Pin.h"
using namespace std;
Gnd::Gnd(sf::Vertex pos) : LogicElement(pos) {
	// TODO: make implicit
	if (!textures[1].loadFromFile("../assets/GND.png"))
	{
		cout << "Failed to load texture !" << endl;
	}


	sprite.setTexture(textures[1]);
	numPins = 1;
	TypeId = O_GND;
	relativePinLocations[0] = sf::Vertex(sf::Vector2f(18,0));
	pins[0].type = OUTPUT;
	this->UpdatePosition(position);

}
Gnd::~Gnd() {
	cout << "destructed Gnd" << endl;
}

void Gnd::LogicOperation() {
	pins[0].state = LOW;
	return;
}

