#pragma once
#include "Object.h"
#include "AndGate.h"


Object* create_element(ObjectTypes type, sf::Vertex position) {

    switch (type)
    {
    case O_AND:
        return new AndGate(position);
        break;
    default:
        return new AndGate(position);
        break;
    }

}

sf::Vertex get_vertex(float posx, float posy) {
    sf::Vertex vert(sf::Vector2f(posx, posy));
    return vert;
}

Object* append_to_objects(Object* objects, Object* new_object) {
    new_object->next = objects;
    objects = new_object;
    return objects;
}

LogicElement* append_to_le(LogicElement* le, LogicElement* new_le) {
    new_le->next = le;
    le = new_le;
    return le;
}

Object* removeElement(Object* objects, Object* rem_obj) {
    
    Object* obj = objects;
    Object* prevObj = NULL;
    while (obj) {
        if (obj && obj == rem_obj) {
            if (prevObj) {
                prevObj->next = prevObj->next->next;
                break;
            }
            else {
                objects = obj->next;
            }
        }
        prevObj = obj;
        obj = obj->next;

    }
    //if (rem_obj->TypeId == O_WIRE) {
    //    Wire* wire = dynamic_cast<Wire*> (rem_obj);
    //    delete wire;
    //}
    //else {
    //    AndGate* le = dynamic_cast<AndGate*> (rem_obj);
    //    delete le;

    //}
    //delete rem_obj;
    return objects;
}

void removePin(Pin* pin) {
    delete &pin;
    return;
}
