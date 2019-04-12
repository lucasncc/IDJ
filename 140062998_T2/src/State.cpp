#include "State.h"
#include <stdio.h>
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include "Music.h"
#include "Rect.h"
#include "Vec2.h"

//#define PI 3.14

using namespace std;

const float PI = 3.14;

//State::State(){
State::State() : music("./assets/audio/stageState.ogg") {
    GameObject* go = new GameObject();
    go->box.x = 0;
    go->box.y = 0;
    Sprite* bg = new Sprite("./assets/img/ocean.jpg", *go);
    go->AddComponent(bg);
    objectArray.emplace_back(go);

    quitRequested = false;
    //music = Music("./assets/audio/stageState.ogg"); substituido na chamada da funcao
    music.Play(-1);
    //bg = Sprite("./assets/img/ocean.jpg"); substituido na chamada da funcao
}

State::~State(){
  for(unsigned int i = this->objectArray.size(); i > 0; --i){
    this->objectArray.erase(objectArray.begin()+i);
  }
  this->objectArray.clear();
}

void State::LoadAssets(){
}

void State::Render(){
    //bg.Render(0,0);
    for(int i = 0; i < (int)objectArray.size(); i++){
        objectArray[i]->Render();
    }
}

void State::Update(float dt){
    Input();
    for(unsigned int i = 0; i < this->objectArray.size(); i++){
        objectArray[i]->Update(dt);
        if(this->objectArray[i] == nullptr)
            objectArray.erase(objectArray.begin()+i);
    }
    if(SDL_QuitRequested() == true){
        //printf("Cheguei aqui: %s|%s:%d\n", __FILE__, __func__, __LINE__);
        quitRequested = true;
    }
}

bool State::QuitRequested(){
    return quitRequested;
}

void State::Input() {
  	SDL_Event event;
  	int mouseX, mouseY;

  	// Obtenha as coordenadas do mouse
  	SDL_GetMouseState(&mouseX, &mouseY);

  	// SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
  	while (SDL_PollEvent(&event)) {

      // Se o evento for quit, setar a flag para terminação
    if(event.type == SDL_QUIT) {
  			quitRequested = true;
  		}

  		// Se o evento for clique...
  		if(event.type == SDL_MOUSEBUTTONDOWN) {
        //cout << "\nCheguei aq: "<< __FILE__ << "|" <<  __func__ << ":" << __LINE__ << "\n";

  			// Percorrer de trás pra frente pra sempre clicar no objeto mais de cima
  			for(int i = objectArray.size() - 1; i >= 0; --i) {
  				// Obtem o ponteiro e casta pra Face.
  				GameObject* go = (GameObject*) objectArray[i].get();
  				// Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
  				// O propósito do unique_ptr é manter apenas uma cópia daquele ponteiro,
  				// ao usar get(), violamos esse princípio e estamos menos seguros.
  				// Esse código, assim como a classe Face, é provisório. Futuramente, para
  				// chamar funções de GameObjects, use objectArray[i]->função() direto.

          //cout << "\nCheguei aq: "<< __FILE__ << "|" <<  __func__ << ":" << __LINE__ << "\n";
  				if(go->box.Contains((float)mouseX, (float)mouseY)) {
            //cout << "\nCheguei aq: "<< __FILE__ << "|" <<  __func__ << ":" << __LINE__ << "\n";
  					Face* face = (Face*)go->GetComponent( "Face" );
  					if ( nullptr != face ) {
  						// Aplica dano
  						//face->Damage(std::rand() % 10 + 10);
              face->Damage(10);
              cout << "\nCheguei aq: "<< __FILE__ << "|" <<  __func__ << ":" << __LINE__ << "\n";
  						// Sai do loop (só queremos acertar um)
  						break;
  					}
  				}
  			}
  		}
  		if( event.type == SDL_KEYDOWN ) {
  			// Se a tecla for ESC, setar a flag de quit
  			if( event.key.keysym.sym == SDLK_ESCAPE ) {
  				quitRequested = true;
  			}
  			// Se não, crie um objeto
  			else {
  				Vec2 objPos = Vec2( 200.0, 0.0 ).GetRotated( -PI + PI*(rand() % 1001)/500.0 ) + Vec2( (float)mouseX, (float)mouseY );
  				AddObject((int)objPos.x, (int)objPos.y);
  			}
  		}
  	}
}



void State::AddObject(int mouseX, int mouseY){
    GameObject* go = new GameObject();
    go->box.x = mouseX;
    go->box.y = mouseY;

    //Sprite* enemy = (Sprite*)go.Sprite("./assets/img/penguinface.png", go);
    //Sound* sound_destroy = (Sound*)go.Sound("./assets/audio/boom.wav", go);
    //Face* face = (Face*)go.Face(go);

    Sprite* enemy = new Sprite("./assets/img/penguinface.png", *go);
    Sound* sound_destroy = new Sound("./assets/audio/boom.wav", *go);
    Face* face = new Face(*go);

    go->AddComponent(enemy);
    go->AddComponent(sound_destroy);
    go->AddComponent(face);

    objectArray.emplace_back(go);


}
