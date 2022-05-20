#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"

class Display
{
private:
	sf::RenderWindow* _window;
	sf::Font _font;
	sf::Text _text;
	sf::CircleShape _origin;
	sf::VertexArray _grid;
public:
	Display(sf::RenderWindow& window);
	//void Render (sf::Transform&, sf::Vector2f mLoc);
	void Render(Object*& objects, sf::Vector2f mLoc, bool isSimulationOn);
};
