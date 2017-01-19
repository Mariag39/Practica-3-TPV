#include "JuegoPG.h"
#include "SDL.h"
#include "Sound.h"
#include "TexturaSDL.h"
#include "GlobosPG.h"
#include "Premio.h"
#include "Mariposa.h"
#include <iostream>
#include "SDL_image.h"
#include <vector>
#include <time.h>
using namespace std;

JuegoPG::JuegoPG()
{
	//inicializar vectores
	srand(SDL_GetTicks());
	if (initSDL()) {
		error = false;
	}
	else {
		error = true;
	}
	
	
	

	gameOver = false;

	punts = 0;
	numMariposas = 1;
	premios = numMariposas;
	numGlobos = 20;
	exit = false;
	nombarch.emplace_back("..\\bmps\\sky.png");
	nombarch.emplace_back("..\\bmps\\yellow.png");
	nombarch.emplace_back("..\\bmps\\premio.png");
	nombarch.emplace_back("..\\bmps\\mariposa.png");
	nombarch.emplace_back("..\\bmps\\play_button.png");
	nombarch.emplace_back("..\\bmps\\menu_button.png");
	nombarch.emplace_back("..\\bmps\\exit_button.png");
	nombarch.emplace_back("..\\bmps\\score_button.png");
	nombarch.emplace_back("..\\bmps\\resume_button.png");
	
	
	
	

}
void JuegoPG::Mensaje(string msg1, string msg2) {
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
		msg1.c_str(), msg2.c_str(), nullptr);
}

bool JuegoPG::initSDL() {
	bool success = true; //Initialization flag


						 //Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		throw Error("SDL could not initialize!");
		//cout << "SDL could not initialize! \nSDL_Error: " << SDL_GetError() << '\n';
		success = false;

	}
	else {
		//Create window: SDL_CreateWindow("SDL Hello World", posX, posY, width, height, SDL_WINDOW_SHOWN);
		pWindow = SDL_CreateWindow("SDL Práctica 1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (pWindow == nullptr) {
			throw Error("Window could not be created!");
			//cout << "Window could not be created! \nSDL_Error: " << SDL_GetError() << '\n';
			success = false;
		}
		else {
			//Get window surface:
			pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
			//SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255); //Set background color to black 
			if (pRenderer == nullptr) {
				throw Error("Renderer could not be created!");
				//cout << "Renderer could not be created! \nSDL_Error: " << SDL_GetError() << '\n';
				success = false;
			}
		}
	}

	return success;
}
void JuegoPG::closeSDL() {

	SDL_DestroyRenderer(pRenderer);
	pRenderer = nullptr;

	SDL_DestroyWindow(pWindow);
	pWindow = nullptr;

	SDL_Quit();
}
void JuegoPG::render()  {
	//Clear the window to background color 
	SDL_RenderClear(pRenderer);

	SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
	SDL_Rect rect;
	rect = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };
	objetostext[TFondo]->draw(pRenderer, rect);
	for (int i = 0; i < objetosvec.size(); i++) {
		objetosvec[i]->draw();
	}

	//Show window																			
	SDL_RenderPresent(pRenderer);
}
void JuegoPG::initMedia() {
  
	for (int i = 0; i < 9; i++) {
		objetostext.push_back(new TexturaSDL());
		objetostext[i]->load(pRenderer, nombarch[i]);
	}
}
TexturaSDL* JuegoPG::getTextura(Textura_t et) const{
	return objetostext[et];
}
void JuegoPG::random(int& x, int& y) {
	y = rand() % SCREEN_HEIGHT;
	x = rand() % SCREEN_WIDTH;
	if (y > SCREEN_HEIGHT - 100) y = SCREEN_HEIGHT - 100;
	if (x > SCREEN_WIDTH - 100) x = SCREEN_WIDTH - 100;

}


void JuegoPG::freeMedia() {
	for (unsigned int i = 0; i < objetosvec.size(); i++) {
		if (objetosvec[i] != nullptr) {
			delete objetosvec[i];
			
		}
	}
	for (unsigned int i = 0; i < objetostext.size(); i++) {
		delete objetostext[i];
		
	}
}
void JuegoPG::onClick(){
	bool pinchado = false;
	for (int i = objetosvec.size() - 1; i >= 0; i--) {
		if (objetosvec[i]->onClick()) {
			pinchado = true;
		}
	}
}
void JuegoPG::getMousePos(int& mpx, int& mpy) const{
	mpx = x;
	mpy = y;
}

void JuegoPG::update() {
	for (int i = 0; i < objetosvec.size(); ++i) {
		objetosvec[i]->update();
	}
	if (numGlobos <= 0) {
		gameOver = true;
	}
}

void JuegoPG::onExit() {
	exit = true;
	cout << "EXIT ";
}
void JuegoPG::setSalir() {
	popState();
	exit = true;
}

void JuegoPG::pushState(EstadoJuego* newState) {
	estados.push(newState);
}
void JuegoPG::changeState(EstadoJuego* newSt) {
	popState();
	pushState(newSt);
}

void JuegoPG::popState() {
	delete topEstado();
	estados.pop();
}

EstadoJuego* JuegoPG::topEstado() {
	return estados.top();
}
void JuegoPG::run() {
	pushState(new MenuPG(this));
	
	if (!error) {
		Uint32 MSxUpdate = 500;
		cout << "PLAY\n";
		Uint32 lastUpdate = SDL_GetTicks();
		Mensaje("PLAY","Ready?");
		initMedia();
		render();
		handle_event();
		while (!exit && !gameOver) {
			if (SDL_GetTicks() - lastUpdate >= MSxUpdate) {
				update();
				lastUpdate = SDL_GetTicks();
			}
			render();
			handle_event();
		}

		SDL_Delay(1000);
		
		cin.get();
	}
}

void JuegoPG::handle_event() {
	
	SDL_Event e;
	while (SDL_PollEvent(&e) && !exit) {
		if (e.type == SDL_QUIT) {
			onExit();
		}
	else if (e.type == SDL_MOUSEBUTTONUP) {
		if (e.button.button == SDL_BUTTON_LEFT) {
			cout << "CLICK";
			x = e.button.x;
			y = e.button.y;
			onClick();
		}
	}
	else if (e.type == SDL_KEYUP) {
		if (e.key.keysym.sym == SDLK_p) {
			//si se pulsa pausa
		}
		else if (e.key.keysym.sym == SDLK_ESCAPE && dynamic_cast<PlayPG*>(topEstado())) {
			pushState(new Pausa(this));
		}
	}
}
}


JuegoPG::~JuegoPG()
{
	freeMedia ();
	closeSDL();
	
	
}
