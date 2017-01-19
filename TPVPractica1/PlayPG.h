#pragma once
#include "EstadoPG.h"
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
class PlayPG :
	public EstadoPG
{
public:
	PlayPG();
	~PlayPG();
	void newBaja(ObjetoJuego* po);
	void newPuntos(ObjetoJuego* po);
	void newPremio(ObjetoJuego* po);
	virtual void draw() const;
	virtual bool onClick();
	virtual void update();
	bool initObjetos();
private:

};

