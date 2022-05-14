#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
using namespace std;

enum ObjTypes { O_NULL, O_AND, O_OR, O_XOR, O_NOT, O_Panel, O_Led, O_Vdd, O_Ground, O_Dff};


class Object {
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
    Object() {
        //window = window;
        //textures = textures
        locked = false;
        next = NULL;
        selected = false;
        state = false;
        moving = false;
    }
    ~Object() {
        cout << "Object Destructor called" << endl;
    }
    /*sf::RenderWindow getWindow() {
        return *window;
    }*/
    bool getState() {
        return state;
    }
    bool IsLocked() {
        return locked;
    }
    bool IsSelected() {
        return selected;
    }
    sf::Sprite getSprite() {
        return sprite;
    }
         //const Object& operator[](int i) const {
        //    if (i < 0) {
        //        cerr << "Index out of range!" << endl;
        //        return;
        //    }
        //    
        //    return [i];

        //}
    };


};