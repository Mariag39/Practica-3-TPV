#include "GameOver.h"

int GameOver::puntos = 0;

GameOver::GameOver(JuegoPG* juego, int punts): EstadoPG(juego)
{
	puntos = punts;
	initboton();
}
void GameOver::initboton() {
	x = SCREEN_HEIGHT / 2;
	y = SCREEN_WIDTH / 2;
	objetos.emplace_back(new Boton(jg, TExit, x, y - 10, Menu));
	objetos.emplace_back(new Boton(jg, TPlay, x, y + 5, Score));
}

GameOver::~GameOver()
{
	delete objetos[0];
	delete objetos[1];
}
