#ifndef SOUND_H
#define SOUND_H

#define INCLUDE_SDL
#define INCLUDE_SDL_MIXER
#include "iostream"
#include "string"
#include "SDL_include.h"
#include "GameObject.h"

using namespace std;

class Sound : public Component
{
    public:

      Sound(GameObject& associated);
      Sound(const char* file, GameObject& associated);
      ~Sound();

      void Play(int times = 1);
      void Stop();
      void Open(const char* file);
      bool IsOpen();

      void Update(float dt) override;
      void Render() override;
      bool Is(std::string type) override;


    protected:


    private:

      Mix_Chunk* chunk;
      int channel;

};

#endif // SOUND_H
