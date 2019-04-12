#include "Face.h"
#include <stdio.h>
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include "GameObject.h"


Face::Face(GameObject& associated):Component (associated){
    hitpoints = 30;
}

void Face::Damage(int damage){

    cout << "Vida antes do dano: " << this->hitpoints << endl;


    this->hitpoints = this->hitpoints - damage;

    cout << "Vida apos dano: " << this->hitpoints << endl;
    if(this->hitpoints <= 0){
      this->sound_destroy = (Sound*)associated.GetComponent("Sound");
      if(this->sound_destroy != nullptr){
          sound_destroy->Play();
      }

      this->associated.RequestDelete();
    }
}

void Face::Update(float dt){

}

void Face::Render(){

}

bool Face::Is(std::string type){
  if(0 == strcmp( "Face", type.c_str() ) )
      return true;
  return false;
}
