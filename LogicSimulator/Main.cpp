#include <iostream>
#include "Wire.h"
#include "Object.h"
#include <SFML/Graphics.hpp>
//#include "Simulator.h"
#include "AndGate.h"
using namespace std;

//class Simulator {
//    Object* head;
//
//};



int main()
{ 
    //Wire wire();
    AndGate andd(300.f, 300.f);
    //Object* objects = &wire;
    //Wire wire2();
    //wire2.next = &andd;
    //andd.next = objects;
    Object* objects = &andd;

   // Simulator simulator(objects);
    
    //sf::Texture texture;
    /*
    if (!texture.loadFromFile("../assets/AND.png"))
    {
        cout << "Failed to load texture!" << endl;
        return -1;
    }*/

    //sf::Texture texture;
    //if (!texture.loadFromFile("../assets/AND.png"))
    //{
    //    cout << "Failed to load texture !" << endl;
    //    return -1;
    //}

    //Wire w1;
    //Wire* ptr = &w1;



    //sf::RectangleShape rectangle(sf::Vector2f(120.f, 50.f));
    //rectangle.setFillColor(sf::Color(112, 112, 112));
    //rectangle.setSize(sf::Vector2f(150.f, 980.f));

    //sf::RectangleShape rectangle2(sf::Vector2f(120.f, 50.f));
    //rectangle2.setFillColor(sf::Color(112, 112, 112));
    //rectangle2.setSize(sf::Vector2f(1200.f, 100.f));
    //sf::Sprite sprite;
    //sprite.setPosition(sf::Vector2f(10.f, 50.f));
    //sprite.setTexture(texture);
    /*sf::Texture textures[2];
    */
     /*
    sf::Texture texture;
    if (!texture.loadFromFile("../assets/AND.png"))
    {
        cout << "Failed to load texture !" << endl;
    }
    sf::Sprite sprite;
    sprite.setTexture(texture);*/

    /*sprite.setPosition(sf::Vector2f(10.f, 50.f));
    sprite.setTexture(textures[1]);*/

    //sf::Sprite sprite= ptr->getSprite;
    //Wire wire;
    //sf::Sprite sprite = wire.getSprite();


    return 0;
}
