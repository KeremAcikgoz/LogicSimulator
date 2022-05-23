#include "Display.h"
#include <cmath>
#include "StartButton.h"
#include "StopButton.h"

Display::Display(sf::RenderWindow& window) : _window(&window)
{
	_font.loadFromFile("../assets/font.ttf");
	_text.setFont(_font);
	_text.setCharacterSize(80);

	_origin = sf::CircleShape(1, 4);
	_origin.setFillColor(sf::Color::Black);
	_origin.setPosition(-1, -1);

};


void Display::Render(Object*& objects, sf::Vector2f mLoc, bool isSimulationOn, StartButton startButton, StopButton stopButton)
{
	_window->clear(sf::Color::Black);
	
	//Draw object connections
	_window->draw(startButton.getSprite());
	_window->draw(stopButton.getSprite());
	Object* obj = objects;
	while (obj) {
		if (obj->TypeId == O_WIRE) {
			sf::VertexArray lines = obj->GetPosition();
			_window->draw(lines);
		}
		else {
			_window->draw(obj->getSprite());
		}
		obj = obj->next;
	}


	_window->display();
}
