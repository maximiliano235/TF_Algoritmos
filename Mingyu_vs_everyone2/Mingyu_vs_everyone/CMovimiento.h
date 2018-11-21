#pragma once
class CMovimiento
{
private:
	int X, Y;
	int Ancho, Largo;
	int dX, dY;
	int Mapa;

public:
	CMovimiento();
	CMovimiento(int X, int Y, int Ancho, int Largo, int dX, int dY);
	~CMovimiento();
	int Get_X();
	void Set_X(int X);
	int Get_Y();
	void Set_Y(int Y);
	int Get_Ancho();
	void Set_Ancho(int Ancho);
	int Get_Largo();
	void Set_Largo(int Largo);
	int Get_dX();
	void Set_dX(int dX);
	int Get_dY();
	void Set_dY(int dY);
};

CMovimiento::CMovimiento()
{
}

CMovimiento::CMovimiento(int X, int Y, int Ancho, int Largo, int dX, int dY)
{
	this->X = X;
	this->Y = Y;
	this->Ancho = Ancho;
	this->Largo = Largo;
	this->dX = dX;
	this->dY = dY;
}

CMovimiento::~CMovimiento() {}

int CMovimiento::Get_X()
{
	return this->X;
}

void CMovimiento::Set_X(int X)
{
	this->X = X;
}

int CMovimiento::Get_Y()
{
	return this->Y;
}

void CMovimiento::Set_Y(int Y)
{
	this->Y = Y;
}

int CMovimiento::Get_Ancho()
{
	return this->Ancho;
}

void CMovimiento::Set_Ancho(int Ancho)
{
	this->Ancho = Ancho;
}

int CMovimiento::Get_Largo()
{
	return this->Largo;
}

void CMovimiento::Set_Largo(int Largo)
{
	this->Largo = Largo;
}

int CMovimiento::Get_dX()
{
	return this->dX;
}

void CMovimiento::Set_dX(int dX)
{
	this->dX = dX;
}

int CMovimiento::Get_dY()
{
	return this->dY;
}

void CMovimiento::Set_dY(int dY)
{
	this->dY = dY;
}