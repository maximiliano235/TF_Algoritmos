#pragma once

#include "CFuegoMorado.h"
#include "CFuegoNormal.h"
#include "CMartillo.h"
#include <vector>

using namespace std;

class CVecHabilidad
{
private:
	vector<CFuegoMorado *>* arrFuegoMorado;
	vector<CFuegoNormal *>* arrFuegoNormal;
	vector<CMartillo *>* arrMartillo;

public:
	CVecHabilidad();
	~CVecHabilidad();
	void AgregarFuegoMorado(int X, int Y, int Ancho, int Largo, int dX, int dY);
	void AgregarFuegoNormal(int X, int Y, int Ancho, int Largo, int dX, int dY);
	void AgregarMartillo(int X, int Y, int Ancho, int Largo, int dX, int dY);
	void Dibujar(Graphics^ g, Bitmap ^imgFuegoMorado, Bitmap ^imgFuegoNormal, Bitmap^ imgMartillo);
	void Mover(int AnchoF, int LargoF);
	void Eliminar();
	int HayColisionFuegoMorado(CCanaval *objCanaval);
	int HayColisionFuegoNormal(CCanaval *objCanaval);
	int HayColisionMartillo(CCanaval *objCanaval);
};

CVecHabilidad::CVecHabilidad()
{
	arrFuegoMorado = new vector<CFuegoMorado *>();
	arrFuegoNormal = new vector<CFuegoNormal *>();
	arrMartillo = new vector<CMartillo *>();
}

CVecHabilidad::~CVecHabilidad() {}

void CVecHabilidad::AgregarFuegoMorado(int X, int Y, int Ancho, int Largo, int dX, int dY)
{
	CFuegoMorado *objFuegoMorado = new CFuegoMorado(X, Y, Ancho, Largo, dX, dY);
	arrFuegoMorado->push_back(objFuegoMorado);
}

void CVecHabilidad::AgregarFuegoNormal(int X, int Y, int Ancho, int Largo, int dX, int dY)
{
	CFuegoNormal *objFuegoNormal = new CFuegoNormal(X, Y, Ancho, Largo, dX, dY);
	arrFuegoNormal->push_back(objFuegoNormal);
}

void CVecHabilidad::AgregarMartillo(int X, int Y, int Ancho, int Largo, int dX, int dY)
{
	CMartillo *objMartillo = new CMartillo(X, Y, Ancho, Largo, dX, dY);
	arrMartillo->push_back(objMartillo);
}

void CVecHabilidad::Dibujar(Graphics^ g, Bitmap ^imgFuegoMorado, Bitmap^ imgFuegoNormal, Bitmap^ imgMartillo)
{
	for (int i = 0; i < arrFuegoMorado->size(); i++)
		arrFuegoMorado->at(i)->Dibujar(g, imgFuegoMorado);

	for (int i = 0; i < arrFuegoNormal->size(); i++)
		arrFuegoNormal->at(i)->Dibujar(g, imgFuegoNormal);

	for (int i = 0; i < arrMartillo->size(); i++)
		arrMartillo->at(i)->Dibujar(g, imgMartillo);

	//	g->DrawString("P: " + arrFuegoMorado->size().ToString(),
	//		gcnew Font("Arial", 10), Brushes::Black,
	//		10, 250);
}

void CVecHabilidad::Mover(int AnchoF, int LargoF)
{
	for (int i = 0; i < arrFuegoMorado->size(); i++)
		arrFuegoMorado->at(i)->Mover(AnchoF, LargoF);

	for (int i = 0; i < arrFuegoNormal->size(); i++)
		arrFuegoNormal->at(i)->Mover(AnchoF, LargoF);

	for (int i = 0; i < arrMartillo->size(); i++)
		arrMartillo->at(i)->Mover(AnchoF, LargoF);
}

void CVecHabilidad::Eliminar()
{
	vector<CFuegoMorado*>* Aux = new vector<CFuegoMorado *>();
	vector<CFuegoNormal*>* Aux2 = new vector<CFuegoNormal *>();
	vector<CMartillo*>* Aux3 = new vector<CMartillo *>();

	for (int i = 0; i < arrFuegoMorado->size(); i++)
		if (arrFuegoMorado->at(i)->Get_Estado())
			Aux->push_back(arrFuegoMorado->at(i));

	for (int i = 0; i < arrFuegoNormal->size(); i++)
		if (arrFuegoNormal->at(i)->Get_Estado())
			Aux2->push_back(arrFuegoNormal->at(i));

	for (int i = 0; i < arrMartillo->size(); i++)
		if (arrMartillo->at(i)->Get_Estado())
			Aux3->push_back(arrMartillo->at(i));

	arrFuegoMorado = Aux;
	arrFuegoNormal = Aux2;
	arrMartillo = Aux3;
}

int CVecHabilidad::HayColisionFuegoMorado(CCanaval *objCanaval)
{
	int Puntaje = 0;

	for (int i = 0; i < arrFuegoMorado->size(); i++)
		if (arrFuegoMorado->at(i)->HayColision(objCanaval))
			Puntaje += 20;

	return Puntaje;
}

int CVecHabilidad::HayColisionFuegoNormal(CCanaval *objCanaval)
{
	int Puntaje = 0;

	for (int i = 0; i < arrFuegoNormal->size(); i++)
		if (arrFuegoNormal->at(i)->HayColision(objCanaval))
			Puntaje += 20;

	return Puntaje;
}


int CVecHabilidad::HayColisionMartillo(CCanaval *objCanaval)
{
	int Puntaje = 0;

	for (int i = 0; i < arrMartillo->size(); i++)
		if (arrMartillo->at(i)->HayColision(objCanaval))
			Puntaje += 20;

	return Puntaje;
}