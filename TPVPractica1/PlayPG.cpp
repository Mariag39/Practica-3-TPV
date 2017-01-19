#include "PlayPG.h"



PlayPG::PlayPG()
{
}
void PlayPG::newBaja(ObjetoJuego* po) {
	if (dynamic_cast<GlobosPG*>(po)) {
		numGlobos--;

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
void PlayPG::newPremio() {

	dynamic_cast<Premio*>(objetosvec[objetosvec.size() - 1])->visible = true;

}
bool PlayPG::initObjetos() {

	int x;
	int y;
	for (int i = 0; i < numGlobos; i++) {

		x = rand() % (SCREEN_HEIGHT - 5);
		y = rand() % (SCREEN_WIDTH - 5);
		objetosvec.push_back(new GlobosPG(TGlobo, x, y, this));
	}
	for (int i = 0; i < numMariposas; i++) {

		x = rand() % (SCREEN_HEIGHT - 5);
		y = rand() % (SCREEN_WIDTH - 5);
		objetosvec.push_back(new Mariposa(TMariposa, x, y, this));
	}
	x = rand() % (SCREEN_HEIGHT - 5);
	y = rand() % (SCREEN_WIDTH - 5);
	objetosvec.push_back(new Premio(TPremio, x, y, this));
	return true;
}

PlayPG::~PlayPG()
{
}
