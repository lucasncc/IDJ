#include "Component.h"
#include <stdio.h>
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
//#include "GameObject.h"


Component::Component(GameObject& associated):associated (associated){

}



Component::~Component(){

}

void Component::Update(float dt){

}

void Component::Render(){
}

bool Component::Is(std::string type){
  cout << "\nCheguei aq: "<< __FILE__ << "|" <<  __func__ << ":" << __LINE__ << "\n";
    if(type == "Component")
        return true;
    return false;
}
