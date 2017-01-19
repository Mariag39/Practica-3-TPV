#pragma once
#ifndef _H_GameOver_H_
#define _H_GameOver_H_
#include "EstadoPG.h"
#include "Boton.h"
using namespace std;
class GameOver :
	public EstadoPG
{
public:
	GameOver(JuegoPG* juego);
	
	static void Menu(JuegoPG* game);
	static void Score(JuegoPG* game);
	void initboton();
	
	~GameOver();
private:
	int x, y;
	JuegoPG* gueim;
};
#endif

