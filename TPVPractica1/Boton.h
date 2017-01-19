#pragma once
#include "ObjetoPG.h"

class Boton :
	public ObjetoPG
{
public:
	typedef void CallBack_t(JuegoPG* jg);
	Boton(JuegoPG* juego, Textura_t text, int x, int y, CallBack_t* cb);
	

	~Boton();
	virtual bool OnClick();
	virtual void draw();
	virtual void update();
protected:
	
	CallBack_t *cb;
	
};

