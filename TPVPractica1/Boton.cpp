#include "Boton.h"



Boton::Boton(JuegoPG* juego, Textura_t text, int x, int y, CallBack_t* cb): ObjetoPG(juego, text, x, y)
{
	rect.w = 30;
	rect.h = 20;
}
void Boton::draw() {
	pJuego->getTextura(texturas)->draw(pJuego->getRender(), rect);
}

Boton::~Boton()
{
}
