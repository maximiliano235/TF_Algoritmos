#pragma once

#include "CCanaval.h"

using namespace System::Drawing;

class CMartillo
{
private:
	int X, Y;
	int Ancho, Largo;
	int dX, dY;
	bool Estado;

public:
	CMartillo(int X, int Y, int Ancho, int Largo, int dX, int dY);
	~CMartillo();
	void Dibujar(Graphics^ g, Bitmap^ imgMartillo);
	void Mover(int AnchoF, int LargoF);
	void Set_Estado(bool Estado);
	bool Get_Estado();
	bool HayColision(int pX, int pY);
	bool HayColision(CCanaval* objCanaval);
};

CMartillo::CMartillo(int X, int Y, int Ancho, int Largo, int dX, int dY)
{
	this->X = X;
	this->Y = Y;
	this->Ancho = Ancho;
	this->Largo = Largo;
	this->dX = dX;
	this->dY = dY;
	this->Estado = true;
}

CMartillo::~CMartillo() {}

void CMartillo::Dibujar(Graphics^ g, Bitmap^ imgMartillo)
{
	g->DrawImage(imgMartillo, X, Y+Largo, Ancho, Largo);
}

void CMartillo::Mover(int AnchoF, int LargoF)
{
	if (X + dX < 0 || X + Ancho + dX > AnchoF)
		Estado = false;

	X += dX;
	Y += dY;
}

void CMartillo::Set_Estado(bool Estado)
{
	this->Estado = Estado;
}

bool CMartillo::Get_Estado()
{
	return this->Estado;
}

bool CMartillo::HayColision(int pX, int pY)
{
	return pX >= X && pX <= X + Ancho &&
		pY >= Y && pY <= Y + Largo;
}

bool CMartillo::HayColision(CCanaval* objCanaval)
{
	if (HayColision(objCanaval->Get_X(), objCanaval->Get_Y()) ||
		HayColision(objCanaval->Get_X() + objCanaval->Get_Ancho(),
			objCanaval->Get_Y()) ||
		HayColision(objCanaval->Get_X(), objCanaval->Get_Y() +
			objCanaval->Get_Largo()) ||
		HayColision(objCanaval->Get_X() + objCanaval->Get_Ancho(),
			objCanaval->Get_Y() + objCanaval->Get_Largo()) ||
		objCanaval->HayColision(X, Y, Ancho, Largo))
	{
		objCanaval->Set_Estado(false);
		this->Estado = false;
		return true;
	}

	return false;
}