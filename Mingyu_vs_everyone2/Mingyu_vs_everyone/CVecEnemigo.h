#pragma once
#include "CCanaval.h"

class CVecEnemigo
{
private:
	vector<CCanaval*>* arrCanaval;
public:
	CVecEnemigo();
	~CVecEnemigo();
	void Agregar(int X, int Y, int Direccion);
	void Dibujar(Graphics^ g, Bitmap^ imgEnemigo);
	void Mover(int AnchoF, int LargoF);
	void Eliminar();
	int HayColision(CVecMartillo* objVecMartillo, CVecFuegoMorado* objVecFuegoMorado, CVecFuegoNormal* objVecFuegoNormal);
	int HayColision(CMingyu* objMingyu, CPonky* objPonky, CMely* objMely);
	int getSize() { return arrCanaval->size(); }
};

CVecEnemigo::CVecEnemigo()
{
	arrCanaval = new vector<CCanaval *>();
}

CVecEnemigo::~CVecEnemigo(){}

void CVecEnemigo::Agregar(int X, int Y, int Direccion)
{
	CCanaval* objCanaval = new CCanaval(X, Y, Direccion);
	arrCanaval->push_back(objCanaval);
}

void CVecEnemigo::Dibujar(Graphics^ g, Bitmap^ imgEnemigo)
{
	for (int i = 0; i < arrCanaval->size(); i++)
		arrCanaval->at(i)->Dibujar(g, imgEnemigo);
}

void CVecEnemigo::Mover(int AnchoF, int LargoF)
{
	for (int i = 0; i < arrCanaval->size(); i++)
		arrCanaval->at(i)->Mover(AnchoF, LargoF);
}

void CVecEnemigo::Eliminar()
{
	vector<CCanaval *>* Aux = new vector<CCanaval *>();

	for (int i = 0; i < arrCanaval->size(); i++)
		if (arrCanaval->at(i)->Get_Estado())
			Aux->push_back(arrCanaval->at(i));

	arrCanaval = Aux;
}

int CVecEnemigo::HayColision(CVecMartillo* objVecMartillo, CVecFuegoMorado* objVecFuegoMorado, CVecFuegoNormal* objVecFuegoNormal)
{
	int Puntaje = 0;

	for (int i = 0; i < arrCanaval->size(); i++)
	{
		Puntaje += objVecMartillo->HayColision(arrCanaval->at(i));
		Puntaje += objVecFuegoMorado->HayColision(arrCanaval->at(i));
		Puntaje += objVecFuegoNormal->HayColision(arrCanaval->at(i));
	}

	return Puntaje;
}

int CVecEnemigo::HayColision(CMingyu* objMingyu, CPonky* objPonky, CMely* objMely)
{
	int Puntaje = 0;

	for (int i = 0; i < arrCanaval->size(); i++)
	{
		if (arrCanaval->at(i)->HayColision(objMingyu->Get_X(),
			objMingyu->Get_Y(), objMingyu->Get_Ancho(),
			objMingyu->Get_Largo()))
		{
			Puntaje -= 5;
			objMingyu->Set_NivelVida(objMingyu->Get_NivelVida() - 1);
			arrCanaval->at(i)->Set_Estado(false);
			if (objMingyu->Get_NivelVida() <= 0)
			{
				//objMingyu->Set_NivelVida(100);
				objMingyu->Set_NroVidas(objMingyu->Get_NroVidas() - 1);
			}
		}

		if (arrCanaval->at(i)->HayColision(objPonky->Get_X(),
			objPonky->Get_Y(), objPonky->Get_Ancho(),
			objPonky->Get_Largo()))
		{
			Puntaje -= 5;
			objPonky->Set_NivelVida(objPonky->Get_NivelVida() - 1);
			arrCanaval->at(i)->Set_Estado(false);
			if (objPonky->Get_NivelVida() <= 0)
			{
				//objPonky->Set_NivelVida(100);
				objPonky->Set_NroVidas(objPonky->Get_NroVidas() - 1);
			}
		}

		if (arrCanaval->at(i)->HayColision(objMely->Get_X(),
			objMely->Get_Y(), objMely->Get_Ancho(),
			objMely->Get_Largo()))
		{
			Puntaje -= 5;
			objMely->Set_NivelVida(objMely->Get_NivelVida() - 1);
			arrCanaval->at(i)->Set_Estado(false);
			if (objMely->Get_NivelVida() <= 0)
			{
				//objMely->Set_NivelVida(100);
				objMely->Set_NroVidas(objMely->Get_NroVidas() - 1);
			}
		}
	}

	return Puntaje;
}