#pragma once
class EstadoJuego
{
public:

	EstadoJuego()
	{
	}
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual bool OnClick() = 0;
	
	virtual ~EstadoJuego()
	{
	}
};

