#pragma once
#ifndef _H_Pausa_H_
#define _H_Pausa_H_
#include "EstadoPG.h"
#include "Boton.h"
#include "JuegoPG.h"
#include "MenuPG.h"
using namespace std;
class Pausa :
	public EstadoPG
{
public:
	Pausa(JuegoPG* juego);
	static void Menu(JuegoPG* game) {
		game->changeState(new MenuPG(game));
	}
	static void Resume(JuegoPG* game) {
		game->popState();
	}
	void initboton();
private:
	int x, y;
	

	~Pausa();
};
#endif

