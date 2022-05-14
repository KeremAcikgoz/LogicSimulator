#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
using namespace std;

enum ObjectTypes { O_NULL, O_AND, O_OR, O_XOR, O_NOT, O_Panel, O_Led, O_Vdd, O_Ground, O_Dff};

class Object 
{
protected:
    bool locked;
    bool state;
    bool selected;
    sf::Texture textures[2];
    bool moving;
public:
    sf::RenderWindow window;
    Object* next;
    sf::Sprite sprite;
    ObjectTypes TypeId;
    bool isSource;
    Object() {
        //window = window
        //textures = textures
        locked = false;
        next = NULL;
        selected = false;
        state = false;
        moving = false;
        isSource = false;
        //TypeId = O_AND;

    }
    virtual ~Object() {
        cout << "Object Destructor called" << endl;
    }
    virtual bool getState() {
        return state;
    }
    virtual bool IsLocked() {
        return locked;
    }
    virtual bool IsSelected() {
        return selected;
    }
    virtual sf::Sprite getSprite() {
        return sprite;
    }

    
};