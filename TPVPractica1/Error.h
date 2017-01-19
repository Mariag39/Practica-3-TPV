#pragma once
#ifndef _H_Error_H_
#define _H_Error_H_
#include "SDL.h"
#include "JuegoPG.h"
#include <iostream>
#include <vector>
#include <exception>
using namespace std;
class Error
{
public:
	Error(string const& msg);
	const string& mensaje();
	virtual ~Error();
protected:
	string msgError = "Error de inicio SDL";
};
#endif

