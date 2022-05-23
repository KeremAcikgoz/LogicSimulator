#include "XorGate.h"
#include "LogicElement.h"
#include <SFML/Graphics.hpp>
#include "Pin.h"
using namespace std;


XorGate::XorGate(sf::Vertex pos) : LogicElement(pos) {
	// TODO: make implicit
	if (!textures[1].loadFromFile("../assets/XOR.png"))
	{
		cout << "Failed to load texture !" << endl;
	}

	sprite.setTexture(textures[1]);
	numPins = 3;
	TypeId = O_XOR;
	relativePinLocations[0] = sf::Vertex(sf::Vector2f(0, 10));
	relativePinLocations[1] = sf::Vertex(sf::Vector2f(0, 40));
	relativePinLocations[2] = sf::Vertex(sf::Vector2f(90, 25));
	pins[2].type = OUTPUT;
	this->UpdatePosition(position);

}
XorGate::~XorGate() {
	cout << "destructed xor gate" << endl;
}

void XorGate::LogicOperation() {
	bool in_state1 = pins[0].state == LOW ? false : true;
	bool in_state2 = pins[1].state == LOW ? false : true;
	bool out_state = in_state1 ^ in_state2;
	pins[2].state = out_state ? HIGH : LOW;
	return;
}

