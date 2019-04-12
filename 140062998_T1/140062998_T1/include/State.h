#ifndef STATE_H
#define STATE_H

#define INCLUDE_SDL

#include "Music.h"
#include "Sprite.h"

#include "SDL_include.h"
#include <iostream>
#include <string>
using namespace std;

class State
{
    public:

        State();
        bool QuitRequested();
        void LoadAssets();
        void Update(float dt);
        void Render();

    protected:


    private:

        Sprite bg;
        Music music;
        bool quitRequested;

};

#endif // STATE_H




