#pragma once
#include "CMovimiento.h"
#include <vector>
#include <stdio.h>

using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

enum TypeMovimientoMoneda { Plata };

class CMoneda
{
private:
	CMovimiento *objMovimiento;

	int X, Y;
	vector<CMovimiento *>* arrMovimiento;
	int Direccion, Indice;
	TypeMovimientoMoneda TipoMovimiento;
	bool Estado;
public:
	CMoneda(int X, int Y, int Direccion);
	~CMoneda();
	void Set_Movimiento(TypeMovimientoMoneda TipoMovimiento);
	void Dibujar(Graphics^ g, Bitmap^ imgMoneda);
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


CMoneda::CMoneda(int X, int Y, int Direccion)
{
	this->X = X;
	this->Y = Y;
	this->Indice = 0;
	this->Direccion = Direccion * 1;
	this->arrMovimiento = new vector<CMovimiento *>();
	Set_Movimiento(TypeMovimientoMoneda::Plata);
	this->Estado = true;
}

CMoneda::~CMoneda() {}

void CMoneda::Dibujar(Graphics^ g, Bitmap^ imgMoneda)
{
	Rectangle Origen = Rectangle(arrMovimiento->at(Indice)->Get_X(),
		arrMovimiento->at(Indice)->Get_Y(),
		arrMovimiento->at(Indice)->Get_Ancho(),
		arrMovimiento->at(Indice)->Get_Largo());

	Rectangle Destino = Rectangle(X, Y- (arrMovimiento->at(Indice)->Get_Largo()), arrMovimiento->at(Indice)->Get_Ancho()/5, arrMovimiento->at(Indice)->Get_Largo()/5);
	//Rectangle Destino = Rectangle(X, Y, arrMovimiento->at(Indice)->Get_Ancho(), arrMovimiento->at(Indice)->Get_Largo());

	g->DrawImage(imgMoneda, Destino, Origen, GraphicsUnit::Pixel);

	if (Indice == arrMovimiento->size() - 1)
	{
		if (TipoMovimiento != TypeMovimientoMoneda::Plata)
			Set_Movimiento(TypeMovimientoMoneda::Plata);

		Indice = 0;
	}
	else
	{
		Indice++;
	}
}

void CMoneda::Set_Movimiento(TypeMovimientoMoneda TipoMovimiento)
{
	this->TipoMovimiento = TipoMovimiento;
	char* Archivo = new char[100];

	switch (TipoMovimiento)
	{
	case TypeMovimientoMoneda::Plata:
		strcpy(Archivo, "Moneda.txt");
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

void CMoneda::Mover(int AnchoF, int LargoF)
{
	/*
	if (X <-150)
		Estado = false;


	X -= 4;
	*/
	X += (Direccion * arrMovimiento->at(Indice)->Get_dX());
	Y += (arrMovimiento->at(Indice)->Get_dY());
}

void CMoneda::Set_Estado(bool Estado)
{
	this->Estado = Estado;
}

int CMoneda::Get_X()
{
	return this->X;
}

int CMoneda::Get_Y()
{
	return Y - (arrMovimiento->at(Indice)->Get_Largo()/5) - (arrMovimiento->at(Indice)->Get_Largo()/5)-128-16;
}

int CMoneda::Get_Ancho()
{
	return arrMovimiento->at(Indice)->Get_Ancho()/5+10;
}

int CMoneda::Get_Largo()
{
	return arrMovimiento->at(Indice)->Get_Largo()/5-20;
}

bool CMoneda::Get_Estado()
{
	return this->Estado;
}

bool CMoneda::HayColision(int pX, int pY)
{
	return pX >= X && pX <= X + Get_Ancho() &&
		pY >= Get_Y() && pY <= Get_Y() + Get_Largo();
}

bool CMoneda::HayColision(int pX, int pY, int pAncho, int pLargo)
{
	return HayColision(pX, pY) ||
		HayColision(pX + pAncho, pY) ||
		HayColision(pX, pY + pLargo) ||
		HayColision(pX + pAncho, pY + pLargo);
}