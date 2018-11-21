#pragma once

#include "CMovimiento.h"
#include "CVecMartillo.h"
#include <vector>
#include <stdio.h>

using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

enum TypeMovimientoMingyu { EstaticoMingyu, ArribaMingyu, AbajoMingyu, IzquierdaMingyu, DerechaMingyu};

class CMingyu
{
private:
	int X, Y;
	int puntaje;

	vector<CMovimiento *>* arrMovimiento;
	int Direccion, Indice;
	TypeMovimientoMingyu TipoMovimiento;
	CVecMartillo* objVecMartillo;
	int NroVidas;
	int NivelVida;
	int Dir;

public:


	CMingyu(int X, int Y, int NivelVida, int puntaje);
	~CMingyu();
	void Dibujar(Graphics^ g, Bitmap^ imgMingyu, Bitmap^ imgMartillo);
	void Set_Movimiento(TypeMovimientoMingyu TipoMovimiento);
	void Mover(Keys Tecla);
	void Mover_Martillo(int AnchoF, int LargoF);
	void Estatico(Keys Tecla);

	CVecMartillo* Get_VecMartillo();

	int Get_X();
	int Get_Y();

	int Get_Ancho();
	int Get_Largo();
	void Set_NroVidas(int NroVidas);
	void Set_NivelVida(int NivelVida);
	int Get_NroVidas();
	int Get_NivelVida();

	int getPuntaje();
};



CMingyu::CMingyu(int X, int Y, int NivelVida, int puntaje)
{
	this->X = X;
	this->Y = Y;
	this->Indice = 0;
	this->Direccion = 1; // HACIA LA DERECHA
	this->Dir = 0; //Direccion del personaje estaticamente (Hacia abajo)

	this->arrMovimiento = new vector<CMovimiento *>();
	Set_Movimiento(TypeMovimientoMingyu::EstaticoMingyu);
	objVecMartillo = new CVecMartillo();
	this->NivelVida = NivelVida;
	this->puntaje = puntaje;
}

CMingyu::~CMingyu() {}

int CMingyu::getPuntaje() { return puntaje; }

void CMingyu::Dibujar(Graphics^ g, Bitmap^ imgMingyu, Bitmap^ imgMartillo)
{
	//Origen del personaje
	Rectangle Origen = Rectangle(arrMovimiento->at(Indice)->Get_X(),
		arrMovimiento->at(Indice)->Get_Y(),
		arrMovimiento->at(Indice)->Get_Ancho(),
		arrMovimiento->at(Indice)->Get_Largo());

	Rectangle Destino = Rectangle(X, Y, arrMovimiento->at(Indice)->Get_Ancho(), arrMovimiento->at(Indice)->Get_Largo());
	//Rectangle Destino = Rectangle(X, Y - (arrMovimiento->at(Indice)->Get_Largo()), arrMovimiento->at(Indice)->Get_Ancho(), arrMovimiento->at(Indice)->Get_Largo());

	g->DrawImage(imgMingyu, Destino, Origen, GraphicsUnit::Pixel);

	X += (Direccion * arrMovimiento->at(Indice)->Get_dX());
	Y += (arrMovimiento->at(Indice)->Get_dY());


	if (Indice == arrMovimiento->size() - 1)
	{
		if (TipoMovimiento != TypeMovimientoMingyu::EstaticoMingyu)
			Set_Movimiento(TypeMovimientoMingyu::EstaticoMingyu);

		Indice = 0;
	}
	else
	{
		Indice++;
	}
	// Dibujar los ataques
	objVecMartillo->Dibujar(g, imgMartillo);
}

void CMingyu::Mover_Martillo(int AnchoF, int LargoF)
{
	objVecMartillo->Mover(AnchoF, LargoF);
	objVecMartillo->Eliminar(); // ELIMINAR TODOS LOS QUE TENGAN ESTADO FALSE
}


