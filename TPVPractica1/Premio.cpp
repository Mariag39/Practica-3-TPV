#ifndef _H_Premio_H_
#define _H_Premio_H_
#include "Premio.h"
#include "JuegoPG.h"


Premio::Premio(Textura_t text, int x, int y, JuegoPG* juego) : ObjetoPG(juego,text,x,y)
{
	visible = false;
	pp = ini;
	rect.w = rect.h = 50;
	
}


bool Premio::onClick() {
	if (ObjetoPG::onClick()) {
		if (dynamic_cast<PlayPG*>(pJuego->topEstado())) {
			dynamic_cast<PlayPG*>(pJuego->topEstado())->newPuntos(this);
			dynamic_cast<PlayPG*>(pJuego->topEstado())->newBaja(this);
		}
		reinicio();
		return true;
	}
	else if (visible) {
		if (oport < 3)
			oport++;
	}
	else {
		if (dynamic_cast<PlayPG*>(pJuego->topEstado())) {
			dynamic_cast<PlayPG*>(pJuego->topEstado())->newBaja(this);
		}
		//reinicio();
	}
	return false;
}

void Premio::reinicio() {
	pp = ini;
	oport = 0;
	pJuego->random(rect.x, rect.y);
	visible = false;
}
void Premio::update() {
	pp -= 1;
}
int Premio::getPuntos() {
	return pp;
}
Premio::~Premio()
{ 
	//delete guarever
}

#endif