#pragma once
#ifndef _H_MenuPG_H_
#define _H_MenuPG_H_
#include "EstadoPG.h"
#include "Boton.h"
#include "JuegoPG.h"
using namespace std;
class MenuPG :
	public EstadoPG
{
public:
	MenuPG(JuegoPG* juego);
	static void exit(JuegoPG* game);
	static void play(JuegoPG* game);
	void initboton();
	virtual void draw();
	
	
	//boton exit y play
	//funcion de tipo callback para cada funcion
	~MenuPG();
private:
	int x, y;
	JuegoPG* gueim;
};
#endif

