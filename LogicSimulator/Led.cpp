#include "Led.h"
#include "OrGate.h"
#include "AndGate.h"
#include "LogicElement.h"
#include <SFML/Graphics.hpp>
#include "Pin.h"
using namespace std;
Led::Led(sf::Vertex pos) : LogicElement(pos) {
	// TODO: make implicit
	if (!textures[1].loadFromFile("../assets/LEDON.png"))
	{
		cout << "Failed to load texture !" << endl;
	}
	if (!textures[0].loadFromFile("../assets/LEDOFF.png"))
	{
		cout << "Failed to load texture !" << endl;
	}

	sprite.setTexture(textures[0]);
	numPins = 2;
	TypeId = O_LED;
	relativePinLocations[0] = sf::Vertex(sf::Vector2f(10, 67));
	relativePinLocations[1] = sf::Vertex(sf::Vector2f(24, 67));
	this->UpdatePosition(position);

}
Led::~Led() {
	cout << "destructed or gate" << endl;
}

void Led::LogicOperation() {
	bool in_state1 = pins[0].state == LOW ? false : true;
	bool in_state2 = pins[1].state == LOW ? false : true;
	bool out_state = in_state1 ^ in_state2;
	out_state ? sprite.setTexture(textures[1]) : sprite.setTexture(textures[0]);
	return;
}

