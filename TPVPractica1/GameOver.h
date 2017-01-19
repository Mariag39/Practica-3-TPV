#pragma once
#ifndef _H_GameOver_H_
#define _H_GameOver_H_
#include "EstadoPG.h"
#include "Boton.h"
#include "MenuPG.h"
using namespace std;
class GameOver :
	public EstadoPG
{
public:
	
	GameOver(JuegoPG* juego, int punts);
	
	static void Menu(JuegoPG* game) {
		game->changeState(new MenuPG(game));
	}
	static void Score(JuegoPG* game) {
		string puntuacion = "Puntuacion: ";
		puntuacion += to_string(puntos);
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Fin!!", puntuacion.c_str(), nullptr);
	}
	
	
	~GameOver();
protected:
	int x, y;
	void initboton();
	static int puntos;
};
#endif

