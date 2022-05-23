#include "Dff.h"
#include "LogicElement.h"
#include <SFML/Graphics.hpp>
#include "Pin.h"
using namespace std;


Dff::Dff(sf::Vertex pos) : LogicElement(pos) {
	// TODO: make implicit
	if (!textures[1].loadFromFile("../assets/DFF.png"))
	{
		cout << "Failed to load texture !" << endl;
	}

	sprite.setTexture(textures[1]);
	numPins = 4;
	TypeId = O_Dff;
	relativePinLocations[0] = sf::Vertex(sf::Vector2f(0, 15)); // D
	relativePinLocations[1] = sf::Vertex(sf::Vector2f(0, 35));// clk
	relativePinLocations[2] = sf::Vertex(sf::Vector2f(90, 15));//Q
	relativePinLocations[3] = sf::Vertex(sf::Vector2f(90, 55));//Q_not
	pins[2].type = OUTPUT;
	pins[3].type = OUTPUT;
	this->UpdatePosition(position);

}
Dff::~Dff() {
	cout << "destructed D-FlipFlop" << endl;
}

void Dff::LogicOperation() {
	bool wasClockOn = isClockOn;
	isClockOn = pins[1].state == HIGH ? true : false;
	if(!wasClockOn && isClockOn) {
		pins[2].state = pins[0].state;
		pins[3].state = pins[0].state == HIGH ? LOW : HIGH;
	}

	return;
}


