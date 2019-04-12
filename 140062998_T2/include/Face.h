#ifndef FACE_H
#define FACE_H

#define INCLUDE_SDL
#include "SDL_include.h"

#include "GameObject.h"
#include "Sound.h"

#include<iostream>
#include<string>

using namespace std;

class Face : public Component
{
    public:

      Face(GameObject& associated);

      void Damage(int damage);

      void Update(float dt) override;
      void Render() override;
      bool Is(std::string type) override;

    protected:


    private:

      int hitpoints;
      Sound* sound_destroy;

};

#endif // FACE_H
