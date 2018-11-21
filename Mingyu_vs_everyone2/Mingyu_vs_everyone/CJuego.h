#pragma once
#include "CMingyu.h"
#include "CMely.h"
#include "CPonky.h"
#include "CVecEnemigo.h"
#include "CMovimiento.h"
#include "CHUD.h"
#include"CVecMonedas.h"
#include "CVecTrampas.h"
#include"CArbolAVL.h"
#include"CNivel.h"
#include "CPortal.h"
class CJuego
{
private:
	CMingyu* objMingyu;
	CPonky* objPonky;
	CMely* objMely;
	CVecMonedas* objVecMonedas;

	CPortal* objPortal;

	//HUD
	CHUD* objHUD;
	CVecTrampas* objVecTrampas;
	CVecEnemigo* objVecEnemigo;
	CNivel* Nivelat;
	int X, Y;
	int Puntaje;
	bool fin;
	int Vidas;
	int NivelVida;

	int NivelVidaM1, NivelVidaM2, NivelVidaM3;

	bool tipo;
	bool perdiste;
	int ambiente;
	bool teletransportar;

	vector<CNivel*>* vecNiveles;
	AVLTree<CNivel*>* TreexEnemigos;
	AVLTree<CNivel*>* TreexMonedas;
	AVLTree<CNivel*>* TreexTrampas;
	AVLTree<CNivel*>* TreexAmbiente;
public:
	CJuego(int X, int Y, int NivelVida, int puntaje);
	~CJuego();

	int get_Puntaje();
	bool get_Teletransportar();
	int getNivelVida();
	bool getPerdiste();

	void Dibujar(Graphics^ g, Bitmap^ imgMingyu, Bitmap^ imgMely, Bitmap^ imgPonky, Bitmap^ imgHP, Bitmap^ imgMedidor, Bitmap^ imgFuegoNormal, Bitmap^ imgFuegoMorado, Bitmap^ imgMartillo, Bitmap^ imgPortal,Bitmap^ imgMoneda,Bitmap^ imgTrampa,Bitmap^Cesped, Bitmap^ imgCanaval);
	void Set_Movimiento(TypeMovimientoMingyu TipoMovimiento, TypeMovimientoPonky TipoMovimiento2, TypeMovimientoMely TipoMovimiento3);
	void Mover_Principal(Keys Tecla);
	void Estatico_Principal(Keys Tecla);
	void GenerarDatosIniciales();
	void Mover_Enemigo(int AnchoF, int LargoF);
	void Set_Nivel(CNivel* n);
	void ActualizarDatos();
	CNivel* getNivelat() { return Nivelat; }
	CNivel* buscarxEnemigos(int n);
	CNivel* buscarxAmbiente(int n);
	CNivel* buscarxMonedas(int n);
	CNivel* buscarxTrampas(int n);
};
void CJuego::Set_Nivel(CNivel* n) { Nivelat = n; }
int CJuego::getNivelVida() { NivelVida = objMingyu->Get_NivelVida(); return NivelVida; }
int CJuego::get_Puntaje() { return Puntaje + objMingyu->getPuntaje(); }
bool CJuego::getPerdiste() { return perdiste; }


CJuego::CJuego(int X, int Y, int NivelVida, int puntaje)
{
	this->NivelVidaM1 = 10;
	this->NivelVidaM2 = 10;
	this->NivelVidaM3 = 10;
	this->perdiste = false;

	objMingyu = new CMingyu(X, Y, NivelVida, puntaje);
	objPonky = new CPonky(X-40, Y, NivelVida);
	objMely = new CMely(X+40, Y, NivelVida);
	objVecEnemigo = new CVecEnemigo();
	objVecMonedas = new CVecMonedas();
	objVecTrampas = new CVecTrampas();
	objPortal = new CPortal(-5000, -50000);
	
	teletransportar = false;

	Puntaje = 0;
	tipo = 0;
	ambiente = 0;
	Nivelat = new CNivel();
	auto compxEnemigos = [](CNivel* n1, CNivel* n2) { if (n1->getCantEnemigos() > n2->getCantEnemigos()) return 1; else if (n1->getCantEnemigos() == n2->getCantEnemigos())return 0; else { return -1; } };
	auto compxMonedas = [](CNivel* n1, CNivel* n2) { if (n1->getcantMonedas() > n2->getcantMonedas()) return 1; else if (n1->getcantMonedas() == n2->getcantMonedas())return 0; else { return -1; } };
	auto compxTrampas = [](CNivel* n1, CNivel* n2) { if (n1->getcantTrampas() > n2->getcantTrampas()) return 1; else if (n1->getcantTrampas() == n2->getcantTrampas())return 0; else { return -1; } };
	auto compxAmbiente = [](CNivel* n1, CNivel* n2) { if (n1->getAmbiente() > n2->getAmbiente()) return 1; else if (n1->getAmbiente() == n2->getAmbiente())return 0; else { return -1; } };
	TreexEnemigos = new AVLTree<CNivel*>(compxEnemigos);
	TreexMonedas = new AVLTree<CNivel*>(compxMonedas);
	TreexTrampas = new AVLTree<CNivel*>(compxTrampas);
	TreexAmbiente = new AVLTree<CNivel*>(compxAmbiente);

}
bool CJuego::get_Teletransportar() { return teletransportar; }
CJuego::~CJuego() {}

