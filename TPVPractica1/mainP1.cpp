//María García Raldúa, Javier Landaburu Sánchez
#include "SDL.h"  // Para utilizar SDL
#include "JuegoPG.h"
#include "Error.h"
#include <iostream>  // la consola: cin / cout
using namespace std; // Para cualificar automaticamente con std:: los identificadores de la librería estandar 


int main(int argc, char* args[]) {
	system("chcp 1252");
	string msg;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	JuegoPG* game = new JuegoPG();
	Error* error = new Error(msg);
	try {
		game->run();
	}
	catch (Error & e) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Error", e.mensaje().c_str(), nullptr);
	}
	delete game;
	//cout << " ¡Error!\n Pulsa ENTER para cerrar";  cin.ignore();
	return 0;
}