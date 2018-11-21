#pragma once

#include "CCanaval.h"
#include <vector>
#include "CMovimiento.h"
#include <stdio.h>

using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

enum TypeMovimientoFuegoNormal { FuegoNormal };

class CFuegoNormal
{
private:
	CMovimiento *objMovimiento;
	vector<CMovimiento *>* arrMovimiento;
	TypeMovimientoFuegoNormal TipoMovimiento;

	int X, Y;
	int Ancho, Largo;
	int dX, dY;
	bool Estado;
	int Indice;
	int tiempo;

public:
	CFuegoNormal(int X, int Y, int Ancho, int Largo, int dX, int dY);
	~CFuegoNormal();
	void Set_Movimiento(TypeMovimientoFuegoNormal TipoMovimiento);
	void Dibujar(Graphics^ g, Bitmap^ imgFuego);
	void Mover(int AnchoF, int LargoF);
	void Set_Estado(bool Estado);
	bool Get_Estado();
	bool HayColision(int pX, int pY);
	bool HayColision(CCanaval* objCanaval);
};

CFuegoNormal::CFuegoNormal(int X, int Y, int Ancho, int Largo, int dX, int dY)
{
	this->X = X;
	this->Y = Y;
	this->Ancho = Ancho;
	this->Largo = Largo;
	this->dX = dX;
	this->dY = dY;
	this->Estado = true;
	this->Indice = 0;
	this->tiempo = 20;
	this->arrMovimiento = new vector<CMovimiento *>();
	Set_Movimiento(TypeMovimientoFuegoNormal::FuegoNormal);
}

CFuegoNormal::~CFuegoNormal() {}

void CFuegoNormal::Dibujar(Graphics^ g, Bitmap^ imgFuego)
{
	Rectangle Origen = Rectangle(arrMovimiento->at(Indice)->Get_X(),
		arrMovimiento->at(Indice)->Get_Y(),
		arrMovimiento->at(Indice)->Get_Ancho(),
		arrMovimiento->at(Indice)->Get_Largo());

	Rectangle Destino = Rectangle(X, Y, Ancho*2, Largo*2);
	
	if (Indice == 19)
	{
		X -= 100000;
	}

	if (Indice == arrMovimiento->size() - 1)
	{
		if (TipoMovimiento != TypeMovimientoFuegoNormal::FuegoNormal)
			Set_Movimiento(TypeMovimientoFuegoNormal::FuegoNormal);

		Indice = 0;
	}
	else
	{
		Indice++;
	}

	g->DrawImage(imgFuego, Destino, Origen, GraphicsUnit::Pixel);
}

void CFuegoNormal::Set_Movimiento(TypeMovimientoFuegoNormal TipoMovimiento)
{
	this->TipoMovimiento = TipoMovimiento;
	char* Archivo = new char[100];

	switch (TipoMovimiento)
	{
	case TypeMovimientoFuegoNormal::FuegoNormal:
		strcpy(Archivo, "Fuego.txt");
		break;
	}

	int NroMovimientos;
	int X, Y, Ancho, Largo, dX, dY;
	freopen(Archivo, "r", stdin);
	scanf("%d", &NroMovimientos);
	arrMovimiento->clear();

	for (int i = 0; i < NroMovimientos; i++)
	{
		scanf("%d %d %d %d %d %d", &X, &Y, &Ancho, &Largo, &dX, &dY);
		X = X/4;
		Y = Y/4;
		Ancho = Ancho/4;
		Largo = Largo/4;
		arrMovimiento->push_back(new CMovimiento(X, Y, Ancho, Largo, dX, dY));
	}
}

void CFuegoNormal::Mover(int AnchoF, int LargoF)
{

	if (X + dX < 0 || X + Ancho + dX > AnchoF || Y + dY < 0 || X + Largo + dY > LargoF)
	{
		Estado = false;
	}
}

void CFuegoNormal::Set_Estado(bool Estado)
{
	this->Estado = Estado;
}

bool CFuegoNormal::Get_Estado()
{
	return this->Estado;
}

bool CFuegoNormal::HayColision(int pX, int pY)
{
	return pX >= X && pX <= X + Ancho &&
		pY >= Y && pY <= Y + Largo;
}

bool CFuegoNormal::HayColision(CCanaval* objCanaval)
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