#pragma once

#include "CMartillo.h"
#include <vector>

using namespace std;

class CVecMartillo
{
private:
	vector<CMartillo *>* arrMartillo;

public:
	CVecMartillo();
	~CVecMartillo();
	void Agregar(int X, int Y, int Ancho, int Largo, int dX, int dY);
	void Dibujar(Graphics^ g, Bitmap ^imgMartillo);
	void Mover(int AnchoF, int LargoF);
	void Eliminar();
	int HayColision(CCanaval *objCanaval);
};

CVecMartillo::CVecMartillo()
{
	arrMartillo = new vector<CMartillo *>();
}

CVecMartillo::~CVecMartillo() {}

void CVecMartillo::Agregar(int X, int Y, int Ancho, int Largo, int dX, int dY)
{
	CMartillo *objMartillo = new CMartillo(X, Y, Ancho, Largo, dX, dY);
	arrMartillo->push_back(objMartillo);
}

void CVecMartillo::Dibujar(Graphics^ g, Bitmap ^imgMartillo)
{
	for (int i = 0; i < arrMartillo->size(); i++)
		arrMartillo->at(i)->Dibujar(g, imgMartillo);

	//	g->DrawString("P: " + arrMartillo->size().ToString(),
	//		gcnew Font("Arial", 10), Brushes::Black,
	//		10, 250);
}

void CVecMartillo::Mover(int AnchoF, int LargoF)
{
	for (int i = 0; i < arrMartillo->size(); i++)
		arrMartillo->at(i)->Mover(AnchoF, LargoF);
}

void CVecMartillo::Eliminar()
{
	vector<CMartillo*>* Aux = new vector<CMartillo *>();

	for (int i = 0; i < arrMartillo->size(); i++)
		if (arrMartillo->at(i)->Get_Estado())
			Aux->push_back(arrMartillo->at(i));

	arrMartillo = Aux;
}

int CVecMartillo::HayColision(CCanaval *objCanaval)
{
	int Puntaje = 0;

	for (int i = 0; i < arrMartillo->size(); i++)
		if (arrMartillo->at(i)->HayColision(objCanaval))
			Puntaje += 20;

	return Puntaje;
}