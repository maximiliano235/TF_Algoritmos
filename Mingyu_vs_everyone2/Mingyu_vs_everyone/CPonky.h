#pragma once

#include "CMovimiento.h"
#include "CVecFuegoMorado.h"
#include <vector>
#include <stdio.h>

using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

enum TypeMovimientoPonky { EstaticoPonky, ArribaPonky, AbajoPonky, IzquierdaPonky, DerechaPonky};

class CPonky
{
private:
	int X, Y;

	vector<CMovimiento *>* arrMovimiento;
	int Direccion, Indice;
	TypeMovimientoPonky TipoMovimiento;
	CVecFuegoMorado* objVecFuegoMorado;
	int NroVidas;
	int NivelVida;
	int Dir;

public:


	CPonky(int X, int Y, int NivelVida);
	~CPonky();
	void Dibujar(Graphics^ g, Bitmap^ imgPonky, Bitmap^ imgFuegoMorado);
	void Set_Movimiento(TypeMovimientoPonky TipoMovimiento);
	void Mover(Keys Tecla);
	void Mover_FuegoMorado(int AnchoF, int LargoF);
	void Estatico(Keys Tecla);

	CVecFuegoMorado* Get_VecFuegoMorado();

	int Get_X();
	int Get_Y();

	int Get_Ancho();
	int Get_Largo();
	void Set_NroVidas(int NroVidas);
	void Set_NivelVida(int NivelVida);
	int Get_NroVidas();
	int Get_NivelVida();
};


CPonky::CPonky(int X, int Y, int NivelVida)
{
	this->X = X;
	this->Y = Y;
	this->Indice = 0;
	this->Direccion = 1; // HACIA LA DERECHA
	this->Dir = 0; //Direccion del personaje estaticamente (Hacia abajo)

	this->arrMovimiento = new vector<CMovimiento *>();
	Set_Movimiento(TypeMovimientoPonky::EstaticoPonky);
	objVecFuegoMorado = new CVecFuegoMorado();
	this->NivelVida = NivelVida;
}

CPonky::~CPonky() {}

void CPonky::Dibujar(Graphics^ g, Bitmap^ imgPonky, Bitmap^ imgFuegoMorado)
{
	//Origen del personaje
	Rectangle Origen = Rectangle(arrMovimiento->at(Indice)->Get_X(),
		arrMovimiento->at(Indice)->Get_Y(),
		arrMovimiento->at(Indice)->Get_Ancho(),
		arrMovimiento->at(Indice)->Get_Largo());

	Rectangle Destino = Rectangle(X, Y-32, arrMovimiento->at(Indice)->Get_Ancho(), arrMovimiento->at(Indice)->Get_Largo());

	g->DrawImage(imgPonky, Destino, Origen, GraphicsUnit::Pixel);

	X += (Direccion * arrMovimiento->at(Indice)->Get_dX());
	Y += (arrMovimiento->at(Indice)->Get_dY());


	if (Indice == arrMovimiento->size() - 1)
	{
		if (TipoMovimiento != TypeMovimientoPonky::EstaticoPonky)
			Set_Movimiento(TypeMovimientoPonky::EstaticoPonky);

		Indice = 0;
	}
	else
	{
		Indice++;
	}
	// Dibujar los ataques
	objVecFuegoMorado->Dibujar(g, imgFuegoMorado);
	//Dibujar el portal
}

void CPonky::Mover_FuegoMorado(int AnchoF, int LargoF)
{
	objVecFuegoMorado->Mover(AnchoF, LargoF);
	objVecFuegoMorado->Eliminar(); // ELIMINAR TODOS LOS QUE TENGAN ESTADO FALSE
}