CNivel* CJuego::buscarxEnemigos(int n) {
	CNivel* niv = new CNivel();
	niv->setCantEnemigos(n);
	return TreexEnemigos->search(niv)->e;
}
CNivel* CJuego::buscarxMonedas(int n) {
	CNivel* niv = new CNivel();
	niv->setCantMonedas(n);
	return TreexMonedas->search(niv)->e;
}
CNivel* CJuego::buscarxTrampas(int n) {

	CNivel* niv = new CNivel();
	niv->setAmbiente(n);
	return TreexTrampas->search(niv)->e;
}
CNivel* CJuego::buscarxAmbiente(int n) {
	CNivel* niv = new CNivel();
	niv->setAmbiente(n);
	return TreexAmbiente->search(niv)->e;
}
void CJuego::Dibujar(Graphics^ g, Bitmap^ imgMingyu, Bitmap^ imgMely, Bitmap^ imgPonky, Bitmap^ imgHP, Bitmap^ imgMedidor, Bitmap^ imgFuegoNormal, Bitmap^ imgFuegoMorado, Bitmap^ imgMartillo, Bitmap^ imgPortal,Bitmap^ imgMoneda,Bitmap^ imgTrampa,Bitmap^ imgCesped, Bitmap^ imgCanaval)
{
	objHUD = new CHUD(0, 0, objMingyu->Get_NivelVida()*25.6, objPonky->Get_NivelVida()*25.6, objMely->Get_NivelVida()*25.6);
	if (objMingyu->Get_NivelVida() <= 0 || objPonky->Get_NivelVida() <= 0 || objMely->Get_NivelVida() <= 0)
	{
		perdiste = true;
	}
	objPortal->Dibujar(g, imgPortal);
	objVecEnemigo->Dibujar(g, imgCanaval);
	objPonky->Dibujar(g, imgPonky, imgFuegoMorado);
	objMingyu->Dibujar(g, imgMingyu, imgMartillo);
	objMely->Dibujar(g, imgMely, imgFuegoNormal);
	objVecMonedas->Dibujar(g,imgMoneda);
	objVecTrampas->Dibujar(g, imgTrampa);
	objHUD->Dibujar(g, imgHP, imgMedidor);
	NivelVida = objMingyu->Get_NivelVida();

	if (objMingyu->Get_X() >= objPortal->Get_X() &&
		objPonky->Get_X() >= objPortal->Get_X() &&
		objMely->Get_X() >= objPortal->Get_X() &&

		objMingyu->Get_X() + objMingyu->Get_Ancho() <= objPortal->Get_X() + 300 &&
		objPonky->Get_X() + objPonky->Get_Ancho() <= objPortal->Get_X() + 300 &&
		objMely->Get_X() + objMely->Get_Ancho() <= objPortal->Get_X() + 300 &&

		objMingyu->Get_Y() >= objPortal->Get_Y() &&
		objPonky->Get_Y() >= objPortal->Get_Y() &&
		objMely->Get_Y() >= objPortal->Get_Y()  &&

		objMingyu->Get_Y() + objMingyu->Get_Largo() <= objPortal->Get_Y() + 300 &&
		objPonky->Get_Y() + objPonky->Get_Largo() <= objPortal->Get_Y() + 300 &&
		objMely->Get_Y() + objMely->Get_Largo() <= objPortal->Get_Y() + 300)
	{
		teletransportar = true;
	}
	else
	{
		teletransportar = false;
	}
	g->DrawString("Puntaje: " + Puntaje.ToString(),
		gcnew Font("Arial", 12), Brushes::Red, 0, 10);
	/*
	if (objHUD->Get_AnchoM1 <= 0 || objHUD->Get_AnchoM2 <= 0 || objHUD->Get_AnchoM3 <= 0)
	{
		perdiste = true;
	}
	*/
	
}

