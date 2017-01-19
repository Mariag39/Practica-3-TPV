#include "Pausa.h"



Pausa::Pausa(JuegoPG* juego): EstadoPG(juego)
{
	initboton();
}
void Pausa::initboton() {
	x = SCREEN_HEIGHT / 2;
	y = SCREEN_WIDTH / 2;
	objetos.emplace_back(new Boton(jg, TExit, x, y - 10, Menu));
	objetos.emplace_back(new Boton(jg, TPlay, x, y + 5, Resume));
}

Pausa::~Pausa()
{
	delete objetos[0];
	delete objetos[1];
}
