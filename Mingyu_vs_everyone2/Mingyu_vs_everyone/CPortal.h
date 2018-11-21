#pragma once
using namespace System;
using namespace System::Drawing;

class CPortal
{
private:
	int X, Y;
	int Indice;
	bool teletransportar;

public:
	CPortal(int X, int Y);
	~CPortal();
	void Dibujar(Graphics^ g, Bitmap^ imgPortal);
	int Get_X();
	int Get_Y();
	int Get_Ancho();
	int Get_Largo();
};

CPortal::CPortal(int X, int Y)
{
	this->X = X;
	this->Y = Y;
	this->Indice = 0;
}

CPortal::~CPortal()
{
}

void CPortal::Dibujar(Graphics^ g, Bitmap^ imgPortal)
{
	Indice++;
	if (Indice > 8) {
		Indice = 0;
	}

	// Portal
	Rectangle OrigenF = Rectangle(Indice*111, 0, imgPortal->Width/9, imgPortal->Height);
	Rectangle DestinoF = Rectangle(X, Y, 300, 300);

	g->DrawImage(imgPortal, DestinoF, OrigenF, GraphicsUnit::Pixel);
}

int CPortal::Get_X()
{
	return this->X;
}

int CPortal::Get_Y()
{
	return this->Y;
}

int CPortal::Get_Ancho()
{
	return 300;
}

int CPortal::Get_Largo()
{
	return 300;
}