void CPonky::Set_Movimiento(TypeMovimientoPonky TipoMovimiento)
{
	this->TipoMovimiento = TipoMovimiento;
	char* Archivo = new char[100];

	switch (TipoMovimiento)
	{
	case TypeMovimientoPonky::EstaticoPonky:
		if (Dir == 0)
			strcpy(Archivo, "EstaticoAbajo.txt");
		else if (Dir == 1)
			strcpy(Archivo, "EstaticoArriba.txt");
		else if (Dir == 2)
			strcpy(Archivo, "EstaticoDerecha.txt");
		else if (Dir == 3)
			strcpy(Archivo, "EstaticoIzquierda.txt");
		break;
	case TypeMovimientoPonky::AbajoPonky:
		strcpy(Archivo, "Abajo.txt");
		break;
	case TypeMovimientoPonky::ArribaPonky:
		strcpy(Archivo, "Arriba.txt");
		break;
	case TypeMovimientoPonky::DerechaPonky:
		strcpy(Archivo, "Derecha.txt");
		break;
	case TypeMovimientoPonky::IzquierdaPonky:
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
		Y *= 2;
		Largo *= 2;
		arrMovimiento->push_back(new CMovimiento(X, Y, Ancho, Largo, dX, dY));
	}
}

void CPonky::Mover(Keys Tecla)
{
	switch (Tecla)
	{
	case Keys::G:
		Dir = 0;
		Set_Movimiento(TypeMovimientoPonky::AbajoPonky);
		break;
	case Keys::T:
		Dir = 1;
		Set_Movimiento(TypeMovimientoPonky::ArribaPonky);
		break;
	case Keys::H:
		Dir = 2;
		Set_Movimiento(TypeMovimientoPonky::DerechaPonky);
		break;
	case Keys::F:
		Dir = 3;
		Set_Movimiento(TypeMovimientoPonky::IzquierdaPonky);
		break;
	case Keys::Y:

		if (Dir == 0)
		{
			objVecFuegoMorado->Agregar(X-15, Y-32, 32, 64, 0, -0);
		}
		else if (Dir == 1)
		{
			objVecFuegoMorado->Agregar(X-15, Y-96-32, 32, 64, 0, -0);
		}
		else if (Dir == 2)
		{
			objVecFuegoMorado->Agregar(X+25, Y-35-32, 32, 64, 0, -0);
		}
		else
		{
			objVecFuegoMorado->Agregar(X-60, Y-35-32, 32, 64, 0, -0);
		}
		break;
	}
}

void CPonky::Estatico(Keys Tecla)
{
	switch (Tecla)
	{
	case Keys::G:
		Dir = 0;
		Indice = 0;
		Set_Movimiento(TypeMovimientoPonky::EstaticoPonky);
		break;
	case Keys::T:
		Dir = 1;
		Indice = 0;
		Set_Movimiento(TypeMovimientoPonky::EstaticoPonky);
		break;
	case Keys::H:
		Dir = 2;
		Indice = 0;
		Set_Movimiento(TypeMovimientoPonky::EstaticoPonky);
		break;
	case Keys::F:
		Dir = 3;
		Indice = 0;
		Set_Movimiento(TypeMovimientoPonky::EstaticoPonky);
		break;
	}
}

CVecFuegoMorado* CPonky::Get_VecFuegoMorado()
{
	return this->objVecFuegoMorado;
}
int CPonky::Get_X()
{
	return this->X;
}

int CPonky::Get_Y()
{
	return this->Y - (arrMovimiento->at(Indice)->Get_Largo()/2);
}

int CPonky::Get_Ancho()
{
	return arrMovimiento->at(Indice)->Get_Ancho();
}

int CPonky::Get_Largo()
{
	return arrMovimiento->at(Indice)->Get_Largo()/2;
}

void CPonky::Set_NroVidas(int NroVidas)
{
	this->NroVidas = NroVidas;
}

void CPonky::Set_NivelVida(int NivelVida)
{
	this->NivelVida = NivelVida;
}

int CPonky::Get_NroVidas()
{
	return this->NroVidas;
}

int CPonky::Get_NivelVida()
{
	return this->NivelVida;
}