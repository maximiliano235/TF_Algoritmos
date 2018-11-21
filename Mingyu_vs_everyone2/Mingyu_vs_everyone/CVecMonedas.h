#pragma once
#include "CMoneda.h"

class CVecMonedas
{
private:
	vector<CMoneda*>* arrMoneda;
public:
	CVecMonedas();
	~CVecMonedas();
	void Agregar(int X, int Y, int Direccion);
	void Dibujar(Graphics^ g, Bitmap^ imgMonedas);
	void Mover(int AnchoF, int LargoF);
	void Eliminar();
	int GetSize() { return arrMoneda->size(); }
	int HayColision(CMingyu* objMingyu, CPonky* objPonky, CMely* objMely);
};

CVecMonedas::CVecMonedas()
{
	arrMoneda = new vector<CMoneda *>();
}

CVecMonedas::~CVecMonedas(){}

void CVecMonedas::Agregar(int X, int Y, int Direccion)
{
	CMoneda* objMoneda = new CMoneda(X, Y, Direccion);
	arrMoneda->push_back(objMoneda);
}

void CVecMonedas::Dibujar(Graphics^ g, Bitmap^ imgMonedas)
{
	for (int i = 0; i < arrMoneda->size(); i++)
		arrMoneda->at(i)->Dibujar(g, imgMonedas);
}

void CVecMonedas::Mover(int AnchoF, int LargoF)
{
	for (int i = 0; i < arrMoneda->size(); i++)
		arrMoneda->at(i)->Mover(AnchoF, LargoF);
}

void CVecMonedas::Eliminar()
{
	vector<CMoneda *>* Aux = new vector<CMoneda *>();

	for (int i = 0; i < arrMoneda->size(); i++)
		if (arrMoneda->at(i)->Get_Estado())
			Aux->push_back(arrMoneda->at(i));

	arrMoneda = Aux;
}

int CVecMonedas::HayColision(CMingyu* objMingyu, CPonky* objPonky, CMely* objMely)
{
	int Puntaje = 0;

	for (int i = 0; i < arrMoneda->size(); i++)
	{
		if (arrMoneda->at(i)->HayColision(objMingyu->Get_X(),
			objMingyu->Get_Y(), objMingyu->Get_Ancho(),
			objMingyu->Get_Largo()))
		{
			Puntaje += 5;
			objMingyu->Set_NivelVida(objMingyu->Get_NivelVida() - 0);
			arrMoneda->at(i)->Set_Estado(false);
			if (objMingyu->Get_NivelVida() <= 0)
			{
				//objMingyu->Set_NivelVida(100);
				objMingyu->Set_NroVidas(objMingyu->Get_NroVidas() - 1);
			}
		}

		if (arrMoneda->at(i)->HayColision(objPonky->Get_X(),
			objPonky->Get_Y(), objPonky->Get_Ancho(),
			objPonky->Get_Largo()))
		{
			Puntaje += 5;
			objPonky->Set_NivelVida(objPonky->Get_NivelVida() - 0);
			arrMoneda->at(i)->Set_Estado(false);
			if (objPonky->Get_NivelVida() <= 0)
			{
				//objPonky->Set_NivelVida(100);
				objPonky->Set_NroVidas(objPonky->Get_NroVidas() - 1);
			}
		}

		if (arrMoneda->at(i)->HayColision(objMely->Get_X(),
			objMely->Get_Y(), objMely->Get_Ancho(),
			objMely->Get_Largo()))
		{
			Puntaje += 5;
			objMely->Set_NivelVida(objMely->Get_NivelVida() - 0);
			arrMoneda->at(i)->Set_Estado(false);
			if (objMely->Get_NivelVida() <= 0)
			{
				//objMely->Set_NivelVida(100);
				objMely->Set_NroVidas(objMely->Get_NroVidas() - 1);
			}
		}
	}

	return Puntaje;
}