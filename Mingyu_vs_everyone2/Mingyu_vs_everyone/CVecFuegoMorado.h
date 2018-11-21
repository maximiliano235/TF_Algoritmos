#pragma once

#include "CFuegoMorado.h"
#include <vector>

using namespace std;

class CVecFuegoMorado
{
private:
	vector<CFuegoMorado *>* arrFuegoMorado;

public:
	CVecFuegoMorado();
	~CVecFuegoMorado();
	void Agregar(int X, int Y, int Ancho, int Largo, int dX, int dY);
	void Dibujar(Graphics^ g, Bitmap ^imgFuegoMorado);
	void Mover(int AnchoF, int LargoF);
	void Eliminar();
	int HayColision(CCanaval *objCanaval);
};

CVecFuegoMorado::CVecFuegoMorado()
{
	arrFuegoMorado = new vector<CFuegoMorado *>();
}

CVecFuegoMorado::~CVecFuegoMorado() {}

void CVecFuegoMorado::Agregar(int X, int Y, int Ancho, int Largo, int dX, int dY)
{
	CFuegoMorado *objFuegoMorado = new CFuegoMorado(X, Y, Ancho, Largo, dX, dY);
	arrFuegoMorado->push_back(objFuegoMorado);
}

void CVecFuegoMorado::Dibujar(Graphics^ g, Bitmap ^imgFuegoMorado)
{
	for (int i = 0; i < arrFuegoMorado->size(); i++)
		arrFuegoMorado->at(i)->Dibujar(g, imgFuegoMorado);

	//	g->DrawString("P: " + arrFuegoMorado->size().ToString(),
	//		gcnew Font("Arial", 10), Brushes::Black,
	//		10, 250);
}

void CVecFuegoMorado::Mover(int AnchoF, int LargoF)
{
	for (int i = 0; i < arrFuegoMorado->size(); i++)
		arrFuegoMorado->at(i)->Mover(AnchoF, LargoF);
}

void CVecFuegoMorado::Eliminar()
{
	vector<CFuegoMorado*>* Aux = new vector<CFuegoMorado *>();

	for (int i = 0; i < arrFuegoMorado->size(); i++)
		if (arrFuegoMorado->at(i)->Get_Estado())
			Aux->push_back(arrFuegoMorado->at(i));

	arrFuegoMorado = Aux;
}

int CVecFuegoMorado::HayColision(CCanaval *objCanaval)
{
	int Puntaje = 0;

	for (int i = 0; i < arrFuegoMorado->size(); i++)
		if (arrFuegoMorado->at(i)->HayColision(objCanaval))
			Puntaje += 20;

	return Puntaje;
}