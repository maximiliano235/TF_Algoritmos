#pragma once

using namespace System;
using namespace System::Drawing;

class CFondo
{
private:
	int X, Y;

public:
	CFondo(int X, int Y);
	~CFondo();
	void Dibujar(Graphics^ g, Bitmap^ imgFondo, Bitmap^ imgRojo, Bitmap^ imgContinuar);
};

CFondo::CFondo(int X, int Y)
{
	this->X = X;
	this->Y = Y;
}

CFondo::~CFondo()
{
}

void CFondo::Dibujar(Graphics^ g, Bitmap^ imgFondo, Bitmap^ imgRojo, Bitmap^ imgContinuar)
{
	// HUD
	Rectangle OrigenF = Rectangle(0, 0, imgFondo->Width, imgFondo->Height);
	Rectangle OrigenC = Rectangle(0, 0, imgContinuar->Width, imgContinuar->Height);
	Rectangle DestinoF = Rectangle(X, Y, imgFondo->Width*2, imgFondo->Height*2);
	Rectangle DestinoC = Rectangle(300, 300, 800, 300);

	g->DrawImage(imgFondo, DestinoF, OrigenF, GraphicsUnit::Pixel);
	g->DrawImage(imgRojo, DestinoF, OrigenF, GraphicsUnit::Pixel);
	g->DrawImage(imgContinuar, DestinoC, OrigenC, GraphicsUnit::Pixel);
}