#pragma once
#include "Object.h"
#include "AndGate.h"

string Texture(ObjectTypes type){
    string texture;
    switch (type)
    {
    case O_AND:
        texture = "../assets/AND.png";
        break;
    
    default:
        texture = "";
        break;
    }
    texture = "";
    return texture;
}

Object* create_element(ObjectTypes type, sf::Vertex position){
    
    switch (type)
    {
    case O_AND:
        // AndGate new_and_gate(position);
        // return &new_and_gate;
        break;
    default:
        break;
    }

}

sf::Vertex get_vertex(float posx, float posy){
    sf::Vertex vert(sf::Vector2f(posx, posy));
    return vert;
}

Object* append_to_objects(Object* objects, Object* new_object){
    new_object->next = objects;
    objects = new_object;
    return objects;
}