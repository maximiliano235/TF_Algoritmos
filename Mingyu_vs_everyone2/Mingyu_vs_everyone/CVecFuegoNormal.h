#pragma once

#include "CFuegoNormal.h"
#include <vector>

using namespace std;

class CVecFuegoNormal
{
private:
	vector<CFuegoNormal *>* arrFuegoNormal;

public:
	CVecFuegoNormal();
	~CVecFuegoNormal();
	void Agregar(int X, int Y, int Ancho, int Largo, int dX, int dY);
	void Dibujar(Graphics^ g, Bitmap ^imgFuegoNormal);
	void Mover(int AnchoF, int LargoF);
	void Eliminar();
	int HayColision(CCanaval *objCanaval);
};

CVecFuegoNormal::CVecFuegoNormal()
{
	arrFuegoNormal = new vector<CFuegoNormal *>();
}

CVecFuegoNormal::~CVecFuegoNormal() {}

void CVecFuegoNormal::Agregar(int X, int Y, int Ancho, int Largo, int dX, int dY)
{
	CFuegoNormal *objFuegoNormal = new CFuegoNormal(X, Y, Ancho, Largo, dX, dY);
	arrFuegoNormal->push_back(objFuegoNormal);
}

void CVecFuegoNormal::Dibujar(Graphics^ g, Bitmap ^imgFuegoNormal)
{
	for (int i = 0; i < arrFuegoNormal->size(); i++)
		arrFuegoNormal->at(i)->Dibujar(g, imgFuegoNormal);

	//	g->DrawString("P: " + arrFuegoNormal->size().ToString(),
	//		gcnew Font("Arial", 10), Brushes::Black,
	//		10, 250);
}

void CVecFuegoNormal::Mover(int AnchoF, int LargoF)
{
	for (int i = 0; i < arrFuegoNormal->size(); i++)
		arrFuegoNormal->at(i)->Mover(AnchoF, LargoF);
}

void CVecFuegoNormal::Eliminar()
{
	vector<CFuegoNormal*>* Aux = new vector<CFuegoNormal *>();

	for (int i = 0; i < arrFuegoNormal->size(); i++)
		if (arrFuegoNormal->at(i)->Get_Estado())
			Aux->push_back(arrFuegoNormal->at(i));

	arrFuegoNormal = Aux;
}

int CVecFuegoNormal::HayColision(CCanaval *objCanaval)
{
	int Puntaje = 0;

	for (int i = 0; i < arrFuegoNormal->size(); i++)
		if (arrFuegoNormal->at(i)->HayColision(objCanaval))
			Puntaje += 20;

	return Puntaje;
}