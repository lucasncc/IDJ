#include "Rect.h"

Rect::Rect(){
  x = 0;
  y = 0;
  w = 0;
  h = 0;
}

Rect::Rect(float a, float b, float c, float d){
    this->x = a;
    this->y = b;
    this->w = c;
    this->h = d;
}



bool Rect::Contains(float valueX, float valueY){
    if(valueX >= this->x && valueX <= this->w && valueY >= this->y && valueY <= this->h)
        return true;
    else
        return false;
}
