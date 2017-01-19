#include "MenuPG.h"




MenuPG::MenuPG(JuegoPG* juego): gueim(juego)
{
	
}

void MenuPG::initboton() {
	x = SCREEN_HEIGHT / 2;
	y = SCREEN_WIDTH / 2;
	objetos.emplace_back(new Boton(gueim, TExit, x, y - 10, exit(gueim)));
	objetos.emplace_back(new Boton(gueim, TPlay, x, y + 5, play(gueim)));
}
MenuPG::~MenuPG()
{
}
