
#include <iostream>
#include "Wire.h"
#include "Object.h"
#include <SFML/Graphics.hpp>
//#include "Simulator.h"
#include "AndGate.h"
#include "utils.h"
#include "Display.h"
#include "Pin.h"
#include "LogicElement.h"
#include "Simulation.h"
#include "Button.h"
#include "StartButton.h"
#include "StopButton.h"


#define keyPressed(key) sf::Keyboard::isKeyPressed(key)
#define WIN_W 1000
#define WIN_H 1000

using namespace std;

int main()
{
	//sf::Vertex vert(sf::Vector2f(300.f, 300.f));
	//sf::Vertex vert2(sf::Vector2f(600.f, 600.f));
	//Pin pin(OUTPUT, 0, vert);
	//Pin pin2(INPUT, 0, vert2);

	//Wire* wire = new Wire(vert, &pin, &pin2);
	//AndGate* andnew = new AndGate(vert);

	//wire->ConnectWire(&pin2);

	//delete wire;
	//Wire* wire2 = wire;
	//delete andnew;
	//AndGate* and_source2 = new AndGate(get_vertex(1.f, 100.f));
	//delete and_source2;
	//cout << "wait" << endl;
	//while (true);

	bool isSimulationOn = false;
	bool wasLeftClick = false;
	bool wasRightClick = false;
	Object* selectedObj = NULL;
	bool isSelected = false;
	bool clickSpent = false;
	sf::Vector2f offset;

	Pin tmp_pin(OUTPUT, 0, sf::Vertex(sf::Vector2f(0.f, 0.f)));


	StartButton startButton(sf::Vector2f(300.f, 1.f));
	StopButton stopButton(sf::Vector2f(600.f, 1.f));


	Object* objects = NULL;

	Object* and_source = create_element(O_AND, get_vertex(1.f, 200.f));
	Object* or_source = create_element(O_OR, get_vertex(1.f, 100.f));
	Object* led_source = create_element(O_LED, get_vertex(1.f, 300.f));
	Object* vdd_source = create_element(O_Vdd, get_vertex(1.f, 400.f));
	Object* gnd_source = create_element(O_GND, get_vertex(1.f, 500.f));
	Object* not_source = create_element(O_NOT, get_vertex(1.f, 600.f));
	Object* xor_source = create_element(O_XOR, get_vertex(1.f, 700.f));
	Object* clock_source = create_element(O_CLOCK, get_vertex(1.f, 800.f));
	Object* dff_source = create_element(O_Dff, get_vertex(1.f, 1.f));
	led_source->isSource = true;
	vdd_source->isSource = true;
	or_source->isSource = true;
	and_source->isSource = true;
	gnd_source->isSource = true;
	not_source->isSource = true;
	xor_source->isSource = true;
	clock_source->isSource = true;
	dff_source->isSource = true;
	objects = append_to_objects(objects, and_source);
	objects = append_to_objects(objects, or_source);
	objects = append_to_objects(objects, led_source);
	objects = append_to_objects(objects, vdd_source);
	objects = append_to_objects(objects, gnd_source);
	objects = append_to_objects(objects, not_source);
	objects = append_to_objects(objects, xor_source);
	objects = append_to_objects(objects, clock_source);
	objects = append_to_objects(objects, dff_source);


	//Object* and_source2 = create_element(O_AND, get_vertex(1.f, 100.f));
	//objects = append_to_objects(objects, and_source2);
	//
	//LogicElement* le;
	//append_to_le(and_source2)


	cout << "created some stuff to play with" << endl;

	sf::RenderWindow window(sf::VideoMode(WIN_W, WIN_H), "LogicSimulator");
	auto display = Display(window);

	while (window.isOpen()) {
		
		//window.draw(startButton.getSprite());
		bool isMouse = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
		auto mPos = sf::Vector2f(sf::Mouse::getPosition(window));
		
		tmp_pin.DragPin(mPos);
		//cout << mPos.x << "," << mPos.y << endl;

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::Resized) {
				window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
			}

			bool isLeftClick = sf::Mouse::isButtonPressed(sf::Mouse::Left);
			bool isRightClick = sf::Mouse::isButtonPressed(sf::Mouse::Right);
			if(isSimulationOn){//isSimulationOn

				if (stopButton.checkClick(mPos) && isLeftClick) {
						isSimulationOn = false;
						startButton.current = false;
				}
					//isSimulationOn = false;
					//TODO: end simulation týklayýnca kapat.
			}
			else {
				if (isLeftClick) {
					if (wasLeftClick) {
						if (clickSpent) continue;
						//drag selected if draggable, check for pins if making wire and when pin found clickspent=true
						if (isSelected && selectedObj->TypeId == O_WIRE) {
							//is there a pin around? if yes connect and set clickspent = true
							//else keep dragging tmp_pin along with mouse
							Wire* current_wire = dynamic_cast<Wire*>(selectedObj);
							LogicElement* current_logic_element = NULL;
							Object* obj = objects;
							while (obj) {

								if (obj->TypeId != O_WIRE && obj->DoesContain(mPos) && !obj->isSource) {
									LogicElement* selectedLogicElement = dynamic_cast<LogicElement*>(obj);
									if (selectedLogicElement->DoesContainPin(current_wire->GetPin(0)) ||
										selectedLogicElement->DoesContainPin(current_wire->GetPin(1))) {
										break;
									}
									current_logic_element = selectedLogicElement;
									offset = mPos - obj->getSprite().getPosition();
									break;
								}
								obj = obj->next;
							}
							if (current_logic_element && current_logic_element->TypeId != O_WIRE) {
								bool isTouching = false;

								//LogicElement* selectedElement = dynamic_cast<LogicElement*>(selectedObj);

								Pin* selectedPin = current_logic_element->DoesTouchPins(mPos, &isTouching);

								if (isTouching) {
									if (selectedPin->type == INPUT && selectedPin->numConnections > 0) {
										continue;
									}
									else if (selectedPin->type == INPUT && !(current_wire->IsConnected(0)) ||
										selectedPin->type == OUTPUT && !(current_wire->IsConnected(1))) {

										current_wire->ConnectWire(selectedPin);
										isSelected = false;
										clickSpent = true;
									}
								}

							}

						}
						else if (isSelected) {
							//drag
							selectedObj->UpdatePosition(mPos - offset);
						}
					}
					else {
						//click actions: create new instance from source and select it, select, create wire from that pin, select
						Object* obj = objects;
						while (obj) {
							if (obj->TypeId != O_WIRE && obj->DoesContain(mPos)) {
								selectedObj = obj;
								isSelected = true;
								offset = mPos - obj->getSprite().getPosition();
								break;
							}
							obj = obj->next;
						}
						if (isSelected) {
							if (selectedObj->isSource) {
								//create new object from that type and select that
								selectedObj = create_element(selectedObj->TypeId, mPos);
								objects = append_to_objects(objects, selectedObj);

							}
							else {
								//check if it is close to a pin,
								//if so, create wire and select it
								bool isTouching = false;
								LogicElement* selectedElement = dynamic_cast<LogicElement*>(selectedObj);

								Pin* selectedPin = selectedElement->DoesTouchPins(mPos, &isTouching);

								if (isTouching) {
									if (selectedPin->type == INPUT && selectedPin->numConnections > 0) {
										continue;
									}
									else {
										Wire* wire = new Wire(selectedPin->pos, selectedPin, &tmp_pin);
										wire->SetSelected(true);
										selectedObj = wire;
										objects = append_to_objects(objects, wire);
									}
								}

							}
						}
						else if (startButton.checkClick(mPos)) {
							//TODO: eðer startsimulation týklandýysa
							isSimulationOn = true;
							//isSimulationOn = Simulation::StartSimulation(objects);
							stopButton.current = false;
							int a = 1;
						}
					}
					wasLeftClick = true;
				}

				if (isRightClick) {
					if (!wasRightClick) {

						//remove if logic element or wire just once when it is clicked
						Object* obj = objects;
						while (obj) {
							if (!obj->isSource && obj->DoesContain(mPos)) {
								//remove obj from objects
								//remember to clear pins and wires too
								if (obj->TypeId == O_WIRE) {
									Wire* selectedWire = dynamic_cast<Wire*>(obj);
									objects = remove_from_objects(objects, selectedWire);
									delete selectedWire;
									break;
								}
								else {
									LogicElement* selectedElement = dynamic_cast<LogicElement*>(obj);//?
									for (int i = 0; i < 4; i++) {
										Object** list_of_wires = selectedElement->GetPin(i)->wires;
										for (int j = 0; j < selectedElement->GetPin(i)->numConnections; j++) {
											objects = remove_from_objects(objects, list_of_wires[j]);
										}
										if (selectedElement->GetPin(i)->numConnections > 0) {
											delete[] * list_of_wires;

										}

									}
									objects = remove_from_objects(objects, selectedElement);
									delete selectedElement;
									break;
								}
							}
							obj = obj->next;
						}
					}
					wasRightClick = true;
				}
				if (!isLeftClick && !isRightClick) {
					if (wasLeftClick) {
						if (isSelected) {
							//release actions: if wire remove, if logic element release
							if (selectedObj->TypeId == O_WIRE && !clickSpent) {
								//remove wire since it is of no use anymore
								//remember to clear pins too
								//remove wire from objects

								Wire* selectedWire = dynamic_cast<Wire*>(selectedObj);//?
								objects = remove_from_objects(objects, selectedWire);
								delete selectedWire;


							}

							isSelected = false;
						}

					}
					wasLeftClick = false;
					wasRightClick = false;
					clickSpent = false;
					isSelected = false;
				}
			}
		}
		if (isSimulationOn) {
			Simulation::Simulate(objects);
		}
		display.Render(objects, mPos, isSimulationOn, startButton, stopButton);

	}

	cout << "done" << endl;

	return 0;
}


