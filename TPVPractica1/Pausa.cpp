#include "Pausa.h"



Pausa::Pausa(JuegoPG* juego)
{
}
void Pausa::initboton() {
	x = SCREEN_HEIGHT / 2;
	y = SCREEN_WIDTH / 2;
	objetos.emplace_back(new Boton(gueim, TExit, x, y - 10, Menu(gueim)));
	objetos.emplace_back(new Boton(gueim, TPlay, x, y + 5, Resume(gueim)));
}

Pausa::~Pausa()
{
}
