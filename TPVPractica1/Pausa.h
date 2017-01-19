#pragma once
#include "EstadoPG.h"
#include "Boton.h"
using namespace std;
class Pausa :
	public EstadoPG
{
public:
	Pausa(JuegoPG* juego);
	//static void Menu(JuegoPG* game);
	static void Resume(JuegoPG* game);
	void initboton();
private:
	int x, y;
	JuegoPG* gueim;

	~Pausa();
};

