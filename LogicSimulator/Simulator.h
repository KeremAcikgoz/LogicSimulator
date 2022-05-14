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

        sf::Transform trans;
        bool isPanning = false, isDragging = false;
        Object* mObj = NULL;
        Object* connObj = NULL;
        sf::Vector2f prevDrag;
        sf::Vector2f prevClick;
        bool clickSpent = false;
        bool wasLeftClick = false;
        bool wasRightClick = false;
        bool paused = false;

        trans.translate(1200 / 2, 980 / 2);
        trans.scale(10, 10);

        auto clock = std::chrono::system_clock::now();
        sf::Clock powerClock;


        // run the program as long as the window is open
        while (window.isOpen())
        {
            auto mPos = sf::Vector2f(sf::Mouse::getPosition(window));
            auto mLoc = trans.getInverse().transformPoint(mPos);


            // check all the window's events that were triggered since the last iteration of the loop
            sf::Event event;
            while (window.pollEvent(event))
            {
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                    window.close();

				bool isLeftClick = sf::Mouse::isButtonPressed(sf::Mouse::Left);
				//bool isRightClick = sf::Mouse::isButtonPressed(sf::Mouse::Right);
				if (isLeftClick) {

					wasLeftClick = isLeftClick;
					//wasRightClick = isRightClick;
					clickSpent = false;

					auto delta = prevDrag - mPos;
					//Do drag
					if (isPanning) trans.translate(-delta / trans.getMatrix()[0]);
					if (isDragging) {
						auto drag = -delta / trans.getMatrix()[0];
						//if (mObj->TypeId == O_Panel) MovePanel(drag, mObj, objects);
						mObj->move(drag);
					}
					//Begin pan/drag/click
					if (!(isPanning + isDragging)) {
						prevClick = mPos;
						mObj = NULL;

						//Check if mouse over object - obj preferred to be non-panel
						for (auto& obj : objects) {
							if (!obj->getRoughRect().contains(mLoc)) continue;
							if (!mObj || (mObj && obj->TypeId != O_Panel)) mObj = obj;
						}

						if (isLeftClick) {
							bool lShift = keyPressed(sf::Keyboard::LShift);
							if (lShift && mObj) { //Delete obj if shift pressed
								DeleteObj(mObj, objects);
								clickSpent = true;
							}
							else if (!mObj && !lShift) isPanning = true;
							else if (mObj) {
								isDragging = true;
								if (mObj->TypeId == O_Panel) StartPanelDrag(mObj, objects, mLoc); //If we are beginning to drag a panel, mark participant objects
							}
						}
					}
					prevDrag = mPos;
					//Cancel making a connection, if we clicked somewhere else
					if ((!mObj || !mObj->Connectable) && connObj) connObj = NULL;
				}
				else {
					bool wasClick = prevClick == mPos;

					if ((!mObj || (mObj && mObj->TypeId == O_Panel)) && wasClick && !clickSpent) {
						//Check if there was a connection under the mouse, and delete it
						for (auto& obj : objects) {
							auto conns = &obj->Connections;
							auto rIterator = remove_if(conns->begin(), conns->end(), [mLoc](ObjX* conn) { return conn->ContainsPoint(mLoc); });
							conns->erase(rIterator, conns->end());
						}
						clickSpent = true;
					}
					else if (mObj) { //If we had an object under the mouse
						isDragging = false;
						if (wasClick && !clickSpent) {
							if ((wasLeftClick || (connObj && wasRightClick)) && mObj->Connectable) { //Start/make a new connection?
								if (!connObj) connObj = mObj; //First connect
								else { //Second connect
									if (connObj != mObj) AddConnection(connObj, mObj);
									if (!wasRightClick) connObj = NULL;
								}
							}
							else if (wasRightClick) { //'Click' the object?
								connObj = NULL;
								mObj->Click();
							}
							clickSpent = true;
							clock += std::chrono::milliseconds(30); //Mitigate double click
						}
						else {
							//Snap to grid
							mObj->setLocation(SnapPos(mObj->getPosition()));
							if (mObj->TypeId == O_Panel) SnapPanelObjs(mObj, objects);
						}
						mObj = NULL;
					}
					isPanning = false;
				}
            }

      
            
            window.clear();

            ////vector<sf::Sprite> sprites;
            //for (Object* p = objects; p; p = p->next) {
            //    //sprites.push_back(p->getSprite());
            //    window.draw(p->getSprite());
            //}
            //

            // end the current frame
            window.display();
            
        }
    }
    
};

