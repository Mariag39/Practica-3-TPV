#pragma once
#include "SDL.h"
#include <vector>
#include <stack> 
#include "SDL_image.h"
#include "Sound.h"
#include "Error.h"
#include "EstadoJuego.h"
#include "TexturaSDL.h"
#include "ObjetoJuego.h"
#include "MenuPG.h"
#include "Pausa.h"
using namespace std;

static const int SCREEN_WIDTH = 640;   //Screen dimension
static const int SCREEN_HEIGHT = 480;  //Screen dimension
enum Textura_t { TFondo, TGlobo, TPremio, TMariposa, TPlay, TMenu, TExit, TScore, TResume };
class JuegoPG
{
	
public:
	JuegoPG();
	~JuegoPG();
	void run();
	void onExit();
	
	TexturaSDL* getTextura(Textura_t et) const;
	SDL_Renderer* getRender() const { 
		return pRenderer;
	};
	void random(int& x, int& y);
	void getMousePos(int& mpx, int& mpy) const;
	void initMedia(); // carga las texturas en el vector de texturas (fuente y música)  
	void freeMedia();
	void changeState(EstadoJuego* newSt);
	void pushState(EstadoJuego* newState);
	void popState();
	void setSalir();
	vector<TexturaSDL*> objetostext;
	EstadoJuego* topEstado();
	

private:
	
	int x;
	int y;
	int premios;
	int numMariposas;
	bool initSDL();
	Textura_t texturas;
	vector<string> nombarch;
	void closeSDL();
	void Mensaje(string msg1, string msg2);
	void render() ;
	void onClick();
	void update();
	stack<EstadoJuego*> estados;
	void handle_event();
	SDL_Window* pWindow;
	SDL_Renderer* pRenderer;
	SDL_Texture* pTexture;
	
	vector<ObjetoJuego*> objetosvec; //era GlobosPG
	
	
	
	bool error;
	bool exit;
	bool gameOver;
	int punts;
	int numGlobos;

};

