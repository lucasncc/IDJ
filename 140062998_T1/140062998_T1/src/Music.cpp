#include "Music.h"
#include <stdio.h>
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"


Music::Music(){
    music = nullptr;
}


Music::Music(const char* file){
    music = nullptr;
    Open(file);
}


void Music::Play (int times){
    if(music == nullptr){
        std::cout << "SDL Error: SDL_MUSIC_PLAY error" << SDL_GetError() << std::endl;
        exit(1);
    }

    Mix_PlayMusic(music, times);
}


void Music::Stop (int msToStop){
    Mix_FadeOutMusic(msToStop);
}


void Music::Open (const char* file){
    if(file == nullptr){
        std::cout << "SDL Error: SDL_MUSIC_OPEN error" << SDL_GetError() << std::endl;
        exit(1);
    }

    music = Mix_LoadMUS(file);
}


bool Music::IsOpen (){
    if(music == nullptr){
        return true;
    }
    return false;
}

Music::~Music(){
    Stop(msToStop);
}


