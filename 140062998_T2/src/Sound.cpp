#include "Sound.h"
#include <stdio.h>
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include "GameObject.h"

Sound::Sound(GameObject& associated):Component (associated){
//    associated;
    chunk = nullptr;
}

Sound::Sound(const char* file, GameObject& associated):Component (associated){
    Sound(this->associated);
    Open(file);
}

Sound::~Sound(){
    if(this->chunk != nullptr)
      Mix_HaltChannel(this->channel);
    Mix_FreeChunk(this->chunk);
}

void Sound::Play(int times){
  if(this->chunk == nullptr){
      std::cout << "SDL Error: SDL_SOUND_PLAY error" << SDL_GetError() << std::endl;
      exit(1);
  }
  this->channel = Mix_PlayChannel(-1, this->chunk, times);
}

void Sound::Stop(){
  if(this->chunk != nullptr)
    Mix_HaltChannel(this->channel);
}

void Sound::Open(const char* file){
  if(file == nullptr){
      std::cout << "SDL Error: SDL_SOUND_OPEN error" << SDL_GetError() << std::endl;
      exit(1);
  }
  this->chunk = Mix_LoadWAV(file);
}

bool Sound::IsOpen(){
  if(this->chunk == nullptr){
      return true;
  }
  return false;
}

void Sound::Update(float dt){

}

void Sound::Render(){

}

bool Sound::Is(std::string type){
  if(type == "Sound")
      return true;
  return false;
}