void CJuego::Set_Movimiento(TypeMovimientoMingyu TipoMovimiento, TypeMovimientoPonky TipoMovimiento2, TypeMovimientoMely TipoMovimiento3)
{
	objPonky->Set_Movimiento(TipoMovimiento2);
	objMingyu->Set_Movimiento(TipoMovimiento);
	objMely->Set_Movimiento(TipoMovimiento3);
}

void CJuego::Mover_Enemigo(int AnchoF, int LargoF)
{
	//objVecEnemigo->Agregar(1000, 700, -1);
	objVecEnemigo->Mover(AnchoF, LargoF);
	objVecMonedas->Mover(AnchoF, LargoF);
	objVecTrampas->Mover(AnchoF, LargoF);
	objMingyu->Mover_Martillo(AnchoF, LargoF);
	Puntaje += objVecEnemigo->HayColision(objMingyu->Get_VecMartillo(), objPonky->Get_VecFuegoMorado(), objMely->Get_VecFuegoNormal());
	Puntaje += objVecEnemigo->HayColision(objMingyu, objPonky, objMely);
	Puntaje += objVecMonedas->HayColision(objMingyu, objPonky, objMely);
	Puntaje += objVecTrampas->HayColision(objMingyu, objPonky, objMely);
	objVecEnemigo->Eliminar(); Nivelat->setCantEnemigos(objVecEnemigo->getSize());
	objVecMonedas->Eliminar(); Nivelat->setCantMonedas(objVecMonedas->GetSize());
	objVecTrampas->Eliminar(); Nivelat->setCantTrampas(objVecTrampas->GetSize());
}

void CJuego::Mover_Principal(Keys Tecla)
{
	switch (Tecla)
	{
	case Keys::R:
		objPortal = new CPortal(objPonky->Get_X() - 130, objPonky->Get_Y() - 100);
		break;
	default:
		objMingyu->Mover(Tecla);
		objPonky->Mover(Tecla);
		objMely->Mover(Tecla);
		break;
	}
}
void CJuego::Estatico_Principal(Keys Tecla)
{
	objMingyu->Estatico(Tecla);
	objPonky->Estatico(Tecla);
	objMely->Estatico(Tecla);
}

void CJuego::GenerarDatosIniciales() {
	this->Nivelat->GenerateData();
	/*Agregar Enemigos*/
	
	for (int i = 0; i < Nivelat->getCantEnemigos(); i++)
	{
		objVecEnemigo->Agregar(rand()%1250+1,rand() % 1250+300,1);
	}
	/*Agregar Monedas*/
	for (int i = 0; i < this->Nivelat->getcantMonedas(); i++)
	{
		objVecMonedas->Agregar(rand() % 1250 + 1, rand() % 1250 + 300, 1);
	}
	/*Agregar Trampas*/
	for (int i = 0; i <this->Nivelat->getcantTrampas(); i++)
	{
		objVecTrampas->Agregar(rand() % 1250 + 1, rand() % 1250 + 300, 1);
	}
    /*Set Ambiente*/
	ambiente = Nivelat->getAmbiente();

	/*Generar los Arboles*/

	for (int i = 0; i < 999999; i++)
	{
		CNivel* niv = new CNivel();
		niv->setID(i);
		TreexEnemigos->add(niv);
		TreexAmbiente->add(niv);
		TreexMonedas->add(niv);
		TreexTrampas->add(niv);
	}

}

void CJuego::ActualizarDatos() {
/*Actualizar si se mataron enemigos o agarraron monedas y tambien al cambiar de nivel guardar el CNivel en el vec de niveles y obtener el Cnivel del arbol para que ese sea
  el NivelAt */




}

