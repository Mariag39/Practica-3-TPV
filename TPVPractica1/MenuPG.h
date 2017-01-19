#pragma once
#ifndef _H_MenuPG_H_
#define _H_MenuPG_H_
#include "EstadoPG.h"
#include "Boton.h"
#include "JuegoPG.h"
#include "PlayPG.h"
using namespace std;
class MenuPG :
	public EstadoPG
{
public:
	MenuPG(JuegoPG* juego);
	static void exit(JuegoPG* game) {
		game->setSalir();
	}
	static void play(JuegoPG* game) {
		game->changeState(new PlayPG(game));
	}
	void initboton();

	~MenuPG();
private:
	int x, y;

};
#endif

