#pragma once

#include "CMovimiento.h"
#include "CVecFuegoNormal.h"
#include <vector>
#include <stdio.h>

using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

enum TypeMovimientoMely { EstaticoMely, ArribaMely, AbajoMely, IzquierdaMely, DerechaMely};

class CMely
{
private:
	int X, Y;

	vector<CMovimiento *>* arrMovimiento;
	int Direccion, Indice;
	TypeMovimientoMely TipoMovimiento;
	CVecFuegoNormal* objVecFuegoNormal;
	int NroVidas;
	int NivelVida;
	int Dir;

public:


	CMely(int X, int Y, int NivelVida);
	~CMely();
	void Dibujar(Graphics^ g, Bitmap^ imgMely, Bitmap^ imgFuegoNormal);
	void Set_Movimiento(TypeMovimientoMely TipoMovimiento);
	void Mover(Keys Tecla);
	void Mover_FuegoNormal(int AnchoF, int LargoF);
	void Estatico(Keys Tecla);

	CVecFuegoNormal* Get_VecFuegoNormal();

	int Get_X();
	int Get_Y();

	int Get_Ancho();
	int Get_Largo();
	void Set_NroVidas(int NroVidas);
	void Set_NivelVida(int NivelVida);
	int Get_NroVidas();
	int Get_NivelVida();
};


CMely::CMely(int X, int Y, int NivelVida)
{
	this->X = X;
	this->Y = Y;
	this->Indice = 0;
	this->Direccion = 1; // HACIA LA DERECHA
	this->Dir = 0; //Direccion del personaje estaticamente (Hacia abajo)

	this->arrMovimiento = new vector<CMovimiento *>();
	Set_Movimiento(TypeMovimientoMely::EstaticoMely);
	objVecFuegoNormal = new CVecFuegoNormal();
	this->NivelVida = NivelVida;
}

CMely::~CMely() {}

void CMely::Dibujar(Graphics^ g, Bitmap^ imgMely, Bitmap^ imgFuegoNormal)
{
	//Origen del personaje
	Rectangle Origen = Rectangle(arrMovimiento->at(Indice)->Get_X(),
		arrMovimiento->at(Indice)->Get_Y(),
		arrMovimiento->at(Indice)->Get_Ancho(),
		arrMovimiento->at(Indice)->Get_Largo());

	Rectangle Destino = Rectangle(X, Y, arrMovimiento->at(Indice)->Get_Ancho(), arrMovimiento->at(Indice)->Get_Largo());

	g->DrawImage(imgMely, Destino, Origen, GraphicsUnit::Pixel);

	X += (Direccion * arrMovimiento->at(Indice)->Get_dX());
	Y += (arrMovimiento->at(Indice)->Get_dY());


	if (Indice == arrMovimiento->size() - 1)
	{
		if (TipoMovimiento != TypeMovimientoMely::EstaticoMely)
			Set_Movimiento(TypeMovimientoMely::EstaticoMely);

		Indice = 0;
	}
	else
	{
		Indice++;
	}
	// Dibujar los ataques
	objVecFuegoNormal->Dibujar(g, imgFuegoNormal);
}

void CMely::Mover_FuegoNormal(int AnchoF, int LargoF)
{
	objVecFuegoNormal->Mover(AnchoF, LargoF);
	objVecFuegoNormal->Eliminar(); // ELIMINAR TODOS LOS QUE TENGAN ESTADO FALSE
}

void CMely::Set_Movimiento(TypeMovimientoMely TipoMovimiento)
{
	this->TipoMovimiento = TipoMovimiento;
	char* Archivo = new char[100];

	switch (TipoMovimiento)
	{
	case TypeMovimientoMely::EstaticoMely:
		if (Dir == 0)
			strcpy(Archivo, "EstaticoAbajo.txt");
		else if (Dir == 1)
			strcpy(Archivo, "EstaticoArriba.txt");
		else if (Dir == 2)
			strcpy(Archivo, "EstaticoDerecha.txt");
		else if (Dir == 3)
			strcpy(Archivo, "EstaticoIzquierda.txt");
		break;
	case TypeMovimientoMely::AbajoMely:
		strcpy(Archivo, "Abajo.txt");
		break;
	case TypeMovimientoMely::ArribaMely:
		strcpy(Archivo, "Arriba.txt");
		break;
	case TypeMovimientoMely::DerechaMely:
		strcpy(Archivo, "Derecha.txt");
		break;
	case TypeMovimientoMely::IzquierdaMely:
		strcpy(Archivo, "Izquierda.txt");
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

void CMely::Mover(Keys Tecla)
{
	switch (Tecla)
	{
	case Keys::S:
		Dir = 0;
		Set_Movimiento(TypeMovimientoMely::AbajoMely);
		break;
	case Keys::W:
		Dir = 1;
		Set_Movimiento(TypeMovimientoMely::ArribaMely);
		break;
	case Keys::D:
		Dir = 2;
		Set_Movimiento(TypeMovimientoMely::DerechaMely);
		break;
	case Keys::A:
		Dir = 3;
		Set_Movimiento(TypeMovimientoMely::IzquierdaMely);
		break;
	case Keys::Q:

		if (Dir == 0)
		{
			objVecFuegoNormal->Agregar(X-15, Y-32, 32, 64, 0, -0);
		}
		else if (Dir == 1)
		{
			objVecFuegoNormal->Agregar(X-15, Y-96-32, 32, 64, 0, -0);
		}
		else if (Dir == 2)
		{
			objVecFuegoNormal->Agregar(X+25, Y-35-32, 32, 64, 0, -0);
		}
		else
		{
			objVecFuegoNormal->Agregar(X-60, Y-35-32, 32, 64, 0, -0);
		}
		break;
	}
}

void CMely::Estatico(Keys Tecla)
{
	switch (Tecla)
	{
	case Keys::S:
		Dir = 0;
		Indice = 0;
		Set_Movimiento(TypeMovimientoMely::EstaticoMely);
		break;
	case Keys::W:
		Dir = 1;
		Indice = 0;
		Set_Movimiento(TypeMovimientoMely::EstaticoMely);
		break;
	case Keys::D:
		Dir = 2;
		Indice = 0;
		Set_Movimiento(TypeMovimientoMely::EstaticoMely);
		break;
	case Keys::A:
		Dir = 3;
		Indice = 0;
		Set_Movimiento(TypeMovimientoMely::EstaticoMely);
		break;
	}
}

CVecFuegoNormal* CMely::Get_VecFuegoNormal()
{
	return this->objVecFuegoNormal;
}
int CMely::Get_X()
{
	return this->X;
}

int CMely::Get_Y()
{
	return this->Y - arrMovimiento->at(Indice)->Get_Largo();
}

int CMely::Get_Ancho()
{
	return arrMovimiento->at(Indice)->Get_Ancho();
}

int CMely::Get_Largo()
{
	return arrMovimiento->at(Indice)->Get_Largo();
}

void CMely::Set_NroVidas(int NroVidas)
{
	this->NroVidas = NroVidas;
}

void CMely::Set_NivelVida(int NivelVida)
{
	this->NivelVida = NivelVida;
}

int CMely::Get_NroVidas()
{
	return this->NroVidas;
}

int CMely::Get_NivelVida()
{
	return this->NivelVida;
}