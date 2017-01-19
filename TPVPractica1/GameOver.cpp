#include "GameOver.h"



GameOver::GameOver(JuegoPG* juego)
{
}
void GameOver::initboton() {
	x = SCREEN_HEIGHT / 2;
	y = SCREEN_WIDTH / 2;
	objetos.emplace_back(new Boton(gueim, TExit, x, y - 10, Menu(gueim)));
	objetos.emplace_back(new Boton(gueim, TPlay, x, y + 5, Score(gueim)));
}

GameOver::~GameOver()
{
}
