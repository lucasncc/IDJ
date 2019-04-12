#ifndef GAME_H
#define GAME_H

#define INCLUDE_SDL
#include "SDL_include.h"

#include "State.h"

#include <iostream>
#include <string>
using namespace std;

class Game
{
    public:

        void Run();
        ~Game();
        static Game& GetInstance();
        State& GetState();
        SDL_Renderer* GetRenderer();


    protected:


    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        State* state;
        static Game* instance;

        Game(const char* title, int width, int height);


};

#endif // GAME_H




