#include "Object.hpp"

Object::Object(){}



int  Object::next_frame()
{
    int frame_no = (movementClock.getElapsedTime().asMilliseconds() / 100) % num_of_frames;
    obj_Sprite.setTexture(obj_Textures[frame_no]);
    return frame_no;
}

void Object::paint() {

};
void Object::clear() {

};

bool Object::is_in_Rect(int x, int y)
{
    sf::Rect rec = obj_Sprite.getTextureRect();
    float h = (float) rec.height;
    h *= Ylen;
    rec.height = (int)h;
    float w = (float)rec.width;
    w *= Xlen;
    rec.width = (int)w;
 //   cerr << x << "-" << y << "-" << rec.left << "-" << rec.width << "-" << rec.top << "-" << rec.height << endl;
    if( (x>=X) && (x<=(X+rec.width)) && (y>= Y) && (y<=(Y+rec.height) ))
    return true;
    return false;
}