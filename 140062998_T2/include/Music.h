#ifndef MUSIC_H
#define MUSIC_H

#define INCLUDE_SDL
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include <iostream>
#include <string>
using namespace std;

class Music
{
    public:

    int times = -1;
    int msToStop = 1500;

    Music();
    Music(const char* file);
    ~Music();
    void Play (int times);
    void Stop (int msToStop);
    void Open (const char* file);
    bool IsOpen ();


    protected:


    private:

    Mix_Music* music;

};

#endif // MUSIC_H




