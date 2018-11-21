#pragma once
#include "CTrampas.h"

class CVecTrampas
{
private:
	vector<CTrampa*>* arrTrampa;
public:
	CVecTrampas();
	~CVecTrampas();
	void Agregar(int X, int Y, int Direccion);
	void Dibujar(Graphics^ g, Bitmap^ imgTrampas);
	void Mover(int AnchoF, int LargoF);
	int GetSize() { return arrTrampa->size(); }
	void Eliminar();
	int HayColision(CMingyu* objMingyu, CPonky* objPonky, CMely* objMely);
};

CVecTrampas::CVecTrampas()
{
	arrTrampa = new vector<CTrampa *>();
}

CVecTrampas::~CVecTrampas() {}

void CVecTrampas::Agregar(int X, int Y, int Direccion)
{
	CTrampa* objTrampa = new CTrampa(X, Y, Direccion);
	arrTrampa->push_back(objTrampa);
}

void CVecTrampas::Dibujar(Graphics^ g, Bitmap^ imgTrampas)
{
	for (int i = 0; i < arrTrampa->size(); i++)
		arrTrampa->at(i)->Dibujar(g, imgTrampas);
}

void CVecTrampas::Mover(int AnchoF, int LargoF)
{
	for (int i = 0; i < arrTrampa->size(); i++)
		arrTrampa->at(i)->Mover(AnchoF, LargoF);
}

void CVecTrampas::Eliminar()
{
	vector<CTrampa *>* Aux = new vector<CTrampa *>();

	for (int i = 0; i < arrTrampa->size(); i++)
		if (arrTrampa->at(i)->Get_Estado())
			Aux->push_back(arrTrampa->at(i));

	arrTrampa = Aux;
}

int CVecTrampas::HayColision(CMingyu* objMingyu, CPonky* objPonky, CMely* objMely)
{
	int Puntaje = 0;

	for (int i = 0; i < arrTrampa->size(); i++)
	{
		if (arrTrampa->at(i)->HayColision(objMingyu->Get_X(),
			objMingyu->Get_Y(), objMingyu->Get_Ancho(),
			objMingyu->Get_Largo()))
		{
			Puntaje -= 5;
			objMingyu->Set_NivelVida(objMingyu->Get_NivelVida() - 1);
			arrTrampa->at(i)->Set_Estado(false);
			if (objMingyu->Get_NivelVida() <= 0)
			{
				//objMingyu->Set_NivelVida(100);
				objMingyu->Set_NroVidas(objMingyu->Get_NroVidas() - 1);
			}
		}

		if (arrTrampa->at(i)->HayColision(objPonky->Get_X(),
			objPonky->Get_Y(), objPonky->Get_Ancho(),
			objPonky->Get_Largo()))
		{
			Puntaje -= 5;
			objPonky->Set_NivelVida(objPonky->Get_NivelVida() - 1);
			arrTrampa->at(i)->Set_Estado(false);
			if (objPonky->Get_NivelVida() <= 0)
			{
				//objPonky->Set_NivelVida(100);
				objPonky->Set_NroVidas(objPonky->Get_NroVidas() - 1);
			}
		}

		if (arrTrampa->at(i)->HayColision(objMely->Get_X(),
			objMely->Get_Y(), objMely->Get_Ancho(),
			objMely->Get_Largo()))
		{
			Puntaje -= 5;
			objMely->Set_NivelVida(objMely->Get_NivelVida() - 1);
			arrTrampa->at(i)->Set_Estado(false);
			if (objMely->Get_NivelVida() <= 0)
			{
				//objMely->Set_NivelVida(100);
				objMely->Set_NroVidas(objMely->Get_NroVidas() - 1);
			}
		}
	}

	return Puntaje;
}