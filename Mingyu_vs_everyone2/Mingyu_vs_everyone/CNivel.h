#pragma once
#include<ctime>
#include<cstdlib>
using namespace std;

class CNivel
{
	int id;
	int Enemigos;
	int Ambiente;
	int Monedas;
	int Trampas;
	int reqEnemigos;
	int reqMonedas;
public:
	CNivel(){
		id = 0;
		Enemigos = 0;
		Ambiente = 0;/*1:Cesped , 2:Arena , 3:Casa , 4:Agua*/
		Monedas =  0;
		Trampas = 0;
		reqEnemigos = 0;
		reqMonedas = 0;
	}

	int getCantEnemigos() { return Enemigos; }
	int getAmbiente() { return Ambiente; }
	int getcantMonedas() { return Monedas; }
	int getcantTrampas() { return Trampas; }
	int getreqEnemigos() { return reqEnemigos; }
	int getID() { return id; }
	void setAmbiente(int e) { Ambiente = e; }
	void setID(int e) { id = e; }
	void setCantEnemigos(int e) { this->Enemigos = e; }
	void setCantMonedas(int e) { this->Monedas = e; }
	void setCantTrampas(int e) { this->Trampas = e; }
	void GenerateData() {
		srand(1981);
		this->Enemigos = rand() % 80 + 1;
		this->Ambiente = rand() % 3 + 1;
		this->Monedas = rand() % 60 + 1;
		this->Trampas = rand() % 25 + 1;
		this->reqEnemigos = rand() % 150 + 1;
		this->reqMonedas = rand() % 150 + 1;
	}

	~CNivel(){}



};







