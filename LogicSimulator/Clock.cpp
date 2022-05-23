#include "Clock.h"
#include "LogicElement.h"
#include <SFML/Graphics.hpp>
#include "Pin.h"
using namespace std;


Clock::Clock(sf::Vertex pos) : LogicElement(pos) {
	// TODO: make implicit
	if (!textures[1].loadFromFile("../assets/CLOCK.png"))
	{
		cout << "Failed to load texture !" << endl;
	}

	sprite.setTexture(textures[1]);
	numPins = 1;
	TypeId = O_CLOCK;
	relativePinLocations[0] = sf::Vertex(sf::Vector2f(70, 24));

	pins[0].type = OUTPUT;
	this->UpdatePosition(position);

}
Clock::~Clock() {
	cout << "destructed clock gate" << endl;
}

void Clock::LogicOperation() {
	bool out_state = (int)clock.getElapsedTime().asSeconds() % 2 == 0 ? false : true;
	pins[0].state = out_state ? HIGH : LOW;
	return;
}

