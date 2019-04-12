#ifndef STATE_H
#define STATE_H

#define INCLUDE_SDL

#include "Music.h"
#include "Sprite.h"
#include "Sound.h"
#include "Face.h"


#include "SDL_include.h"
#include <iostream>
#include <string>
using namespace std;

class State
{
    public:

        State();
        ~State();
        bool QuitRequested();
        void LoadAssets();
        void Update(float dt);
        void Render();

    protected:


    private:

        //Sprite bg;
        Music music;
        //Sound sound;
        bool quitRequested;

        void Input();
        void AddObject(int mouseX, int mouseY);

        std::vector<std::shared_ptr<GameObject>> objectArray;


};

#endif // STATE_H
