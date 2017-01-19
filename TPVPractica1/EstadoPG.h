#pragma once
#include "JuegoPG.h"
#include "EstadoJuego.h"
#include "ObjetoJuego.h"
using namespace std;
class EstadoPG :
	public EstadoJuego
{
public:
	EstadoPG();
	EstadoPG(JuegoPG* game);
	virtual bool OnClick();
	virtual void update();
	
	
	virtual ~EstadoPG();
protected:
	int x, y;
	JuegoPG* jg;
	vector<ObjetoJuego*> objetos;
};

