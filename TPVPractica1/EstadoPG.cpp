#include "EstadoPG.h"



EstadoPG::EstadoPG()
{
}
bool EstadoPG::onClick() {
	bool click = false;
	for (int i = objetos.size() - 1; i >= 0 && (!click); i--) {
		if (objetos[i]->onClick()) {
			click = true;
		}
	}
	return click;
}

EstadoPG::~EstadoPG()
{
}
