#pragma once
#include "CMovimiento.h"
#include <vector>
#include <stdio.h>

using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

enum TypeMovimientoEnemigo { Mover };

class CCanaval
{
private:
	CMovimiento *objMovimiento;

	int X, Y;
	int dx;
	int dy;
	int dir;
	vector<CMovimiento *>* arrMovimiento;
	int Direccion, Indice;
	TypeMovimientoEnemigo TipoMovimiento;
	bool Estado;
public:
	CCanaval(int X, int Y, int Direccion);
	~CCanaval();
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


CCanaval::CCanaval(int X, int Y, int Direccion)
{
	this->X = X;
	this->Y = Y;
	this->dx = 0;
	this->dy = 0;
	this->dir = rand() % 4;
	this->Indice = 0;
	this->Direccion = Direccion * 1;
	this->arrMovimiento = new vector<CMovimiento *>();
	Set_Movimiento(TypeMovimientoEnemigo::Mover);
	this->Estado = true;

	if (dir == 0)
	{
		dx = -1;
	}
	else if (dir == 1)
	{
		dx = 1;
	}
	else if (dir == 2)
	{
		dx = 1;
	}
	else
	{
		dx = -1;
	}
}

CCanaval::~CCanaval() {}

void CCanaval::Dibujar(Graphics^ g, Bitmap^ imgEnemigo)
{
	Rectangle Origen = Rectangle(arrMovimiento->at(Indice)->Get_X(),
		arrMovimiento->at(Indice)->Get_Y(),
		arrMovimiento->at(Indice)->Get_Ancho(),
		arrMovimiento->at(Indice)->Get_Largo());

	Rectangle Destino = Rectangle(X, Y- (arrMovimiento->at(Indice)->Get_Largo()), arrMovimiento->at(Indice)->Get_Ancho(), arrMovimiento->at(Indice)->Get_Largo());
	//Rectangle Destino = Rectangle(X, Y, arrMovimiento->at(Indice)->Get_Ancho(), arrMovimiento->at(Indice)->Get_Largo());

	g->DrawImage(imgEnemigo, Destino, Origen, GraphicsUnit::Pixel);

	Set_Movimiento(TypeMovimientoEnemigo::Mover);
}

void CCanaval::Set_Movimiento(TypeMovimientoEnemigo TipoMovimiento)
{
	this->TipoMovimiento = TipoMovimiento;
	char* Archivo = new char[100];

	switch (TipoMovimiento)
	{
	case TypeMovimientoEnemigo::Mover:
		strcpy(Archivo, "Canaval.txt");
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

void CCanaval::Mover(int AnchoF, int LargoF)
{
	/*
	if (X <-150)
		Estado = false;


	X -= 4;
	*/
	//X += (Direccion * arrMovimiento->at(Indice)->Get_dX());
	//Y += (arrMovimiento->at(Indice)->Get_dY());

	if (X <= 0)
	{
		dx = 1;
	}
	if (X + 32 >= 1466)
	{
		dx = -1;
	}

	if (Y <= 300)
	{
		dy = 1;
	}
	if (Y + 32 >= 939)
	{
		dy = -1;
	}

	X += dx;
	Y += dy;
}

void CCanaval::Set_Estado(bool Estado)
{
	this->Estado = Estado;
}

int CCanaval::Get_X()
{
	return this->X;
}

int CCanaval::Get_Y()
{
	return Y - arrMovimiento->at(Indice)->Get_Largo() - arrMovimiento->at(Indice)->Get_Largo();
}

int CCanaval::Get_Ancho()
{
	return arrMovimiento->at(Indice)->Get_Ancho();
}

int CCanaval::Get_Largo()
{
	return arrMovimiento->at(Indice)->Get_Largo();
}

bool CCanaval::Get_Estado()
{
	return this->Estado;
}

bool CCanaval::HayColision(int pX, int pY)
{
	return pX >= X && pX <= X + Get_Ancho() &&
		pY >= Get_Y() && pY <= Get_Y() + Get_Largo();
}

bool CCanaval::HayColision(int pX, int pY, int pAncho, int pLargo)
{
	return HayColision(pX, pY) ||
		HayColision(pX + pAncho, pY) ||
		HayColision(pX, pY + pLargo) ||
		HayColision(pX + pAncho, pY + pLargo);
}