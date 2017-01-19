#pragma once
#include "JuegoPG.h"
#include "EstadoJuego.h"
#include "ObjetoJuego.h"
using namespace std;
class EstadoPG :
	public EstadoJuego
{
public:
	EstadoPG(JuegoPG* game);
	virtual bool OnClick();
	virtual void update();
	virtual void draw();
	
	virtual ~EstadoPG();
protected:
	int x, y;
	JuegoPG* jg;
	vector<ObjetoJuego*> objetos;
};

