#include "State.h"
#include <stdio.h>
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include "Music.h"


//State::State(){
State::State() : bg("./assets/img/ocean.jpg"), music("./assets/audio/stageState.ogg") {
    quitRequested = false;
    //music = Music("./assets/audio/stageState.ogg"); substituido na chamada da funcao
    music.Play(-1);
    //bg = Sprite("./assets/img/ocean.jpg"); substituido na chamada da funcao
}

void State::LoadAssets(){
}

void State::Render(){
    bg.Render(0,0);
}

void State::Update(float dt){
    if(SDL_QuitRequested() == true){
        //intf("Cheguei aqui: %s|%s:%d\n", __FILE__, __func__, __LINE__);
        quitRequested = true;
    }
}

bool State::QuitRequested(){
    return quitRequested;
}
