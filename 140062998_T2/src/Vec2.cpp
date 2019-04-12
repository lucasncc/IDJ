#include "Vec2.h"
#include <cmath>

Vec2::Vec2(){
  x = 0;
  y = 0;
}

Vec2::Vec2(float a, float b){
    x = a;
    y = b;
}


Vec2 Vec2::GetRotated(float angle){
  float a = this->x;
  float b = this->y;
  this->x = a * cos(angle) - b * sin(angle);
  this->y = b * cos(angle) + a * sin(angle);
  return *this;
}



Vec2 Vec2::operator+(Vec2 op){
      this->x = this->x + op.x;
      this->y = this->y + op.y;
      return *this;
      //return {this->x + op.x, this->y + op.y};
      //return Vec2(x + op.x, y + op.y);
}
