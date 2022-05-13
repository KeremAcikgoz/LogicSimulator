#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Object.h"

using namespace std;

class Simulator
{
    sf::RenderWindow* window;
    Object* objects;
public:
    // create the window
    Simulator(Object* objectList) {

        objects = objectList;
        sf::RenderWindow window(sf::VideoMode(1200, 980), "Logic Simulator");

        bool movingAnElement = false;
        // run the program as long as the window is open
        while (window.isOpen())
        {
            // check all the window's events that were triggered since the last iteration of the loop
            sf::Event event;
            while (window.pollEvent(event))
            {
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                    window.close();
            }


      
            // draw everything here...
            for (Object* p = objects; p; p = p->next) {
                //sprites.push_back(p->getSprite());
                p->move(movingAnElement);
            }
            
            window.clear();

            //vector<sf::Sprite> sprites;
            for (Object* p = objects; p; p = p->next) {
                //sprites.push_back(p->getSprite());
                window.draw(p->getSprite());
            }
            

            // end the current frame
            window.display();
            
        }
    }
    
};

