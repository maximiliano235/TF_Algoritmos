#pragma once

using namespace System;
using namespace System::Drawing;

class CFondoJuego
{
private:
	int X, Y;

public:
	CFondoJuego(int X, int Y);
	~CFondoJuego();
	void Dibujar(Graphics^ g, Bitmap^ imgFondo);
};

CFondoJuego::CFondoJuego(int X, int Y)
{
	this->X = X;
	this->Y = Y;
}

CFondoJuego::~CFondoJuego()
{
}

void CFondoJuego::Dibujar(Graphics^ g, Bitmap^ imgFondo)
{
	// HUD
	Rectangle OrigenF = Rectangle(0, 0, imgFondo->Width, imgFondo->Height);
	Rectangle DestinoF = Rectangle(X, Y, 1459, 896);

	g->DrawImage(imgFondo, DestinoF, OrigenF, GraphicsUnit::Pixel);
}