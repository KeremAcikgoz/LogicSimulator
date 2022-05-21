#include "OrGate.h"
#include "AndGate.h"
#include "LogicElement.h"
#include <SFML/Graphics.hpp>
#include "Pin.h"
using namespace std;
OrGate::OrGate(sf::Vertex pos) : LogicElement(pos) {
	// TODO: make implicit
	if (!textures[1].loadFromFile("../assets/OR.png"))
	{
		cout << "Failed to load texture !" << endl;
	}

	sprite.setTexture(textures[1]);
	numPins = 3;
	TypeId = O_OR;
	relativePinLocations[0] = sf::Vertex(sf::Vector2f(0, 12));
	relativePinLocations[1] = sf::Vertex(sf::Vector2f(0, 42));
	relativePinLocations[2] = sf::Vertex(sf::Vector2f(90, 27));
	pins[2].type = OUTPUT;
	this->UpdatePosition(position);

}
OrGate::~OrGate() {
	cout << "destructed or gate" << endl;
}

void OrGate::LogicOperation() {
	bool in_state1 = pins[0].state == LOW ? false : true;
	bool in_state2 = pins[1].state == LOW ? false : true;
	bool out_state = in_state1 || in_state2;
	pins[2].state = out_state ? HIGH : LOW;
	return;
}

