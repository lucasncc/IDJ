#include "GameObject.h"
#include <stdio.h>
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"


GameObject::GameObject(){
    isDead = false;
}


GameObject::~GameObject(){
    unsigned int i = 0;
    for(i = this->components.size(); i > 0; --i){
      this->components.erase(components.begin()+i);
    }
    this->components.clear();
}//Adaptar para pilha

void GameObject::Update(float dt){
  for(unsigned int i = 0; i < this->components.size(); i++){
      this->components[i]->Update(dt);
  }
}


void GameObject::Render(){
  for(int i = 0; i < (int)components.size(); i++){
      components[i]->Render();
  }
}


bool GameObject::IsDead(){
    return isDead;
}


void GameObject::RequestDelete(){
    isDead = true;
}


void GameObject::AddComponent(Component* cpt){
    this->components.emplace_back(cpt);
}


void GameObject::RemoveComponent(Component* cpt){
  unsigned int i = 0;
  std::shared_ptr<Component>& tmp = *(new std::shared_ptr<Component>(cpt));
  for(i = 0; this->components[i] != tmp || i < this->components.size(); i++){
  }
  if(this->components[i] == tmp){
      cout << "\nRemovendo objeto\n";
      this->components.erase(components.begin()+i);
  }
}//Adaptar para pilha


Component* GameObject::GetComponent(std::string type){
  //unsigned int i = 0;
  auto it = this->components.begin();
  cout << "\nCheguei aq: "<< __FILE__ << "|" <<  __func__ << ":" << __LINE__ << "\n";


  while(it != this->components.end()){
    cout << "\nCheguei aq: "<< __FILE__ << "|" <<  __func__ << ":" << __LINE__ << "\n";


    if((*it)->Is(type) == true)
    cout << "\nCheguei aq: "<< __FILE__ << "|" <<  __func__ << ":" << __LINE__ << "\n";
      return (*it).get();
    it++;
    //i++;
  }
  return nullptr;
}



bool GameObject::Is(std::string type){
    if(type == "GameObject")
        return true;
    return false;
}
