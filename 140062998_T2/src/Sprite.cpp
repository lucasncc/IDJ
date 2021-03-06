#include "Sprite.h"
#include <stdio.h>
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include "Game.h"


Sprite::Sprite(GameObject& associated):Component (associated){
    texture = nullptr;
}


Sprite::Sprite(const char* file, GameObject& associated):Component (associated){
    texture = nullptr;
    Open(file);
}


Sprite::~Sprite(){
    SDL_DestroyTexture(texture);
}


void Sprite::Open(const char* file){

    if(texture != nullptr){
        SDL_DestroyTexture(texture);
    }

    texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file);

    if(texture == nullptr){
        std::cout << "SDL Error: IMG_LoadTexture error" << SDL_GetError() << std::endl;
        exit(1);
    }

    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);

    SetClip(0, 0, width, height);

    this->associated.box.h = height;
    this->associated.box.w = width;
}


void Sprite::SetClip(int x, int y, int w, int h){
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}

void Sprite::Render(){
    Render(this->associated.box.x, this->associated.box.y);
}


void Sprite::Render(int x, int y){

    SDL_Rect dstrect;

    dstrect.x = x;
    dstrect.y = y;
    dstrect.w = clipRect.w;
    dstrect.h = clipRect.h;

    SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &dstrect);
}


int Sprite::GetWidth(){
    return width;
}



int Sprite::GetHeight(){
    return height;
}



bool Sprite::IsOpen(){
    if(texture != nullptr){
        return true;
    }
    return false;
}

bool Sprite::Is(std::string type){
    if(type == "Sprite")
        return true;
    return false;
}


void Sprite::Update(float dt){


}
