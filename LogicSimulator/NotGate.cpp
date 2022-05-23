#include "LogicElement.h"
#include <SFML/Graphics.hpp>
#include "Pin.h"
#include "NotGate.h"
using namespace std;


NotGate::NotGate(sf::Vertex pos) : LogicElement(pos) {
	// TODO: make implicit
	if (!textures[1].loadFromFile("../assets/NOT.png"))
	{
		cout << "Failed to load texture !" << endl;
	}

	sprite.setTexture(textures[1]);
	numPins = 2;
	TypeId = O_NOT;
	relativePinLocations[0] = sf::Vertex(sf::Vector2f(0, 25));
	relativePinLocations[1] = sf::Vertex(sf::Vector2f(90, 25));
	pins[1].type = OUTPUT;
	this->UpdatePosition(position);

}
NotGate::~NotGate() {
	cout << "destructed or gate" << endl;
}

void NotGate::LogicOperation() {
	bool in_state1 = pins[0].state == LOW ? false : true;
	bool out_state = !in_state1;
	pins[1].state = out_state ? HIGH : LOW;
	return;
}