//sf::Transform trans;
//bool isPanning = false, isDragging = false;
//Obj* mObj = NULL;
//Obj* connObj = NULL;
//sf::Vector2f prevDrag;
//sf::Vector2f prevClick;
//bool clickSpent = false;
//bool wasLeftClick = false;
//bool wasRightClick = false;
//bool paused = false;

//trans.translate(WIN_W/2, WIN_H/2);
//trans.scale(10, 10);

//auto clock = std::chrono::system_clock::now();
//sf::Clock powerClock;
//
//while (window.isOpen()) {
//
//	auto mPos = sf::Vector2f(sf::Mouse::getPosition(window));
//    auto mLoc = trans.getInverse().transformPoint(mPos);
//
//	sf::Event event;
//	while (window.pollEvent(event)) {
//		//Events
//		if (event.type == sf::Event::Closed) window.close();
//		if (event.type == sf::Event::Resized) window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
//
//		//Check if adding a new Obj
//		if (event.type == sf::Event::KeyPressed) {
//			if (keyPressed(sf::Keyboard::LControl)) {
//				switch (event.key.code) {
//					case sf::Keyboard::S: SaveToFile(objects); break;
//					case sf::Keyboard::C: SaveToFile(objects, true); break;
//					case sf::Keyboard::O: OpenFromFile(objects); break;
//					case sf::Keyboard::I: OpenFromFile(objects, true, mLoc); break;
//				}
//			} else {
//				switch (event.key.code) {
//					case sf::Keyboard::A: AddObj(objects, new ObjAND(), mLoc); break;
//					case sf::Keyboard::O: AddObj(objects, new ObjOR(), mLoc); break;
//					case sf::Keyboard::X: AddObj(objects, new ObjXOR(), mLoc); break;
//					case sf::Keyboard::N: AddObj(objects, new ObjNOT(), mLoc); break;
//					case sf::Keyboard::S: AddObj(objects, new ObjSwitch(), mLoc); break;
//					case sf::Keyboard::P: AddObj(objects, new ObjPanel(), mLoc); break;
//					case sf::Keyboard::R: AddObj(objects, new ObjRandom(), mLoc); break;
//					case sf::Keyboard::B: AddObj(objects, new ObjBit(), mLoc); break;
//					case sf::Keyboard::I: AddObj(objects, new ObjIndicator(), mLoc); break;
//					case sf::Keyboard::C: DuplicateObjs(objects, mLoc); break;
//					case sf::Keyboard::F1: paused = !paused; break;
//					case sf::Keyboard::F2: Electrify(objects); break;
//				}
//			}
//		}
//		//Check if clicking/dragging
//		bool isLeftClick = sf::Mouse::isButtonPressed(sf::Mouse::Left) || keyPressed(sf::Keyboard::LAlt);
//		bool isRightClick = sf::Mouse::isButtonPressed(sf::Mouse::Right) || keyPressed(sf::Keyboard::Space);
//		if (isLeftClick || isRightClick) {
//
//			wasLeftClick = isLeftClick;
//			wasRightClick = isRightClick;
//			clickSpent = false;
//
//			auto delta = prevDrag - mPos;
//			//Do drag
//			if (isPanning) trans.translate(-delta/trans.getMatrix()[0]);
//			if (isDragging) {
//				auto drag = -delta / trans.getMatrix()[0];
//				if (mObj->TypeId == O_Panel) MovePanel(drag, mObj, objects);
//				else mObj->move(drag);
//			}
//			//Begin pan/drag/click
//			if (!(isPanning + isDragging)) {
//				prevClick = mPos;
//				mObj = NULL;
//
//				//Check if mouse over object - obj preferred to be non-panel
//				for (auto &obj : objects) {
//					if (!obj->getRoughRect().contains(mLoc)) continue;
//					if (!mObj || (mObj && obj->TypeId != O_Panel)) mObj = obj;
//				}
//
//				if (isLeftClick) {
//					bool lShift = keyPressed(sf::Keyboard::LShift);
//					if (lShift && mObj) { //Delete obj if shift pressed
//						DeleteObj(mObj, objects);
//						clickSpent = true;
//					} else if (!mObj && !lShift) isPanning = true;
//					else if (mObj) {
//						isDragging = true;
//						if (mObj->TypeId == O_Panel) StartPanelDrag(mObj, objects, mLoc); //If we are beginning to drag a panel, mark participant objects
//					}
//				}
//			}
//			prevDrag = mPos;
//			//Cancel making a connection, if we clicked somewhere else
//			if ((!mObj || !mObj->Connectable) && connObj) connObj = NULL;
//		} else {
//			bool wasClick = prevClick == mPos;
//
//			if ((!mObj || (mObj && mObj->TypeId == O_Panel)) && wasClick && !clickSpent) {
//				//Check if there was a connection under the mouse, and delete it
//				for (auto &obj : objects) {
//					auto conns = &obj->Connections;
//					auto rIterator = remove_if(conns->begin(), conns->end(), [mLoc](ObjX* conn) { return conn->ContainsPoint(mLoc); });
//					conns->erase(rIterator, conns->end());
//				}
//				clickSpent = true;
//			} else if (mObj) { //If we had an object under the mouse
//				isDragging = false;
//				if (wasClick && !clickSpent) {
//					if ((wasLeftClick || (connObj && wasRightClick)) && mObj->Connectable) { //Start/make a new connection?
//						if (!connObj) connObj = mObj; //First connect
//						else { //Second connect
//							if (connObj != mObj) AddConnection(connObj, mObj);
//							if (!wasRightClick) connObj = NULL;
//						}
//					} else if (wasRightClick) { //'Click' the object?
//						connObj = NULL;
//						mObj->Click();
//					}
//					clickSpent = true;
//					clock += std::chrono::milliseconds(30); //Mitigate double click
//				} else {
//					//Snap to grid
//					mObj->setLocation(SnapPos(mObj->getPosition()));
//					if (mObj->TypeId == O_Panel) SnapPanelObjs(mObj, objects);
//				}
//				mObj = NULL;
//			}
//			isPanning = false;
//		}
//
//		if (event.type == sf::Event::MouseWheelScrolled) {
//			float zoomBy = event.mouseWheelScroll.delta > 0 ? 0.9f : 1.1f;
//			trans.scale(zoomBy, zoomBy, mLoc.x, mLoc.y);
//		}
//	}
//
//	//Display
//	display.Render(trans, objects, connObj, mLoc);
//	//Electrify
//	if (!paused && IsClockElapsed(&powerClock, 256)) Electrify(objects);
//
//	//Clock
//	clock += std::chrono::milliseconds(30);
//	std::this_thread::sleep_until(clock);
//}
//}
