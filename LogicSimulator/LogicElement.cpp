#include "LogicElement.h"
#include "Object.h"
#include "Pin.h"
#include <SFML/Graphics.hpp>

LogicElement::LogicElement(sf::Vertex pos)
{
	this->UpdatePosition(pos);
}
void LogicElement::UpdatePosition(sf::Vertex new_position) {
	sprite.setPosition(new_position.position);
	position = new_position;
	for (int i = 0; i < numPins; i++) {
		pins[i].DragPin(sf::Vector2f(new_position.position.x + this->relativePinLocations[i].position.x, new_position.position.y + this->relativePinLocations[i].position.y));

	}
}
Pin* LogicElement::DoesTouchPins(sf::Vector2f mPos, bool* isTrue) {
	Pin* outPin = NULL;
	bool ret = false;
	for (int i = 0; i < numPins; i++)
	{
		sf::Vector2f pin_location = position.position + this->relativePinLocations[i].position - sf::Vector2f(5.f, 5.f);
		sf::FloatRect rough_rect = sf::FloatRect(pin_location, RoughSize);
		ret = rough_rect.contains(mPos);
		if (ret) {
			outPin = &pins[i];
			break;
		}
	}
	*isTrue = ret;
	return outPin;
}

sf::VertexArray LogicElement::GetPosition() {
	sf::VertexArray lines(sf::LinesStrip, 1);
	lines[0].position = position.position;
	return lines;
}