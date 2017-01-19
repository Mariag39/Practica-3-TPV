#pragma once
#include "EstadoPG.h"
#include "JuegoPG.h"
#include "SDL.h"
#include "Sound.h"
#include "TexturaSDL.h"
#include "GlobosPG.h"
#include "Premio.h"
#include "GameOver.h"
#include "Mariposa.h"
#include <iostream>
#include "SDL_image.h"
#include <vector>
#include <time.h>
class PlayPG :
	public EstadoPG
{
public:
	PlayPG(JuegoPG* juego);
	~PlayPG();
	void newBaja(ObjetoJuego* po);
	void newPuntos(ObjetoJuego* po);
	void newPremio(ObjetoJuego* po);
	
protected:
	virtual void draw();
	bool initObjetos();
	int numGlobos;
	int punts;
	int x;
	int y;
	int premios;
	int numMariposas;
	vector<ObjetoJuego*> objetosvec;

};

