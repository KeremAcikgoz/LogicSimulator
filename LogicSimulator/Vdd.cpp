#include "Vdd.h"
#include "LogicElement.h"
#include <SFML/Graphics.hpp>
#include "Pin.h"
using namespace std;
Vdd::Vdd(sf::Vertex pos) : LogicElement(pos) {
	// TODO: make implicit
	if (!textures[1].loadFromFile("../assets/VDD.png"))
	{
		cout << "Failed to load texture !" << endl;
	}


	sprite.setTexture(textures[1]);
	numPins = 1;
	TypeId = O_Vdd;
	relativePinLocations[0] = sf::Vertex(sf::Vector2f(26, 49));
	pins[0].type = OUTPUT;
	this->UpdatePosition(position);

}
Vdd::~Vdd() {
	cout << "destructed Vdd" << endl;
}

void Vdd::LogicOperation() {
	pins[0].state = HIGH;
	return;
}

