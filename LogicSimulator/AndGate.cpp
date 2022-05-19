#include "AndGate.h"
#include "LogicElement.h"
#include <SFML/Graphics.hpp>
#include "Pin.h"
using namespace std;
AndGate::AndGate(sf::Vertex pos) : LogicElement(pos) {
	// TODO: make implicit
	if (!textures[1].loadFromFile("../assets/AND.png"))
	{
		cout << "Failed to load texture !" << endl;
	}

	sprite.setTexture(textures[1]);
	numPins = 3;
	TypeId = O_AND;
	relativePinLocations[0] = sf::Vertex(sf::Vector2f(0, 12));
	relativePinLocations[1] = sf::Vertex(sf::Vector2f(0, 42));
	relativePinLocations[2] = sf::Vertex(sf::Vector2f(90, 27));
	pins[2].type = OUTPUT;
	this->UpdatePosition(position);

}
AndGate::~AndGate() {
	cout << "destructed and gate" << endl;
}
//
//void AndGate::SetPinLocations(){
//	for (int i = 0; i < numPins; i++){
//		pins[i].DragPin(sf::Vector2f(this->position.position.x + this->relativePinLocations[i].position.x , this->position.position.y + this->relativePinLocations[i].position.y));
//	}
//}

