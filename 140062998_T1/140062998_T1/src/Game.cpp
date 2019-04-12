#include "Game.h"
#include <stdio.h>
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include <SDL2/SDL_audio.h>


Game* Game::instance = nullptr;

Game::Game(const char* title, int width, int height){
    if(instance != nullptr){
        std::cout << "SDL Error: Instacia do SDL duplicada" << SDL_GetError() << std::endl;
        exit(1);
    }

    instance = this;

    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0){
        std::cout << "SDL Error: SDL_INIT error" << SDL_GetError() << std::endl;
        exit(1);
    }

    if(IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF) == 0){
        std::cout << "SDL Error: IMG_INIT error" << SDL_GetError() << std::endl;
        exit(1);
    }

    if(Mix_Init(MIX_INIT_OGG | MIX_INIT_MP3) == 0){
        std::cout << "SDL Error: Mix_Init error" << SDL_GetError() << std::endl;
        //exit(1); linha comentada por estar dando bug no sdl, por sugestao do monitor
    }

    if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) != 0){
        std::cout << "SDL Error: Mix_OpenAudio error" << SDL_GetError() << std::endl;
        exit(1);
    }

    if(Mix_AllocateChannels(32) != 32){
        std::cout << "SDL Error: Mix_AllocateChannels error" << SDL_GetError() << std::endl;
        exit(1);
    }

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

     if(window == nullptr){
        std::cout << "SDL Error: SDL_CreateWindow error" << SDL_GetError() << std::endl;
        exit(1);
     }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if(renderer == nullptr){
        std::cout << "SDL Error: SDL_CreateRenderer error" << SDL_GetError() << std::endl;
        exit(1);
    }

    state = new State();




}

Game::~Game(){
    //dtor
    IMG_Quit();
    Mix_CloseAudio();
    Mix_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


Game& Game::GetInstance(){
            if(instance != nullptr)
                return *instance;
            else
                Game* instance = new Game("Lucas Cardoso 140062998", 1024, 600);
}

SDL_Renderer* Game::GetRenderer(){
        return renderer;
}

State& Game::GetState(){
        return *state;
}

void Game::Run(){
    while(Game::GetState().QuitRequested() != true){
        Game::GetState().Update(0);
        Game::GetState().Render();
        SDL_RenderPresent(renderer);
        SDL_Delay(33);
    }
}


