#pragma once
#include "CMovimiento.h"
#include <vector>
#include <stdio.h>

using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

enum TypeMovimientoEnemigo { Mover };

class CMedina
{
private:
	CMovimiento *objMovimiento;

	int X, Y;
	vector<CMovimiento *>* arrMovimiento;
	int Direccion, Indice;
	TypeMovimientoEnemigo TipoMovimiento;
	bool Estado;
public:
	CMedina(int X, int Y, int Direccion);
	~CMedina();
	void Set_Movimiento(TypeMovimientoEnemigo TipoMovimiento);
	void Dibujar(Graphics^ g, Bitmap^ imgEnemigo);
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


CMedina::CMedina(int X, int Y, int Direccion)
{
	this->X = X;
	this->Y = Y;
	this->Indice = 0;
	this->Direccion = Direccion * 1;
	this->arrMovimiento = new vector<CMovimiento *>();
	Set_Movimiento(TypeMovimientoEnemigo::Mover);
	this->Estado = true;
}

CMedina::~CMedina() {}

void CMedina::Dibujar(Graphics^ g, Bitmap^ imgEnemigo)
{
	Rectangle Origen = Rectangle(arrMovimiento->at(Indice)->Get_X(),
		arrMovimiento->at(Indice)->Get_Y(),
		arrMovimiento->at(Indice)->Get_Ancho(),
		arrMovimiento->at(Indice)->Get_Largo());

	Rectangle Destino = Rectangle(X,
		Y - (arrMovimiento->at(Indice)->Get_Largo()), arrMovimiento->at(Indice)->Get_Ancho(),
		arrMovimiento->at(Indice)->Get_Largo());

	g->DrawImage(imgEnemigo, Destino, Origen, GraphicsUnit::Pixel);


	Set_Movimiento(TypeMovimientoEnemigo::Mover);
}

void CMedina::Set_Movimiento(TypeMovimientoEnemigo TipoMovimiento)
{
	this->TipoMovimiento = TipoMovimiento;
	char* Archivo = new char[100];

	switch (TipoMovimiento)
	{
	case TypeMovimientoEnemigo::Mover:
		//strcpy(Archivo, "Medina.txt");
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

void CMedina::Mover(int AnchoF, int LargoF)
{
	/*
	if (X <-150)
	Estado = false;


	X -= 4;
	*/
}

void CMedina::Set_Estado(bool Estado)
{
	this->Estado = Estado;
}

int CMedina::Get_X()
{
	return this->X;
}

int CMedina::Get_Y()
{
	return Y - arrMovimiento->at(Indice)->Get_Largo();
}

int CMedina::Get_Ancho()
{
	return arrMovimiento->at(Indice)->Get_Ancho() / 5;
}

int CMedina::Get_Largo()
{
	return arrMovimiento->at(Indice)->Get_Largo() / 5;
}

bool CMedina::Get_Estado()
{
	return this->Estado;
}

bool CMedina::HayColision(int pX, int pY)
{
	return pX >= X && pX <= X + Get_Ancho() &&
		pY >= Get_Y() && pY <= Get_Y() + Get_Largo();
}

bool CMedina::HayColision(int pX, int pY, int pAncho, int pLargo)
{
	return HayColision(pX, pY) ||
		HayColision(pX + pAncho, pY) ||
		HayColision(pX, pY + pLargo) ||
		HayColision(pX + pAncho, pY + pLargo);
}