#pragma once
#include "SDL.h"
#include <iostream>
#include <vector>
#include <exception>
using namespace std;
class Error
{
public:
	Error(string msg);
	//throw exception?
	string msgError = "Error de inicio SDL";
	const string& mensaje();
	~Error();
};

