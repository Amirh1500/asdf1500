#include "Object.hpp"

Object::Object(){}
int  Object::next_frame()
{
    return (movementClock.getElapsedTime().asMilliseconds() / 100) % num_of_frames;
}

void Object::paint() {

};
void Object::clear() {

};