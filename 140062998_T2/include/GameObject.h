#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#define INCLUDE_SDL
#include "SDL_include.h"

#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include "Rect.h"
#include "Component.h"

using namespace std;

class GameObject
{
    public:

        GameObject();
        ~GameObject();

        void Update(float dt);
        void Render();
        bool Is(std::string type);
        bool IsDead();
        void RequestDelete();
        void AddComponent(Component* cpt);
        void RemoveComponent(Component* cpt);
        Component* GetComponent(std::string type);

        Rect box;


    protected:



    private:

      std::vector<std::shared_ptr<Component>> components;
      bool isDead;

};

#endif // GAMEOBJECT_H
