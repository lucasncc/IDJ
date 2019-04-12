#ifndef SPRITE_H
#define SPRITE_H

#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#include "SDL_include.h"
#include <iostream>
#include <string>

#include "GameObject.h"

using namespace std;

class Sprite : public Component
{
    public:

        Sprite(GameObject& associated);
        Sprite(const char* file, GameObject& associated);
        ~Sprite();
        void Open(const char* file);
        void SetClip(int x, int y, int w, int h);
        void Render() override;
        void Render(int x, int y);
        int GetWidth();
        int GetHeight();
        bool IsOpen();

        void Update(float dt) override;
        bool Is(std::string type) override;


    protected:


    private:
        SDL_Texture* texture;
        int width;
        int height;
        SDL_Rect clipRect;

};

#endif // SPRITE_H
