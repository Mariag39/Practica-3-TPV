#include "EstadoPG.h"



EstadoPG::EstadoPG(JuegoPG* game)
{
	jg = game;
}
bool EstadoPG::OnClick() {
	bool click = false;
	for (int i = objetos.size() - 1; i >= 0 && (!click); i--) {
		if (objetos[i]->onClick()) {
			click = true;
		}
	}
	return click;
}
void EstadoPG::draw() {
	for (int i = 0; i < objetos.size(); ++i) {
		objetos[i]->draw();
	}
}
void EstadoPG::update() {
	for (int i = 0; i < objetos.size(); ++i) {
		objetos[i]->draw();
	}
}

EstadoPG::~EstadoPG()
{
}
