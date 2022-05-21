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

	const uint16_t gSize = window.getSize().x;
	_grid = sf::VertexArray(sf::Lines, gSize / 2);
	auto c = sf::Color(0, 0, 0, 32);
	for (uint16_t g = 0, xy = 0; xy < 400; xy += 10) {
		_grid[g++] = sf::Vertex(sf::Vector2f(0, xy), c);
		_grid[g++] = sf::Vertex(sf::Vector2f(gSize, xy), c);
		_grid[g++] = sf::Vertex(sf::Vector2f(xy, 0), c);
		_grid[g++] = sf::Vertex(sf::Vector2f(xy, gSize), c);
	}
};


void Display::Render(Object*& objects, sf::Vector2f mLoc, bool isSimulationOn, StartButton startButton, StopButton stopButton)
{
	_window->clear(sf::Color::Black);
	//Draw grid
//	float scale = matrix.getMatrix()[0];
//	if (scale > 4) { //If above a certian scale
//		auto gridMatrix = sf::Transform();
//		float x = matrix.getMatrix()[12];
//		float y = matrix.getMatrix()[13];
//		gridMatrix.translate(fmod(x, 10*scale) - (10*scale), fmod(y, 10*scale) - (10*scale));
//		gridMatrix.scale(scale, scale);
//
//		_window->draw(_grid, gridMatrix);
//	}
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
	//	//Draw mouse connection object
	//	// if (connObj) _window->draw(*(new sfLine(sf::Color::Green, sf::Color::Black, 1, connObj->CenterPos, mLoc)), matrix);
	//	//Draw panel objects
	//	for (auto &obj : objects) {
	//		_window->draw(*(obj), matrix);
	//
	//		_text.setString(obj->getString());
	//		auto scale = matrix.getMatrix()[0];
	//
	//		auto tBounds = _text.getLocalBounds();
	//		_text.setOrigin(tBounds.left + tBounds.width/2., tBounds.top  + tBounds.height/2.);
	//		_text.setPosition(matrix.transformPoint(obj->getPosition()) + sf::Vector2f(obj->Size.x/2*scale, obj->Size.y/2*scale));
	//		_text.setScale(scale/10, scale/10);
	//		_text.setFillColor(obj->StageElectrified ? sf::Color::White : sf::Color::Black);
	//		_window->draw(_text);
	//	}
	//	//Draw 0,0
	//	_window->draw(_origin, matrix);

	_window->display();
}
