#pragma once
#include "CMovimiento.h"
#include <vector>
#include <stdio.h>

using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

enum TypeMovimientoTrampa { Trap };

class CTrampa
{
private:
	CMovimiento *objMovimiento;

	int X, Y;
	vector<CMovimiento *>* arrMovimiento;
	int Direccion, Indice;
	TypeMovimientoTrampa TipoMovimiento;
	bool Estado;
public:
	CTrampa(int X, int Y, int Direccion);
	~CTrampa();
	void Set_Movimiento(TypeMovimientoTrampa TipoMovimiento);
	void Dibujar(Graphics^ g, Bitmap^ imgTrampa);
	void Mover(int AnchoF, int LargoF);
	void Set_Estado(bool Estado);
	int Get_X();
	int Get_Y();
	int Get_Ancho();
	int Get_Largo();
	bool Get_Estado();
	bool HayColision(int pX, int pY);
	bool HayColision(int pX, int pY, int pAncho, int pLargo);
};


CTrampa::CTrampa(int X, int Y, int Direccion)
{
	this->X = X;
	this->Y = Y;
	this->Indice = 0;
	this->Direccion = Direccion * 1;
	this->arrMovimiento = new vector<CMovimiento *>();
	Set_Movimiento(TypeMovimientoTrampa::Trap);
	this->Estado = true;
}

CTrampa::~CTrampa() {}

void CTrampa::Dibujar(Graphics^ g, Bitmap^ imgTrampa)
{
	Rectangle Origen = Rectangle(arrMovimiento->at(Indice)->Get_X(),
		arrMovimiento->at(Indice)->Get_Y(),
		arrMovimiento->at(Indice)->Get_Ancho(),
		arrMovimiento->at(Indice)->Get_Largo());

	Rectangle Destino = Rectangle(X, Y - (arrMovimiento->at(Indice)->Get_Largo()), arrMovimiento->at(Indice)->Get_Ancho() / 2, arrMovimiento->at(Indice)->Get_Largo() / 2);
	//Rectangle Destino = Rectangle(X, Y, arrMovimiento->at(Indice)->Get_Ancho(), arrMovimiento->at(Indice)->Get_Largo());

	g->DrawImage(imgTrampa, Destino, Origen, GraphicsUnit::Pixel);

	if (Indice == arrMovimiento->size() - 1)
	{
		if (TipoMovimiento != TypeMovimientoTrampa::Trap)
			Set_Movimiento(TypeMovimientoTrampa::Trap);

		Indice = 0;
	}
	else
	{
		Indice++;
	}
}

void CTrampa::Set_Movimiento(TypeMovimientoTrampa TipoMovimiento)
{
	this->TipoMovimiento = TipoMovimiento;
	char* Archivo = new char[100];

	switch (TipoMovimiento)
	{
	case TypeMovimientoTrampa::Trap:
		strcpy(Archivo, "Trampa.txt");
		break;
	}

	int NroMovimientos, X, Y, Ancho, Largo, dX, dY;
	freopen(Archivo, "r", stdin);
	scanf("%d", &NroMovimientos);
	arrMovimiento->clear();

	for (int i = 0; i < NroMovimientos; i++)
	{
		scanf("%d %d %d %d %d %d", &X, &Y, &Ancho, &Largo, &dX, &dY);
		arrMovimiento->push_back(new CMovimiento(X, Y, Ancho, Largo, dX, dY));
	}
}

void CTrampa::Mover(int AnchoF, int LargoF)
{
	/*
	if (X <-150)
		Estado = false;


	X -= 4;
	*/
	X += (Direccion * arrMovimiento->at(Indice)->Get_dX());
	Y += (arrMovimiento->at(Indice)->Get_dY());
}

void CTrampa::Set_Estado(bool Estado)
{
	this->Estado = Estado;
}

int CTrampa::Get_X()
{
	return this->X;
}

int CTrampa::Get_Y()
{
	return Y - (arrMovimiento->at(Indice)->Get_Largo()/2) - (arrMovimiento->at(Indice)->Get_Largo()/2)-20;
}

int CTrampa::Get_Ancho()
{
	return arrMovimiento->at(Indice)->Get_Ancho()-40;
}

int CTrampa::Get_Largo()
{
	return arrMovimiento->at(Indice)->Get_Largo()-64;
}

bool CTrampa::Get_Estado()
{
	return this->Estado;
}

bool CTrampa::HayColision(int pX, int pY)
{
	return pX >= X && pX <= X + Get_Ancho() &&
		pY >= Get_Y() && pY <= Get_Y() + Get_Largo();
}

bool CTrampa::HayColision(int pX, int pY, int pAncho, int pLargo)
{
	return HayColision(pX, pY) ||
		HayColision(pX + pAncho, pY) ||
		HayColision(pX, pY + pLargo) ||
		HayColision(pX + pAncho, pY + pLargo);
}