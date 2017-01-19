#include "PlayPG.h"



PlayPG::PlayPG(JuegoPG* juego): EstadoPG(juego)
{
	initObjetos();
	numGlobos = 20;
	numMariposas = 1;
}
void PlayPG::newBaja(ObjetoJuego* po) {
	if (dynamic_cast<GlobosPG*>(po)) {
		numGlobos--;
		if (numGlobos == 0) {
			jg->changeState(new GameOver(jg, punts));
		}

	}

	else if (dynamic_cast<Premio*>(po)) {
		dynamic_cast<Premio*>(po)->visible = false;
	}
}
void PlayPG::newPuntos(ObjetoJuego* po) {
	if (dynamic_cast<GlobosPG*>(po)) {
		punts += dynamic_cast<GlobosPG*>(po)->getPuntos();
	}
	else if (dynamic_cast<Premio*>(po)) {
		punts += dynamic_cast<Premio*>(po)->getPuntos();
	}

}
void PlayPG::newPremio(ObjetoJuego* po) {

	dynamic_cast<Premio*>(objetosvec[objetosvec.size() - 1])->visible = true;

}
bool PlayPG::initObjetos() {

	int x;
	int y;
	for (int i = 0; i < numGlobos; i++) {

		x = rand() % (SCREEN_HEIGHT - 5);
		y = rand() % (SCREEN_WIDTH - 5);
		objetosvec.push_back(new GlobosPG(TGlobo, x, y, jg));
	}
	for (int i = 0; i < numMariposas; i++) {

		x = rand() % (SCREEN_HEIGHT - 5);
		y = rand() % (SCREEN_WIDTH - 5);
		objetosvec.push_back(new Mariposa(TMariposa, x, y, jg));
	}
	x = rand() % (SCREEN_HEIGHT - 5);
	y = rand() % (SCREEN_WIDTH - 5);
	objetosvec.push_back(new Premio(TPremio, x, y, jg));
	return true;
}
void PlayPG::draw() {
	SDL_Rect rect;
	rect = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };
	jg->objetostext[TFondo]->draw(jg->getRender(), rect);
	for (int i = 0; i < objetosvec.size(); i++) {
		objetosvec[i]->draw();
	}
}
PlayPG::~PlayPG()
{
	for (unsigned int i = 0; i < objetosvec.size(); i++) {
		if (objetosvec[i] != nullptr) {
			delete objetosvec[i];

		}
	}
}
