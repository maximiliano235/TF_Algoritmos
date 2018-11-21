#pragma once

#include "CCanaval.h"
#include <vector>
#include "CMovimiento.h"
#include <stdio.h>

using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

enum TypeMovimientoFuegoMorado { FuegoMorado };

class CFuegoMorado
{
private:
	CMovimiento *objMovimiento;
	vector<CMovimiento *>* arrMovimiento;
	TypeMovimientoFuegoMorado TipoMovimiento;

	int X, Y;
	int Ancho, Largo;
	int dX, dY;
	bool Estado;
	int Indice;
	int tiempo;

public:
	CFuegoMorado(int X, int Y, int Ancho, int Largo, int dX, int dY);
	~CFuegoMorado();
	void Set_Movimiento(TypeMovimientoFuegoMorado TipoMovimiento);
	void Dibujar(Graphics^ g, Bitmap^ imgFuego);
	void Mover(int AnchoF, int LargoF);
	void Set_Estado(bool Estado);
	bool Get_Estado();
	bool HayColision(int pX, int pY);
	bool HayColision(CCanaval* objCanaval);
};

CFuegoMorado::CFuegoMorado(int X, int Y, int Ancho, int Largo, int dX, int dY)
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
	Set_Movimiento(TypeMovimientoFuegoMorado::FuegoMorado);
}

CFuegoMorado::~CFuegoMorado() {}

void CFuegoMorado::Dibujar(Graphics^ g, Bitmap^ imgFuego)
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
		if (TipoMovimiento != TypeMovimientoFuegoMorado::FuegoMorado)
			Set_Movimiento(TypeMovimientoFuegoMorado::FuegoMorado);

		Indice = 0;
	}
	else
	{
		Indice++;
	}

	g->DrawImage(imgFuego, Destino, Origen, GraphicsUnit::Pixel);
}

void CFuegoMorado::Set_Movimiento(TypeMovimientoFuegoMorado TipoMovimiento)
{
	this->TipoMovimiento = TipoMovimiento;
	char* Archivo = new char[100];

	switch (TipoMovimiento)
	{
	case TypeMovimientoFuegoMorado::FuegoMorado:
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
		X /= 4;
		Y /= 4;
		Ancho /= 4;
		Largo /= 4;
		arrMovimiento->push_back(new CMovimiento(X, Y, Ancho, Largo, dX, dY));
	}
}

void CFuegoMorado::Mover(int AnchoF, int LargoF)
{

	if (X + dX < 0 || X + Ancho + dX > AnchoF || Y + dY < 0 || X + Largo + dY > LargoF)
	{
		Estado = false;
	}
}

void CFuegoMorado::Set_Estado(bool Estado)
{
	this->Estado = Estado;
}

bool CFuegoMorado::Get_Estado()
{
	return this->Estado;
}

bool CFuegoMorado::HayColision(int pX, int pY)
{
	return pX >= X && pX <= X + Ancho &&
		pY >= Y && pY <= Y + Largo;
}

bool CFuegoMorado::HayColision(CCanaval* objCanaval)
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