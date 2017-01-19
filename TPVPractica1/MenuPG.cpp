#include "MenuPG.h"




MenuPG::MenuPG(JuegoPG* juego): EstadoPG(juego)
{
	initboton();
}

void MenuPG::initboton() {
	x = SCREEN_HEIGHT / 2;
	y = SCREEN_WIDTH / 2;
	objetos.emplace_back(new Boton(jg, TExit, x, y - 10, exit));
	objetos.emplace_back(new Boton(jg, TPlay, x, y + 5, play));
}
MenuPG::~MenuPG()
{
	delete objetos[0];
	delete objetos[1];
}
