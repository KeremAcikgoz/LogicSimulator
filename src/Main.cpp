
#include <iostream>
#include "Wire.h"
#include "Object.h"
#include <SFML/Graphics.hpp>
//#include "Simulator.h"
#include "AndGate.h"
#include "utils.h"

using namespace std;

int main()
{
    sf::Vertex vert(sf::Vector2f(300.f, 300.f));
    Pin pin;
    Wire wire(vert, pin);

    Object *objects = &wire;

    Object *and_source = create_element(O_AND, get_vertex(300.f, 600.f));
    and_source->isSource = true;
    append_to_objects(objects, and_source);

    // AndGate andd(300.f, 300.f);

    // Object* objects = &andd;

    cout << "isim bitti burda" << endl;
    return 0;
}