void CMingyu::Set_Movimiento(TypeMovimientoMingyu TipoMovimiento)
{
	this->TipoMovimiento = TipoMovimiento;
	char* Archivo = new char[100];

	switch (TipoMovimiento)
	{
	case TypeMovimientoMingyu::EstaticoMingyu:
		if (Dir == 0)
			strcpy(Archivo, "EstaticoAbajo.txt");
		else if (Dir == 1)
			strcpy(Archivo, "EstaticoArriba.txt");
		else if (Dir == 2)
			strcpy(Archivo, "EstaticoDerecha.txt");
		else if (Dir == 3)
			strcpy(Archivo, "EstaticoIzquierda.txt");
		break;
	case TypeMovimientoMingyu::AbajoMingyu:
		strcpy(Archivo, "Abajo.txt");
		break;
	case TypeMovimientoMingyu::ArribaMingyu:
		strcpy(Archivo, "Arriba.txt");
		break;
	case TypeMovimientoMingyu::DerechaMingyu:
		strcpy(Archivo, "Derecha.txt");
		break;
	case TypeMovimientoMingyu::IzquierdaMingyu:
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

void CMingyu::Mover(Keys Tecla)
{
	switch (Tecla)
	{
	case Keys::Down:
		Dir = 0;
		Set_Movimiento(TypeMovimientoMingyu::AbajoMingyu);
		break;
	case Keys::Up:
		Dir = 1;
		Set_Movimiento(TypeMovimientoMingyu::ArribaMingyu);
		break;
	case Keys::Right:
		Dir = 2;
		Set_Movimiento(TypeMovimientoMingyu::DerechaMingyu);
		break;
	case Keys::Left:
		Dir = 3;
		Set_Movimiento(TypeMovimientoMingyu::IzquierdaMingyu);
		break;
	case Keys::C:
		if (Dir == 0)
		{
			objVecMartillo->Agregar(X, Y-32, 32, 32, 0, 10);
		}
		else if (Dir == 1)
		{
			objVecMartillo->Agregar(X, Y-32, 32, 32, 0, -10);
		}
		else if (Dir == 2)
		{
			objVecMartillo->Agregar(X, Y-32, 32, 32, 10, 0);
		}
		else
		{
			objVecMartillo->Agregar(X, Y-32, 32, 32, -10, 0);
		}
		break;
	}
}

void CMingyu::Estatico(Keys Tecla)
{
	switch (Tecla)
	{
	case Keys::Down:
		Dir = 0;
		Indice = 0;
		Set_Movimiento(TypeMovimientoMingyu::EstaticoMingyu);
		break;
	case Keys::Up:
		Dir = 1;
		Indice = 0;
		Set_Movimiento(TypeMovimientoMingyu::EstaticoMingyu);
		break;
	case Keys::Right:
		Dir = 2;
		Indice = 0;
		Set_Movimiento(TypeMovimientoMingyu::EstaticoMingyu);
		break;
	case Keys::Left:
		Dir = 3;
		Indice = 0;
		Set_Movimiento(TypeMovimientoMingyu::EstaticoMingyu);
		break;
	}
}


CVecMartillo* CMingyu::Get_VecMartillo()
{
	return this->objVecMartillo;
}
int CMingyu::Get_X()
{
	return this->X;
}

int CMingyu::Get_Y()
{
	return this->Y - arrMovimiento->at(Indice)->Get_Largo();
}

int CMingyu::Get_Ancho()
{
	return arrMovimiento->at(Indice)->Get_Ancho();
}

int CMingyu::Get_Largo()
{
	return arrMovimiento->at(Indice)->Get_Largo();
}

void CMingyu::Set_NroVidas(int NroVidas)
{
	this->NroVidas = NroVidas;
}

void CMingyu::Set_NivelVida(int NivelVida)
{
	this->NivelVida = NivelVida;
}

int CMingyu::Get_NroVidas()
{
	return this->NroVidas;
}

int CMingyu::Get_NivelVida()
{
	return this->NivelVida;
}